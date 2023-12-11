# Coded by Eric Chen, 陳禹匡, D1172271
# ISTM, Purdue
#
# Copyright @ All Right Reserved

from PyQt6.uic import loadUi
from PyQt6.QtCore import QSize, pyqtSignal
from PyQt6.QtGui import QIcon, QColor
from PyQt6.QtWidgets import (
	QWidget,
	QCheckBox,
	QLabel,
	QHBoxLayout,
)


# The indivisual item (email) displaying in a dynamic list
class Email_Widget(QWidget):
	def __init__(self, real_id, subject, sender, receiver, timestamp, list_item):
		super().__init__()

		# store the corresponding list item
		self.uid = real_id 
		self.list_item = list_item
		self.icon_label = QLabel()
		self.checkbox = QCheckBox()
		self.subject_label = QLabel(subject)
		self.sender_label = QLabel(sender)
		self.receiver_label = QLabel(receiver)
		self.timestamp_label = QLabel(timestamp)

		# prepare horizontal layout
		layout = QHBoxLayout()
		layout.addWidget(self.checkbox)
		layout.addWidget(self.icon_label)
		layout.addSpacing(5)
		layout.addWidget(self.subject_label)
		layout.addSpacing(50)
		layout.addWidget(self.sender_label)
		layout.addSpacing(30)
		layout.addWidget(self.receiver_label)
		layout.addSpacing(30)
		layout.addWidget(self.timestamp_label)
		self.setLayout(layout)

		# set the widgets
		self.icon_label.setPixmap(QIcon("ICON/mail.png").pixmap(32, 32))
		self.Update_Hightlight()

		# connect signal
		self.checkbox.stateChanged.connect(self.Update_Hightlight)


	# DESC: For updating the list object color to make it highlighted if it is checked
	def Update_Hightlight(self):
		if (self.checkbox.isChecked()):
			self.list_item.setBackground(QColor("lightblue"))

		else:
			self.list_item.setBackground(QColor("white"))

		return


# The widget to inspect a email which is clicked
class Email_Inspector(QWidget):
	def __init__(self):
		super().__init__()
		loadUi("UI/email_detail.ui", self)
		self.setFixedSize(QSize(1110, 600))