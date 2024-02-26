# Coded by Eric Chen, 陳禹匡, D1172271
# ISTM, Purdue
#
# Copyright @ All Right Reserved

import sys
from PyQt6.uic import loadUi
from PyQt6.QtCore import QSize, QObject, pyqtSignal
from PyQt6.QtWidgets import QWidget, QLineEdit, QListWidgetItem
from ..POP3 import Dovecot
from . import List


# DESC: The panel with the connection details to reach the server
class Config_Panel(QWidget):
	def __init__(self):
		super().__init__()
		loadUi("UI/config_panel.ui", self)
		self.setFixedSize(QSize(1110, 600))
		self.Passwd_Input.setEchoMode(QLineEdit.EchoMode.Password)

		# attribute declaring
		self.server_ip = None
		self.server_port = None
		self.username = None
		self.passwd = None
		self.signal_hdlr = Custom_Signal()

		# signal binding
		self.Connect_Button.clicked.connect(self.Lockdown)


	# DESC: lockdown the input column and conenct to server
	def Lockdown(self):
		print("[INFO] Now lockdown all input column......")
		
		# read in all textedit column
		if (self.ServerIP_Input.text() == ""):
			self.server_ip = "127.0.0.1"
		else:
			self.server_ip = self.ServerIP_Input.text()

		if (self.ServerPort_Input.text() == ""):
			self.server_port = 110
		else:
			server_port = int(self.ServerPort_Input.text())
		
		self.username = self.UserName_Input.text()
		self.passwd = self.Passwd_Input.text()

		# lockdown
		self.ServerIP_Input.setEnabled(False)
		self.ServerPort_Input.setEnabled(False)
		self.UserName_Input.setEnabled(False)
		self.Passwd_Input.setEnabled(False)

		# trace for debugging
		print("[TRACE] Received Input:", self.server_ip)
		print("[TRACE] Received Input:", self.server_port)
		print("[TRACE] Received Input:", self.username)
		print("[TRACE] Received Input:", self.passwd)
		self.signal_hdlr.Trigger_Connect()
		return



# DESC: The email managemant page panel
class Email_Panel(QWidget):
	def __init__(self):
		super().__init__()
		loadUi("UI/email_panel.ui", self)
		self.setFixedSize(QSize(1110, 600))

		# attribute declaring
		self.API = None

		# signal binding
		self.Refresh_Button.clicked.connect(self.Refresh_MailBox)
		self.Delete_Button.clicked.connect(self.Delete_Email)
		self.Exit_Button.clicked.connect(self.CQD)


	def CQD(self):
		print("\n[TRACE] User exiting program......")

		try:
			if (self.API != None):
				if (self.API.QUIT()):
					print("[TRACE] Disconnected from POP3 server elegantly")
				
				else:
					print("[TRACE] Failed to disconnect with POP3 server")

		except Exception as ex:
			print("[WARNING] Caught expection:", str(ex))

		sys.exit(-1)
		return


	def Refresh_MailBox(self):
		print("\n[TRACE] User attempting to refresh the mailbox......")

		# reset all status
		self.Email_List.clear()

		# retrieve the avalible index inside
		uid_list = self.API.LIST()
		print("\n[INFO] Extracted mail UID list:", uid_list)

		# for each avalible index, create a preview of it
		for uid in uid_list:
			print("\n[TRACE] Trying to receive header of id", uid)
			(subject, sender, receiver, timestamp) = self.API.TOP(uid, 0)
			self.__Add_Email(uid, subject, sender, receiver, timestamp)

		# test dynamic list
		return


	def Delete_Email(self):
		print("\n[TRACE] User attempting to delete the selected emails......")

		for x in range(self.Email_List.count()):
			item = self.Email_List.item(x)
			entry = self.Email_List.itemWidget(item)

			if (entry.checkbox.isChecked()):
				print("\n[INFO] Trying to mark uid {} as deleted......".format(entry.uid))
				self.API.DELE(entry.uid)


		# force refresh
		self.Refresh_MailBox()
		return


	def __Add_Email(self, real_id, subject, sender, receiver, timestamp):
		# registering a new entry for the dynamic list
		list_item = QListWidgetItem(self.Email_List)
		email_entry = List.Email_Widget(real_id, subject, sender, receiver, timestamp, list_item)
		list_item.setSizeHint(email_entry.sizeHint()) # auto resize

		# add in the dynamic list
		self.Email_List.addItem(list_item)
		self.Email_List.setItemWidget(list_item, email_entry)
		return



# DESC: Signal to start connection
class Custom_Signal(QObject):
	connect_signal = pyqtSignal()

	def __init__(self):
		super().__init__()


	def Trigger_Connect(self):
		self.connect_signal.emit()
		return



if __name__ == "__main__":
	print("[DEBUG] Module Executed Locally")