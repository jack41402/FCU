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
        self.backlog = 5

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
        if not self.server:
            self.server = server.Server(self.ip, self.port)
        self.server.start()
        self.client_list.append(client.Client(self.ip, self.port, self.num, len(self.client_list) + 1))
        self.client_list[-1].start()
        print(self.client_list[-1])
        self.createBrowser()

    # callback of a custom singal in server thread
    def createBrowser(self):
        text_browser = TextBrowser()
        widget = text_browser
        self.ui.tabWidget.addTab(widget, f"Client {len(self.client_list)}")
        self.server.server_signal.connect(text_browser.updateBrowser)
        self.client_list[-1].client_signal.connect(text_browser.updateBrowser)

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
    update_signal = pyqtSignal(str)

    def __init__(self):
        super().__init__()
        self.text_browser = QTextBrowser()
        layout = QVBoxLayout()
        layout.addWidget(self.text_browser)
        self.setLayout(layout)
        self.update_signal.connect(self.text_browser.append)

    def updateBrowser(self, text):
        self.text_browser.append(text)
