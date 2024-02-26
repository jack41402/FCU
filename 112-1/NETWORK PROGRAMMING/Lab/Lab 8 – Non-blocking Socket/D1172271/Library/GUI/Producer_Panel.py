# Coded by Eric Chen, D1172271
# ISTM Purdue
#
# @Copyright /  All right reserved
# The Secure TCP client GUI panel implementation

import sys
import time
import random
from PyQt6.uic import loadUi
from PyQt6.QtCore import QSize, pyqtSignal, QObject, QThread
from PyQt6.QtWidgets import (
	QWidget, 
	QMessageBox, 
	QSpacerItem, 
	QSizePolicy,
)
from ..Core import TCP_Networking, Utils

# global var declaration
RECEIVE_TIMEOUT_SECONDS = 5
MAX_TIMEOUT_RETRY = 3


# The main widget of the GUI Client
class ClientPanel(QWidget): 
	def __init__(self):
		super().__init__()
		loadUi("UI/producer.ui", self)

		# setting some important variable
		self.client = None
		self.server_ip = None
		self.server_port = None
		self.countdown = None
		self.setFixedSize(QSize(640, 480))

		# connecting signal to component
		self.StartClient_Button.clicked.connect(self.lockdown)
		self.Abort_Button.clicked.connect(self.abort_process)


	# start connection to server
	def init_socket(self):
		server_ack = False

		try:
			# try to create udp soscket for client		
			self.client = TCP_Networking.SimpleClient(self.server_ip, self.server_port)
			self.Text_Browser.setText("[INFO] UDP Client socket successfully initialized.....")
			self.Text_Browser.append("[INFO] Client successfully connected to host {}".format(self.server_ip))

			# try send to init number to the server to start the countdown
			self.update_browser(f"[INFO] Sending \'{self.countdown}\' to server")
			self.client.send(self.countdown, datatype=Utils.EncodeType.INT)

			# start the transmission loop
			self.start_transmission()

		except OSError as ex:
			self.pop_messagebox("[ERROR]", "Socket error on initializing client UDP socket", str(ex))
			sys.exit(-1)

		except Exception as ex:
			self.pop_messagebox("[ERROR]", "Unexpected error on initializing client UDP socket", str(ex))
			sys.exit(-1)

		return


	# starting the transmission loop
	def start_transmission(self):
		# star the transmission loop in another thread seperately
		self.thread_worker = TransmissionHdlr(self.client, self.countdown)
		self.thread_worker.update_signal.connect(self.update_browser) # browser render callback
		self.thread_worker.start()
		return


	# the callback for the Received_Countdown class
	def update_browser(self, data):
		self.Text_Browser.append(data)
		return


	# perform lockdown on lineedit connecting to server
	def lockdown(self):
		self.server_ip = self.ServerIP_Input.text()
		self.server_port = self.ServerPort_Input.text()
		self.countdown = self.CountdownNum_Input.text()
		print("[TRACE] Receive Input:", self.server_ip)
		print("[TRACE] Receive Input:", self.server_port)
		print("[TRACE] Receive Input:", self.countdown)


		# check the validity of the server connection detail
		if not (Utils.Validity.ip(self.server_ip) and Utils.Validity.port(self.server_port)):
			print("\n[CRITICAL] User input invalid value on the server connection details.")
			self.pop_messagebox("[ERRROR]", "Server IP or Port not valid", "Aborting......")
			sys.exit(-1)

		else:
			print("[TRACE] The user input server connection details are valid")
			self.server_port = int(self.server_port)

		# check the validity of the countdown number
		if not (self.countdown.isdigit()):
			print("\n[CRITICAL] User input invalid value on the countdown number")
			self.pop_messagebox("[ERRROR]", "Countdown number must be integer", "Aborting......")
			sys.exit(-1)

		else:
			self.countdown = int(self.countdown)
			print("[TRACE] The user input countdown value is valid")

		# disable the linedit and start client button
		self.ServerIP_Input.setText(self.server_ip + "	(LOCKED)")
		self.ServerPort_Input.setText(str(self.server_port) + "	(LOCKED)")
		self.CountdownNum_Input.setText(str(self.countdown) + "	(LOCKED)")
		self.StartClient_Button.setText(self.StartClient_Button.text() + "	\n(LOCKED)")
		self.ServerIP_Input.setEnabled(False)
		self.ServerPort_Input.setEnabled(False)
		self.CountdownNum_Input.setEnabled(False)
		self.StartClient_Button.setEnabled(False)

		# start the udp client socket creation process
		self.init_socket()
		return


	# aborting application abruptly
	def abort_process(self):
		self.pop_messagebox("ALERT", "Program now aborting !!", "")
		sys.exit(-1)
		return


    # Alert messgae box
	def pop_messagebox(self, banner, title, text):
		msg_box = QMessageBox(self)
		msg_box.setWindowTitle(banner)
		msg_box.setText(title)
		msg_box.setInformativeText(text)
		msg_box.setIcon(QMessageBox.Icon.Information)  # Set an icon
		msg_box.setStandardButtons(QMessageBox.StandardButton.Ok)

        # Adjusting the size using QSpacerItem
		spacer = QSpacerItem(200, 0, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)
		layout = msg_box.layout()
		layout.addItem(spacer, layout.rowCount(), 0, 1, layout.columnCount())
		msg_box.exec()
		return



# a special class meant to deal with transmission via multi-threading 
class TransmissionHdlr(QThread):
	update_signal = pyqtSignal(str)
	ACK_SIGNAL = "[ACK]"
	READY_SIGNAL = "[READY]"
	NOTREADY_SIGNAL = "[NOT-READY]"
	KEEPALIVE_SIGNAL = "[KEEP-ALIVE]"
	TERMINATION_SIGNAL = "[END-OF-TRANSMISSION]"

	def __init__(self, hdlr, countdown, timeout=RECEIVE_TIMEOUT_SECONDS, max_retry=MAX_TIMEOUT_RETRY):
		super().__init__()
		self.client = hdlr
		self.buffer = None # raw packet buffer, 
		self.running = True
		self.initvalue = countdown;
		self.countdown = countdown # number countdown
		self.timeout_count = 0
		self.recv_timeout = timeout
		self.max_retry = max_retry


	# thread routine
	def run(self):
		# show some configuration for this transmission loop
		self.update_signal.emit("[INFO] Timeout of client receive function set to: {} seconds.".format(self.recv_timeout))
		self.update_signal.emit("[INFO] Disabled the process termination setting based on the max retry(timeout) counts !\n")

		while (self.running):
			time.sleep(random.randint(1, 5))
			# receive first to know what to send
			if not (self._receive_data()):
				self._handle_receive_timeout()
				continue

			# data smart handling
			self._process_data()

		# end of transmission
		self.update_signal.emit("[INFO] End of TCP countdown transmission with server !")
		self.update_signal.emit("[INFO] Total packet loss: {} packets\n".format(self.timeout_count))
		self.client.close()
		return


	# try receive data from server
	def _receive_data(self):
		self.buffer = self.client.receive()
		print(self.buffer)

		# check if we got response
		if not (self.buffer):
			return False

		# parse the data
		print(f"[DEBUG] Receive: {self.buffer[1]} / Datatype: {self.buffer[0]}")
		self.update_signal.emit(f"[INFO] Received: {self.buffer[1]} / Datatype: {self.buffer[0]}")
		return True


	# designed for UDP transmission only, please ignore it in TCP
	def _handle_receive_timeout(self):
		self.update_signal.emit("[WARNING] Client data receive timeout !! Possible UDP packet loss !!")
		self.timeout_count += 1

		# possible udp packet loss, resending the previous packet
		self.update_signal.emit("[WARNING] Resending {} as countdown number to server......".format(self.initvalue))
		self.update_signal.emit("[WARNING] Attempting to restart the whole coundown process !!\n")
		self.client.send(self.initvalue, datatype=Utils.EncodeType.INT)
		return


	# classify the handling of data based on the recevied datatype
	def _process_data(self):
		datatype, data = self.buffer

		# based on the received datatype, we will decide how to process it
		if (datatype == Utils.EncodeType.INT):
			if not self._process_integer_data(data):
				self.running = False

		elif (datatype == Utils.EncodeType.STR):
			if not self._process_string_data(data):
				self.running = False

		else:
			self.update_signal.emit("[ERROR] Received a packet in unknown format\n")

		return


	# for handling the integer data, but we shouldn't be touching it in this project
	def _process_integer_data(self, data):
		if (data > 0):
			# sending the data - 1 back
			self.update_signal.emit("[INFO] Sending value {} back to server\n".format(data - 1))
			if not (self.client.send(data - 1, datatype=Utils.EncodeType.INT)):
				print("[WARNING] Can't send data to client !! Aborting......\n")
				return False
			return True

		elif (data == 0):
			# sending a connection terminate signal to server
			self.update_signal.emit("[INFO] Sending ther terminate command \'[TERMINATE]\' to server !\n")
			if not (self.client.send(self.TERMINATION_SIGNAL, datatype=Utils.EncodeType.STR)):
				print("[WARNING] Can't send data to client !! Aborting......\n")
				return False
			return False


	# for handling the string data
	def _process_string_data(self, data):
		connection_status = False

		if (data == self.ACK_SIGNAL): # server acknoledge our request
			# server confirm the enqueue, decrease countdown number
			self.countdown -= 1

			# send value to server, check if reached zero
			if self.countdown >= 0:
				self.update_signal.emit(f"[INFO] Sending \'{self.countdown}\' to server......")
				self.client.send(self.countdown, datatype=Utils.EncodeType.INT)
				connection_status = True

			else: # end of transmission, terminate connection
				connection_status = False

		elif (data == self.NOTREADY_SIGNAL): # server not ready to handle our request, enter pending state
			print("[WARNING] Server not ready, enter pending state !")
			self.update_signal.emit("[INFO] Sending \'[PENDING]\' to server......")
			self.client.send("[PENDING]", datatype=Utils.EncodeType.STR)
			connection_status = True

		elif (data == self.READY_SIGNAL): # server ready to handle our signal, exit pending state, resend last value
			print("[WARNING] Server ready, exiting pending state !")
			self.update_signal.emit(f"[INFO] Sending \'{self.countdown}\' to server......")
			self.client.send(self.countdown, datatype=Utils.EncodeType.INT)
			connection_status = True

		elif (data == self.KEEPALIVE_SIGNAL): # server tell us to keep alive the conenction, coninue pending state
			print("[WARNING] Server not ready, continue pending state !")
			self.update_signal.emit("[INFO] Sending \'[PENDING]\' to server......")
			self.client.send("[PENDING]", datatype=Utils.EncodeType.STR)
			connection_status = True

		elif (data == self.TERMINATION_SIGNAL): # server tell us to kill the conenction
			connection_status = False

		else:
			self.update_signal.emit(f"[WARNING] Unknown string command \'{data}\', ignoring......\n")
			connection_status = True

		return connection_status