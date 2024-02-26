from PyQt6 import QtWidgets
from home import Ui_MainWindow
from tcp import validate, server, client
import sys


class MainWindow_controller(QtWidgets.QMainWindow):
    def __init__(self):
        super(MainWindow_controller, self).__init__()
        self.clicked_counter = None
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.setup_control()
        self.server = None
        self.client = None
        self.ip = None
        self.port = None
        self.num = None
        self.backlog = 5

    def setup_control(self):
        self.ui.btn_Run.clicked.connect(self.RunClicked)
        self.ui.btn_Exit.clicked.connect(self.ExitClicked)
        self.ui.btn_Clear.clicked.connect(self.ClearClicked)

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

    def ClearClicked(self):
        self.ui.textBrowser.setText("")

    def start(self):
        self.server = server.Server(self.ip, self.port)
        self.client = client.Client(self.ip, self.port, self.num)
        self.server.server_signal.connect(self.UpdateBrowser)
        self.client.client_signal.connect(self.UpdateBrowser)
        self.server.start()
        self.client.start()

    # callback of a custom singal in server thread
    def UpdateBrowser(self, data):
        self.ui.textBrowser.append(data)

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
