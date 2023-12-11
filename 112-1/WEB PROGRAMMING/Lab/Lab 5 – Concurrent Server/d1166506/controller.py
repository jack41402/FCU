import threading

from PyQt6.QtCore import pyqtSignal
from PyQt6.QtWidgets import QWidget, QMainWindow, QTextBrowser, QVBoxLayout
from home import Ui_MainWindow
from tcp import validate, server, client
import sys


class MainWindow_controller(QMainWindow):
    def __init__(self):
        super(MainWindow_controller, self).__init__()
        self.clicked_counter = None
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.setup_control()
        self.server = None
        self.client_list = []
        self.ip = None
        self.port = None
        self.num = None
        self.backlog = 15

    def setup_control(self):
        self.ui.btn_Run.clicked.connect(self.RunClicked)
        self.ui.btn_Exit.clicked.connect(self.ExitClicked)

    def RunClicked(self):
        msg_IP_Address = self.ui.lineEdit_IP_Address.text()
        msg_Server_Port = self.ui.lineEdit_Server_Port.text()
        msg_Number = self.ui.lineEdit_Number.text()
        validator = validate.Validate()
        # validator.valid_warning.connect(self.MessageBox)
        if validator.checker(msg_IP_Address, msg_Server_Port, msg_Number):
            print("[INFO] Validation success.")
        else:
            print("[INFO] Validation Failed")

        self.ip = validator.ip
        self.port = validator.port
        self.num = validator.num
        self.start()

    def ExitClicked(self):
        sys.exit(-1)

    def start(self):
        try:
            if not self.server:
                self.server = server.Server(self.ip, self.port)
                self.server.start()
                print(self.server.serverSocket)
            self.client_list.append(client.Client(self.ip, self.port, self.num, len(self.client_list) + 1))
            self.client_list[-1].start()
            self.createBrowser()
            self.server.counter()
        except Exception as e:
            print(f'[ERROR] Other exception in MainWindow_controller.start: {e}, line ', e.__traceback__.tb_lineno)

    # callback of a custom singal in server thread
    def createBrowser(self):
        try:
            text_browser = TextBrowser(len(self.client_list))
            widget = text_browser
            self.ui.tabWidget.addTab(widget, f"Client {len(self.client_list)}")
            self.client_list[-1].client_signal.connect(text_browser.updateBrowser)
            self.server.server_signal.connect(text_browser.updateBrowser)
        except Exception as e:
            print(f'[ERROR] Other exception in MainWindow_controller.createBrowser: {e}, line ', e.__traceback__.tb_lineno)

    # def MessageBox(self, msg_type: str, msg: str):
    #     print("WRONG")
    #     mbox = QtWidgets.QMessageBox(self)
    #     if msg_type == "information":
    #         mbox.information(self, 'information', msg)
    #     elif msg_type == "question":
    #         mbox.question(self, 'question', msg)
    #     elif msg_type == "warning":
    #         mbox.warning(self, 'warning', msg)
    #     elif msg_type == "critical":
    #         mbox.critical(self, 'critical', msg)


class TextBrowser(QWidget):
    def __init__(self, index):
        super().__init__()
        self.text_browser = QTextBrowser()
        layout = QVBoxLayout()
        layout.addWidget(self.text_browser)
        self.setLayout(layout)
        self.text_browser.setProperty("index", index)
        self.lock = threading.Lock()

    def updateBrowser(self, index: int, text: str):
        try:
            if index == self.text_browser.property("index"):
                self.text_browser.append(text)
        except Exception as e:
            print(f'[ERROR] Other exception in TextBrowser.updateBrowser: {e}, line ', e.__traceback__.tb_lineno)
