from PyQt6.QtCore import Qt
from PyQt6.QtGui import QTextCursor
from PyQt6.QtWidgets import QTableWidgetItem, QMainWindow
from home import Mailbox
from login import Login
from tcp import validate, client
import sys


class MainWindow_controller(QMainWindow):
    def __init__(self):
        super(MainWindow_controller, self).__init__()
        self.mailbox = Mailbox()
        self.mailbox.setupUi(self)

        self.login = Login()
        self.login.setupUi(self)

        self.setup_control()
        self.client = None
        self.ip = "140.134.135.41"
        self.port = 110
        self.username = None
        self.password = None

    def setup_control(self):
        self.mailbox.select_all_checkbox.stateChanged.connect(self.SelectAll)
        self.mailbox.mail_table.doubleClicked.connect(self.ShowMailContent)
        self.mailbox.delete_button.clicked.connect(self.DeleteMail)

        self.login.btn_Run.clicked.connect(self.RunClicked)
        self.login.btn_Exit.clicked.connect(self.ExitClicked)

    def RunClicked(self):
        msg_IP_Address = self.login.lineEdit_IP_Address.text()
        msg_Server_Port = self.login.lineEdit_Server_Port.text()

        msg_Username = self.login.lineEdit_Username.text()
        msg_Password = self.login.label_Password.text()

        validator = validate.Validate()
        # validator.valid_warning.connect(self.MessageBox)
        if validator.checker(msg_IP_Address, msg_Server_Port):
            print("[INFO] Validation success.")
        else:
            print("[INFO] Validation Failed")

        self.ip = validator.ip
        self.port = validator.port
        self.username = msg_Username
        self.password = msg_Password
        self.start()

    def ExitClicked(self):
        sys.exit(-1)

    def start(self):
        self.client = client.Client(ip=self.ip, port=self.port, username=self.username , password=self.password)
        self.client.client_error_signal.connect(self.ErrorHandler)
        self.client.start()

    # callback of a custom signal in server thread
    def ErrorHandler(self, error_msg):
        try:
            if error_msg == "USER ERROR":
                print("[ERROR] USER FAULT")
                self.login.lineEdit_Username.setText("")
                self.login.lineEdit_Password.setText("")
            elif error_msg == "PASSWORD ERROR":
                print("[ERROR] PASSWORD FAULT")
                self.login.lineEdit_Password.setText("")
        except Exception as e:
            print("Other exception: %s" % str(e))

    def AddMail(self, sender, subject, date, time, content):
        row_position = self.mailbox.mail_table.rowCount()
        self.mailbox.mail_table.insertRow(row_position)

        # Create mail info
        item = QTableWidgetItem()
        item.setCheckState(Qt.CheckState.Unchecked)
        self.mail_table.setItem(row_position, 0, item)

        # Create row item
        self.mail_table.setItem(row_position, 1, QTableWidgetItem(sender))
        self.mail_table.setItem(row_position, 2, QTableWidgetItem(subject))
        self.mail_table.setItem(row_position, 3, QTableWidgetItem(date))
        self.mail_table.setItem(row_position, 4, QTableWidgetItem(time))

        # Save mail content at first column in each mail
        item = self.mail_table.item(row_position, 1)
        item.setData(Qt.ItemDataRole.UserRole, content)

    def ShowMailContent(self, index):
        row = index.row()
        content_item = self.mail_table.item(row, 1)
        content = content_item.data(Qt.ItemDataRole.UserRole)
        self.mail_content.clear()
        self.mail_content.insertPlainText(content)
        self.mail_content.moveCursor(QTextCursor.MoveOperation.Start)

    def SelectAll(self):
        for row in range(self.mail_table.rowCount()):
            item = self.mail_table.item(row, 0)
            if item is not None:
                if self.select_all_checkbox.checkState() == Qt.CheckState.Checked:
                    item.setCheckState(Qt.CheckState.Checked)
                else:
                    item.setCheckState(Qt.CheckState.Unchecked)

    def DeleteMail(self):
        pass
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
