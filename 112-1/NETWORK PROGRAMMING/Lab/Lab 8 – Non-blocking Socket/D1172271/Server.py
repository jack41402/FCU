# Coded by Eric Chen, D1172271
# ISTM Purdue
#
# @Copyright /  All right reserved
# TCP Consumer / Producer Server

import time
import queue
import logging
import threading
from Library.Core import TCP_Networking, Utils

BACKLOG = 5
INTERFACE = "0.0.0.0"
PRODUCER_PORT = 8880
CONSUMER_PORT = 8881
LOGGER = None


class ProducerServer(TCP_Networking.ConcurrentServer):
	def __init__(self, interface, port, backlog, shared_queue):
		super().__init__(interface, port, backlog)
		self.logger = logging.getLogger(__name__)
		self.queue = shared_queue


	# producer transmission loop overriding
	def transmission_loop(self, conn):
		connection = True

		while connection:
			# no matter what, receive first
			datatype, data = self.receive(conn)
			self.logger.info(f"Recevied: {data} / Datatype: {datatype}")

			# handle string data
			if datatype == Utils.EncodeType.STR:
				connection = self.process_string_data(conn, data)

			# handle int data
			elif datatype == Utils.EncodeType.INT:
				connection = self.process_integer_data(conn, data)

			# debug, sump all queue content
			self.logger.debug("Queue Content Count: {}".format(self.queue.qsize()))

		return


	def process_string_data(self, conn, data):
		status = None

		if data == "[PENDING]": # producer client still waiting for queue
			if self.queue.qsize() >= 5:
				# queue not ready, send command "[KEEP-ALIVE]"
				self.send(conn, "[KEEP-ALIVE]", datatype=Utils.EncodeType.STR)
				self.logger.debug("[PRODUCER] Queue not ready, connection keep-alive.")
				status = True

			else:
				# queue ready, send command "[READY]"
				self.send(conn, "[READY]", datatype=Utils.EncodeType.STR)
				self.logger.debug("[PRODUCER] Queue ready, now notifying client")
				return True

		elif data == "[END-OF-TRANSMISSION]": # producer client demanding to terminate
			self.logger.warning("[PRODUCER] Received an End-Of-Transmission command, terminating client.")
			return False

		else:
			self.logger.warning("[PRODUCER] String data in unknown convention, ignoring......")
			status = True

		return status


	def process_integer_data(self, conn, data):
		status = None

		if self.queue.qsize() <= 5:
			self.queue.put(data)
			self.send(conn, "[ACK]", datatype=Utils.EncodeType.STR)
			self.logger.debug(f"[PRODUCER] Enqueueing data {data} into the server's queue")
			status = True

		else:
			self.send(conn, "[NOT-READY]", datatype=Utils.EncodeType.STR)
			self.logger.warning("[PRODUCER] Max item in queue met, rejecting the enqueue request.")
			status = True

		return status



class ConsumerServer(TCP_Networking.ConcurrentServer):
	def __init__(self, interface, port, backlog, shared_queue):
		super().__init__(interface, port, backlog)
		self.queue = shared_queue
		self.block_count = 0

	# consumer transmission loop overriding
	def transmission_loop(self, conn):
		connection = True

		while connection:
			# no matter what, receive first
			datatype, data = self.receive(conn)
			self.logger.info(f"Recevied: {data} / Datatype: {datatype}")

			# handle string data
			if datatype == Utils.EncodeType.STR:
				connection = self.process_string_data(conn, data)

			# handle int data
			elif datatype == Utils.EncodeType.INT:
				connection = self.process_integer_data(conn, data)

			# debug, sump all queue content
			self.logger.debug("Queue Content Count: {}".format(self.queue.qsize()))

		return


	def process_string_data(self, conn, data):
		status = None

		if data == "[GET-REQUEST]": # cosumer client request for data
			# check if ha+ve data in queue
			if not self.queue.empty():
				# if got data, send to consumer client
				data = self.queue.get()
				self.logger.debug(f"[CONSUMER] Dequeueing data {data} from the server's queue")
				self.send(conn, data, datatype=Utils.EncodeType.INT)
				status = True

			else:
				# if not, reply [NOT-READY], enter pending state
				self.logger.warning("[CONSUMER] Queue not ready, signaling client to enter pending state")
				self.send(conn, "[NOT-READY]", datatype=Utils.EncodeType.STR)
				status = True

		if data == "[PENDING]":
			if not self.queue.empty():
				# if queue avalible send [READY], client exit pending state
				self.logger.debug("[CONSUMER] Queue ready, singaling client to exit pending state")
				self.send(conn, "[READY]", datatype=Utils.EncodeType.STR)
				status = True

			else:
				# if queue isn't avalible yet, send [KEEP-ALIVE]
				self.logger.debug("[CONSUMER] Queue not ready, connection keep alive")
				self.send(conn, "[KEEP-ALIVE]", datatype=Utils.EncodeType.STR)
				status = True

			pass

		elif data == "[END-OF-TRANSMISSION]":
			status = False

		else:
			self.logger.warning("[CONSUMER] String data in unknown convention, ignoring......")
			status = True

		return status


	def process_integer_data(self, conn, data):
		status = None

		return status



def main():
	global LOGGER

	# setup the logger before run
	logging.basicConfig(level=logging.DEBUG, format='[%(levelname)s] - %(message)s(%(name)s:%(lineno)d)')
	LOGGER = logging.getLogger(__name__)
	LOGGER.debug("Logger Initialization Complete.")

	# create a commonly shared queue for the server to handle on
	data_queue = queue.Queue()

	# create server instance
	producer_server = ProducerServer(INTERFACE, PRODUCER_PORT, BACKLOG, data_queue)
	consumer_server = ConsumerServer(INTERFACE, CONSUMER_PORT, BACKLOG, data_queue) 

	# start the service of both servers
	LOGGER.info(f"Starting producer service on port \'{PRODUCER_PORT}\' !")
	LOGGER.info(f"Starting consumer service on port \'{CONSUMER_PORT}\' !")
	producer_server.start_service()
	consumer_server.start_service()

	# main thread sleep
	time.sleep(300)

	# cleanup, shutdown all server
	LOGGER.warning("Server max time delay reached !! Shutting down all services !!")
	producer_server.stop_service()
	consumer_server.stop_service()
	LOGGER.info("All services terminated gracefully !!")
	return



if __name__ == "__main__":
	main()