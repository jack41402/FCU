from PyQt6.QtCore import Qt
from PyQt6.QtGui import QTextCursor
from PyQt6.QtWidgets import QTableWidgetItem, QMainWindow
from home import Mailbox
from login import Login
from tcp import validate, mail
import sys


class MainWindow_controller(QMainWindow):
    def __init__(self):
        super(MainWindow_controller, self).__init__()
        self.mailbox = None

        self.login = Login()
        self.login.setupUi(self)
        self.login_setup_control()

        self.mail = None
        self.ip = "140.134.135.41"
        self.port = 110
        self.username = None
        self.password = None

    def login_setup_control(self):
        self.login.btn_Run.clicked.connect(self.RunClicked)
        self.login.btn_Exit.clicked.connect(self.LoginExitClicked)
        print("[INFO] Login setup successfully.")

    def mailbox_setup_control(self):
        self.mailbox.select_all_checkbox.stateChanged.connect(self.SelectAll)
        self.mailbox.mail_table.doubleClicked.connect(self.ShowMailContent)
        self.mailbox.delete_button.clicked.connect(self.DeleteMail)
        self.mailbox.exit_button.clicked.connect(self.MailboxExitClicked)

    def RunClicked(self):
        msg_IP_Address = self.login.lineEdit_IP_Address.text()
        msg_Server_Port = self.login.lineEdit_Server_Port.text()
        msg_IP_Address = self.ip if msg_IP_Address == "" else msg_IP_Address
        msg_Server_Port = self.port if msg_Server_Port == "" else msg_Server_Port

        msg_Username = self.login.lineEdit_Username.text()
        msg_Password = self.login.lineEdit_Password.text()

        validator = validate.Validate()
        # validator.valid_warning.connect(self.MessageBox)
        if validator.checker(msg_IP_Address, msg_Server_Port):
            print("[INFO] Validation success.")
        else:
            print("[INFO] Validation failed")

        self.ip = validator.ip
        self.port = validator.port
        self.username = msg_Username
        self.password = msg_Password

        self.mail = mail.Mail(self.ip, self.port)
        self.mail.mail_error_signal.connect(self.ErrorHandler)

        if not self.mail.user(self.username):
            return False
        if not self.mail.password(self.password):
            return False
        self.close()

        try:
            self.mailbox = Mailbox()
            self.mailbox.setupUi(self)
            self.mailbox_setup_control()
            self.show()
        except Exception as e:
            print("Other exception in MainWindow_controller.RunClicked: %s" % str(e))
        self.GetMail()

    def LoginExitClicked(self):
        sys.exit()

    def MailboxExitClicked(self):
        self.mail.quit()
        sys.exit()

    def GetMail(self):
        self.mail.content = {}
        self.mail.parseLength(self.mail.list(), False)
        for key in self.mail.content.keys():
            self.mail.retrive(key)
            self.AddMail(key)
        for key in self.mail.content.keys():
            print("\nKey: %s" % key)
            print(f"{self.mail.content[key]}")
        # for info in self.mail.content["header"]:
        #     print(info)

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
            print("Other exception in MainWindow_controller.ErrorHandler: %s" % str(e))

    def AddMail(self, msg):
        row_position = self.mailbox.mail_table.rowCount()
        self.mailbox.mail_table.insertRow(row_position)
        # Create mail info
        item = QTableWidgetItem()
        item.setCheckState(Qt.CheckState.Unchecked)
        self.mailbox.mail_table.setItem(row_position, 0, item)
        info = self.mail.content[msg]

        # Create row item
        self.mailbox.mail_table.setItem(row_position, 1, QTableWidgetItem(info["header"]["From"]))
        self.mailbox.mail_table.setItem(row_position, 2, QTableWidgetItem(info["header"]["To"]))
        self.mailbox.mail_table.setItem(row_position, 3, QTableWidgetItem(info["header"]["Subject"]))
        self.mailbox.mail_table.setItem(row_position, 4, QTableWidgetItem(info["header"]["Date"]))
        self.mailbox.mail_table.setItem(row_position, 5, QTableWidgetItem(info["header"]["Time"]))

        # Save mail content at first column in each mail
        item = self.mailbox.mail_table.item(row_position, 1)
        item.setData(Qt.ItemDataRole.UserRole, msg)

        item = self.mailbox.mail_table.item(row_position, 2)
        item.setData(Qt.ItemDataRole.UserRole, info["content"])

    def ShowMailContent(self, index):
        row = index.row()
        content_item = self.mailbox.mail_table.item(row, 2)
        content = content_item.data(Qt.ItemDataRole.UserRole)
        self.mailbox.mail_content.clear()
        self.mailbox.mail_content.insertPlainText(content)
        self.mailbox.mail_content.moveCursor(QTextCursor.MoveOperation.Start)

    def SelectAll(self):
        for row in range(self.mailbox.mail_table.rowCount()):
            item = self.mailbox.mail_table.item(row, 0)
            if item is not None:
                if self.mailbox.select_all_checkbox.checkState() == Qt.CheckState.Checked:
                    item.setCheckState(Qt.CheckState.Checked)
                else:
                    item.setCheckState(Qt.CheckState.Unchecked)

    def DeleteMail(self):
        try:
            for row in range(self.mailbox.mail_table.rowCount()):
                item = self.mailbox.mail_table.item(row, 0)
                msg = self.mailbox.mail_table.item(row, 1).data(Qt.ItemDataRole.UserRole)
                if item is not None and item.checkState() == Qt.CheckState.Checked:
                    print("Mail %s is checked!" % msg)
                    self.mail.delete(msg)
            self.mailbox.mail_table.setRowCount(0)
            self.GetMail()
        except Exception as e:
            print("Other exception in MainWindow_controller.DeleteMail: %s" % str(e))

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
