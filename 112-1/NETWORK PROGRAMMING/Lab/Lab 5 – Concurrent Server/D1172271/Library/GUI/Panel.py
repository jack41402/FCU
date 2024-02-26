# Coded by Eric Chen, D1172271
# ISTM Purdue
#
# @Copyright /  All right reserved
#
# The client GUI panel implementation

import sys
from PyQt6.uic import loadUi
from PyQt6.QtCore import QSize, pyqtSignal, QObject, QThread
from PyQt6.QtWidgets import (
	QWidget, 
	QMessageBox, 
	QSpacerItem, 
	QSizePolicy,
)
from ..Core import Networking, Utils


# The main widget of the GUI Client
class Client_Panel(QWidget): 
	def __init__(self):
		super().__init__()
		loadUi("UI/client_panel.ui", self)

		# setting some important variable
		self.client = None
		self.server_ip = None
		self.server_port = None
		self.countdown = None
		self.setFixedSize(QSize(640, 480))

		# connecting signal to component
		self.StartClient_Button.clicked.connect(self.Lockdown)
		self.Abort_Button.clicked.connect(self.CQD)


	# start connection to server
	def Connect_Server(self):
		try:
			# try to establish connection with the server		
			self.client = Networking.Client(self.server_ip, self.server_port)
			self.Text_Browser.setText("[INFO] Client successfully initialized.....")
			self.Text_Browser.append("[INFO] Client successfully connected to host {}".format(self.server_ip))

			# try to send to init number to the server to start the countdown
			self.client.send(Utils.EncodeType.INT, self.countdown)
			self.Text_Browser.append("[INFO] Sending the countdown number \'{}\' to server......\n".format(self.countdown))
			self.Start_Transmission()

		except OSError as ex:
			self.MsgBox("[ERROR]", "Connection to server failed", str(ex))
			sys.exit(-1)

		return


	# starting the transmission loop
	def Start_Transmission(self):
		# star the transmission loop in another thread seperately
		self.thread_worker = Transmission_Hdlr(self.client)
		self.thread_worker.update_signal.connect(self.Update_Browser)
		self.thread_worker.start()
		return


	# the callback for the Received_Countdown class
	def Update_Browser(self, data):
		self.Text_Browser.append(data)
		return


	# perform lockdown on lineedit connecting to server
	def Lockdown(self):
		self.server_ip = self.ServerIP_Input.text()
		self.server_port = self.ServerPort_Input.text()
		self.countdown = self.CountdownNum_Input.text()
		print("[TRACE] Receive Input:", self.server_ip)
		print("[TRACE] Receive Input:", self.server_port)
		print("[TRACE] Receive Input:", self.countdown)


		# check the validity of the server connection detail
		if not (Utils.Validity.ip(self.server_ip) and Utils.Validity.port(self.server_port)):
			print("\n[CRITICAL] User input invalid value on the server connection details.")
			self.MsgBox("[ERRROR]", "Server IP or Port not valid", "Aborting......")
			sys.exit(-1)

		else:
			print("[TRACE] The user input server connection details are valid")
			self.server_port = int(self.server_port)

		# check the validity of the countdown number
		if not (self.countdown.isdigit()):
			print("\n[CRITICAL] User input invalid value on the countdown number")
			self.MsgBox("[ERRROR]", "Countdown number must be integer", "Aborting......")
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

		# connect to server
		self.Connect_Server()
		return


	# aborting application abruptly
	def CQD(self):
		self.MsgBox("ALERT", "Program now aborting !!", "")
		sys.exit(-1)
		return


    # Alert messgae box
	def MsgBox(self, banner, title, text):
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
class Transmission_Hdlr(QThread):
	update_signal = pyqtSignal(str)

	def __init__(self, hdlr):
		super().__init__() # init the super
		self.client = hdlr
		self.buffer = None
		self.countdown = None


	def run(self):
		while True:
			# receive first to know what to send
			self.buffer = self.client.receive()

			# check if connection failed
			if not (self.buffer):
				self.update_signal.emit("\n[WARNING] Disconnected from server !\n")
				break

			datatype = self.buffer[0]
			data = self.buffer[1]
			self.update_signal.emit("[INFO] Received: {}".format(data))

			# check the received datatype to decide how to handle them
			# received data identify as an integer
			if (datatype == Utils.EncodeType.INT):
				if (data > 0):
					# sending the data - 1 back
					if not (self.client.send(Utils.EncodeType.INT, data - 1)):
						print("[WARNING] Can't send data to client !! Aborting......")
						return

					self.update_signal.emit("[INFO] Sending value {} back to server".format(data - 1))

				elif (data == 0):
					# sending a connection terminate signal to server
					if not (self.client.send(Utils.EncodeType.STR, "[TERMINATE]")):
						print("[WARNING] Can't send data to client !! Aborting......")
						return

					self.update_signal.emit("[INFO] Sending ther terminate command \'[TERMINATE]\' to server")


			# received data identify as an string
			elif (datatype == Utils.EncodeType.STR):
				if (data == "[TERMINATE]"):
					self.update_signal.emit("\n[INFO] Terminate signal recived, closing connection......\n")
					self.client.close()			
					break

				else:
					self.update_signal.emit("\n[WARNING] Unknown string command, ignoring......\n")

			# received an unknown data type in a known format
			else:
				self.update_signal.emit("\n[ERROR] Received a packet un unknown format\n")


		return