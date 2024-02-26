# Coded by Eric Chen, D1172271
# ISTM Purdue
#
# @Copyright /  All right reserved
# DESC: Custom sliding window protocol based on UDP

import socket
import random
import logging
import threading
from queue import Queue
from . import UDP_Networking, Utils

# global variable
LOGGER = logging.getLogger(__name__)
BUFFER_SIZE = 2048


# DESC: An implementation of one to ono sliding window porotcal in Go-Back-N(GBN) convention
# Maybe implement timeout in the connect and receive in future
class SimpleGBNSliding:
	def __init__(self, window_value, buffer_size=BUFFER_SIZE):
		# normal class attributes
		self.socket = None
		self.fallback = Queue(maxsize=window_value) # Fallback queue for storing data if package dropped
		self.condition = threading.Condition()
		self.lock = threading.Lock()
		self.buffer_size = buffer_size
		self.destination_info = None # for tracking the (ip, port) of transmission dst
		self.window = window_value

		# attributes of critical section variables
		self.cs_busy = False
		self.cs_buffer = [] # a buffer dedicated for holding received data
		self.cs_send_seq = 0 # next seq number to send (frame tracking)
		self.cs_receive_ack = [] # seq of the of the last successfully received and ack packet


	# For server instance, use for waiting incomming connection, muist call bind() before use
	def accept(self, interface, port, timeout):
		LOGGER.debug("Now initializing SimpleGBNSliding's server socket......")
		self.socket = UDP_Networking.SimpleServer(interface, port, buffer_size=self.buffer_size)

		while True:
			# try to recveive the SYN from client
			address, first_handshake = self.socket.receive(timeout, autoparse=False)
			if not (first_handshake):
				LOGGER.critical("Receive failed for the first handshake on establishing connection !")
				continue

			# parse the first handshake
			packet = Utils.ProtocolX()
			packet.parse(first_handshake)

			# check if the first handshake is valid 
			if not (packet.SYN):
				LOGGER.critical("Unexpected flag type for first handshake on establishing connection !")
				continue

			# send the SYN-ACK to client
			LOGGER.debug(f"Received the first handshake with sequence number {packet.seq}")
			LOGGER.debug(f"Sending the second handshake with ack number {packet.seq + 1} back")
			random_sequence = random.randint(1, 1000)
			second_handshake = Utils.ProtocolX(SYN=True, ACK=True, seq=random_sequence, ack=packet.seq + 1)
			self.socket.send(address, second_handshake.packup())

			# receive the ACK from client
			address, third_handshake = self.socket.receive(timeout, autoparse=False)
			if not (third_handshake):
				LOGGER.critical("Receive failed for the third handshake on establishing connection !")
				continue

			# parse the third handshake
			packet = Utils.ProtocolX()
			packet.parse(third_handshake)

			# check if the third handshake is valid
			LOGGER.debug(f"Received the third handshake with ack number {packet.ack}")
			if not (packet.ACK and packet.ack == random_sequence + 1):
				LOGGER.critical("Got an unexpected ack number !! Reject Connection !!")
				continue

			else:
				LOGGER.info("Established connection with client {}".format(address))
				self.destination_info = address
				break # connection established, exit loop

		# start receive daemon
		#daemon = ReceiveDaemon(self.window, self)
		#daemon.start()
		return address


	# For client instance use to establish connection with server instance
	def connect(self, server_ip, server_port, timeout):
		LOGGER.info("Now initializing SimpleGBNSliding's client socket......")
		self.socket = UDP_Networking.SimpleClient(server_ip, server_port, buffer_size=self.buffer_size)

		# send the random SYN to server
		random_sequence = random.randint(1, 1000)
		first_handshake = Utils.ProtocolX(SYN=True, seq=random_sequence)
		self.socket.send(first_handshake.packup())
		LOGGER.debug("Send first handshake with sequence number {}.".format(random_sequence))

		# receive an SYN / ACK
		remote_address, second_handshake = self.socket.receive(timeout, autoparse=False)
		if not (second_handshake): # check receive status
			LOGGER.critical("Received failed for the second handshake on establishing connection !")
			return False
			
		# parse the received SYN / ACK
		packet = Utils.ProtocolX()
		packet.parse(second_handshake)
		LOGGER.debug(f"Received second handshake with sequence number {packet.seq}, ack number {packet.ack}.")
		if not (packet.SYN and packet.ACK and packet.ack == random_sequence + 1):
			LOGGER.critical("Got an unexpected ack number !! Reject Connection !!")
			return

		# send an ACK to server
		LOGGER.debug("Sending third handshake with ack number {} back.".format(packet.seq + 1))
		third_handshake = Utils.ProtocolX(ACK=True, ack=packet.seq + 1)
		self.socket.send(third_handshake.packup())

		# connected
		LOGGER.info(f"Established connection with {remote_address} !!")
		self.destination_info = remote_address

		# start receive daemon
		#daemon = ReceiveDaemon(self.window, self)
		#daemon.start()
		return


	# General send for client / server
	def send(self, datatype, data):
		success = False

		while not (success):
			# get the next seq number to send in the critical section
			with self.lock:
				sequence = self.cs_send_seq
			
			# creaft packet
			packet = Utils.ProtocolX(ACK=True, PSH=True, seq=self.sequence)
			packet.embed_payload(datatype, data)

			# send it out
			self.socket.send(packet.packup())

			# wait for ack, if ack then break out loop, else resend
			with self.lock:
				if sequence in self.cs_receive_ack:
					break

		# counter increase
		with self.lock:
			self.cs_send_seq = 0


	# General receive for client / server
	def receive(self, autoparse=True):
		with self.condition:
			self.condition.wait()

			# push the received buffer up
			with self.lock:
				data = self.cs_buffer
				self.cs_buffer.clear() # buffer reset
				self.cs_send_seq = 0 # reset the sequence number

		return data


# DESC: A class that is dedicated for helping our custom protocol handling the process of seq, ack, and normal data parsing
class ReceiveDaemon(threading.Thread):
	def __init__(self, window_value, SimpleGBNSliding_instance):
		super.__init__(name="SlidingWindow GBN Receive Daemon")
		self.window = window_value
		self.data = SimpleGBNSliding_instance
		self.socket = SimpleGBNSliding_instance.socket
		self.destination_info = SimpleGBNSliding_instance.destination_info


	def run(self):
		while True:
			address, raw_packet = self.socket.receive(10, autoparse=False)
			if not raw_packet:
				continue

			# parse packet
			packet = Utils.ProtocolX()
			packet.parse(raw_packet)

			# if it is a pure acknoledge flag packet
			if (packet.ACK and packet.ack and not packed.is_embed):
				with self.data.lock:
					self.data.cs_receive_ack.append(packet.ack)

					# check if reached windows end, need to notify to get buffer or resend
					if len(self.data.cs_receive_ack) == self.window:
						self.data.condition.notify() # push to upper layer

			# if it is an manual force EOF sinal indicating that the frame has ended
			if (packet.PSH and packet.URG and not packet.is_embed):
				# check if reached windows end, need to notify to get buffer or resend
				with self.data.lock:
					if len(self.data.cs_receive_ack) == len(self.data.cs_buffer):
						self.data.condition.notify()

			# if it is a normal data transmission paoket
			if (packet.PSH and packet.ACK and packet.is_embed):
				with self.data.lock:
					# normal data receive, append data in buffer with size of window size
					self.data.cs_buffer.append((packet.datatype, packet.payload))

				# send back the ack message to the sender
				ack_message = Utils.ProtocolX(ACK=True, ack=packet.seq)
				self.packet.send(ack_message.packup())


	def find_dropped_packets(lst, x):
		return [num for num in range(1, x + 1) if num not in lst]


if __name__ == "__main__":
	logging.basicConfig(level=logging.DEBUG)