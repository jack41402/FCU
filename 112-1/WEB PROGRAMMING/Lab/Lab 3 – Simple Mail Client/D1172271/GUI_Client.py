# Coded by Eric Chen, 陳禹匡, D1172271
# ISTM, Purdue
#
# Copyright @ All Right Reserved

import sys
from PyQt6.uic import loadUi
from PyQt6.QtCore import QSize
from PyQt6.QtWidgets import QApplication, QMainWindow, QTabWidget, QStackedWidget
from Library.GUI import Panel, List
from Library.POP3 import Dovecot


class MainWindow(QMainWindow):
	def __init__(self):
		super().__init__()
		loadUi("UI/base_window.ui", self) # load in ui

		# create a stack widget manager
		self.stackedwidget_manager = QStackedWidget()
		self.setCentralWidget(self.stackedwidget_manager)

		# create a tab widget
		self.tab_manager = QTabWidget(self)
		self.setFixedSize(QSize(1120, 610))

		# load in the the other main widgets wihich will act as tabs
		self.config_page = Panel.Config_Panel() # stack 0, tab 0
		self.management_page = Panel.Email_Panel() # stack 0, tab 1
		self.inspect_page = List.Email_Inspector() # stack 1
		
		# parenting
		self.config_page.setParent(self.tab_manager)
		self.management_page.setParent(self.tab_manager)
		self.inspect_page.setParent(self.stackedwidget_manager)
		self.tab_manager.setParent(self.stackedwidget_manager)

		# add the two panel in tab of main window
		self.tab_manager.addTab(self.config_page, "Server Details")
		self.tab_manager.addTab(self.management_page, "Account Management")
		self.tab_manager.setCurrentIndex(0)

		# add the tab manager and the email inspector into the stacked widget
		self.stackedwidget_manager.addWidget(self.tab_manager)
		self.stackedwidget_manager.addWidget(self.inspect_page)
		self.stackedwidget_manager.setCurrentIndex(0)

		# connecting some critical signal between pages
		self.config_page.Connect_Button.clicked.connect(self.To_Email_Management)
		self.config_page.signal_hdlr.connect_signal.connect(self.Connect_Server)
		self.config_page.Abort_Button.clicked.connect(self.CQD)
		self.management_page.Email_List.itemClicked.connect(self.Render_Inspector)
		self.inspect_page.PageReturn_Button.clicked.connect(self.Exit_Inspector)


	# DESC: abort the code
	def CQD(self):
		print("\n[WARNING] User aborting program......")
		
		# exit the pop3 server
		if (self.management_page.API != None):
			if (self.management_page.API.QUIT()):
				print("\n[INFO] Exited the pop3 server gracefully")

			else:
				print("\n[INFO] Exited the pop3 server abruptly")

		sys.exit(-1)
		return


	def To_Email_Management(self):
		self.tab_manager.setCurrentIndex(1)
		return


	def Connect_Server(self):
		print("\n[INFO] Now trying to connect to the pop3 server")
		self.management_page.API = Dovecot.API(self.config_page.server_ip, 
											   self.config_page.server_port)

		# login as user
		self.management_page.API.LOGIN(self.config_page.username,
									   self.config_page.passwd)

		# force initial sync to get inbox emails (LIST)
		self.management_page.Refresh_MailBox()
		return


	def Render_Inspector(self, item):
		# Get the Email_Widget instance associated with the clicked item
		email_instance = self.management_page.Email_List.itemWidget(item)
		print("\n[TRACE] Email Inspector rendering triggerd for uid {}!".format(email_instance.uid))

		# try to receive the actual content by uid
		content = self.management_page.API.RETR(email_instance.uid)

		# render the content if RETR succeed
		if not (content):
			pass
		
		else:
			self.inspect_page.Mail_Browser.setText(str(content))


		# render it in the way the class is called
		self.inspect_page.Subject_Label.setText("Subject: " + str(email_instance.subject_label.text()))
		self.inspect_page.From_Label.setText("From: " + str(email_instance.sender_label.text()))
		self.inspect_page.To_Label.setText("To: " + str(email_instance.receiver_label.text()))
		self.inspect_page.Timestamp_Label.setText("Timestamp: " + str(email_instance.timestamp_label.text()))

		# switch page focus on inspector
		self.stackedwidget_manager.setCurrentIndex(1)
		return


	def Exit_Inspector(self):
		self.stackedwidget_manager.setCurrentIndex(0)
		return



def main():
	app = QApplication([])
	window = MainWindow()
	window.show()
	app.exec()
	return


if __name__ == "__main__":
	main() 