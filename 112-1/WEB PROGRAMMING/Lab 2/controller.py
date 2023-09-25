from PyQt6 import QtCore, QtGui, QtWidgets

import tcp.validate
from home import Ui_MainWindow
from tcp import *
import socket
import IPy


class MainWindow_controller(QtWidgets.QMainWindow):
    def __init__(self):
        super(MainWindow_controller, self).__init__()
        self.clicked_counter = None
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.setup_control()
        self.ip = None
        self.port = None
        self.num = None

    def setup_control(self):
        self.ui.btn_Run.clicked.connect(self.buttonClicked)

    def buttonClicked(self):
        msg_IP_Address = self.ui.lineEdit_IP_Address.text()
        msg_Server_Port = self.ui.lineEdit_Server_Port.text()
        msg_Number = self.ui.lineEdit_Number.text()
        validator = tcp.validate.Validate()
        if validator.checker(msg_IP_Address, msg_Server_Port, msg_Number):
            print("[INFO] Validation success.")
        else:
            print("[INFO] Validation Failed")
        self.ip = validator.ip
        self.port = validator.port
        self.num = validator.num
