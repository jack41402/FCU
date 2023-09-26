from PyQt6 import QtCore, QtGui, QtWidgets

from home import Ui_MainWindow
from tcp import thread, message, validate, server, client
import socket
import IPy


class MainWindow_controller(QtWidgets.QMainWindow):
    def __init__(self):
        super(MainWindow_controller, self).__init__()
        self.clicked_counter = None
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.setup_control()
        self.server = None
        self.client = None
        self.serverThread = None
        self.clientThread = None
        self.ip = None
        self.port = None
        self.num = None
        self.backlog = 5

    def setup_control(self):
        self.ui.btn_Run.clicked.connect(self.RunClicked)
        self.ui.btn_send_4.clicked.connect(self.SendClicked)

    def RunClicked(self):
        msg_IP_Address = self.ui.lineEdit_IP_Address.text()
        msg_Server_Port = self.ui.lineEdit_Server_Port.text()
        msg_Number = self.ui.lineEdit_Number.text()
        validator = validate.Validate()
        if validator.checker(msg_IP_Address, msg_Server_Port, msg_Number):
            print("[INFO] Validation success.")
        else:
            print("[INFO] Validation Failed")
        self.ip = validator.ip
        self.port = validator.port
        self.num = validator.num
        self.start()

    def SendClicked(self):
        print("I been to send clicked")
        self.clientThread.client.send()
        self.serverThread.server.receive()

    def start(self):
        self.server = server.Server(self.ip, self.port)
        self.client = client.Client(self.ip, self.port, self.num)

        self.serverThread = thread.ServerThread(self.server)
        self.serverThread.start()

        self.clientThread = thread.ClientThread(self.client)
        self.clientThread.start()


    # callback of a custom singal in server thread
    def Server_UpdateBrowser(self, data):
        self.ui.textBrowser.append(data)
        return
