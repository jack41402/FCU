from PyQt6.QtCore import Qt, pyqtSignal
from PyQt6.QtGui import QTextCursor
from PyQt6.QtWidgets import QTableWidgetItem, QMainWindow
from UI import login, register
from database import sql
from rpc import server, client, validate
import sys


class Login_controller(QMainWindow):
    login_signal = pyqtSignal(str)

    def __init__(self):
        super(Login_controller, self).__init__()
        self.LoginWindow = login.Ui_Login()
        self.LoginWindow.setupUi(self)
        self.login_setup_control()
        self.RegisterWindow = None
        self.client = None
        self.ip = "127.0.0.1"
        self.port = 6666
        self.start()
        self.database = sql.SQL()

    def login_setup_control(self):
        try:
            self.LoginWindow.Login_button.clicked.connect(self.LoginClicked)
            self.LoginWindow.Register_label.linkActivated.connect(self.RegisterClicked)
            print("[INFO] Login setup successfully.")
        except Exception as e:
            print(f'[ERROR] Other exception in Login_controller.login_setup_control: {e}')

    def LoginClicked(self):
        try:
            username = self.LoginWindow.Username_lineEdit.text()
            password = self.LoginWindow.Password_lineEdit.text()
            try_login = self.server.login(username, password)
            if try_login is False:
                self.LoginWindow.Password_lineEdit.setText("")
            elif try_login is True:
                self.close()
                if self.RegisterWindow:
                    self.RegisterWindow.close()
            else:
                return False
        except Exception as e:
            print(f'[ERROR] Other exception in Login_controller.LoginClicked: {e}')

    def RegisterClicked(self):
        try:
            if not self.RegisterWindow:
                self.RegisterWindow = Register_controller()
            self.RegisterWindow.LoginWindow = self
            self.RegisterWindow.server = self.server
            self.hide()
            self.LoginWindow.Username_lineEdit.setText("")
            self.LoginWindow.Password_lineEdit.setText("")
            self.RegisterWindow.show()
        except Exception as e:
            print(f'[ERROR] Other exception in Login_controller.RegisterClicked: {e}')

    def start(self):
        self.client = client.Client(self.ip, self.port)
        # self.client.client_signal.connect(self.UpdateBrowser)
        self.client.start()

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


class Register_controller(QMainWindow):
    def __init__(self):
        super(Register_controller, self).__init__()
        self.RegisterWindow = register.Ui_Register()
        self.RegisterWindow.setupUi(self)
        self.register_setup_control()

        self.LoginWindow = None
        self.server = None
        self.database = sql.SQL()

    def register_setup_control(self):
        try:
            self.RegisterWindow.Register_button.clicked.connect(self.RegisterClicked)
            self.RegisterWindow.Login_label.linkActivated.connect(self.LoginClicked)
            print("[INFO] Register setup successfully.")
        except Exception as e:
            print(f'[ERROR] Other exception in Register_controller.register_setup_control: {e}')

    def RegisterClicked(self):
        try:
            username = self.RegisterWindow.Username_lineEdit.text()
            password = self.RegisterWindow.Password_lineEdit.text()
            confirm_password = self.RegisterWindow.Confirm_Password_lineEdit.text()
            try_register = self.server.register(username, password, confirm_password)
            if try_register is False:
                self.RegisterWindow.Password_lineEdit.setText("")
                self.RegisterWindow.Confirm_Password_lineEdit.setText("")
            elif try_register is True:
                self.close()
                self.LoginWindow.show()
        except Exception as e:
            print(f'[ERROR] Other exception in Login_controller.LoginClicked: {e}')

    def LoginClicked(self):
        try:
            self.hide()
            self.RegisterWindow.Username_lineEdit.setText("")
            self.RegisterWindow.Password_lineEdit.setText("")
            self.RegisterWindow.Confirm_Password_lineEdit.setText("")
            self.LoginWindow.show()
        except Exception as e:
            print(f'[ERROR] Other exception in Login_controller.RegisterClicked: {e}')


class Forum_controller(QMainWindow):
    def __init__(self):
        super(Forum_controller, self).__init__()
        self.LoginWindow = login.Ui_Login()
        self.LoginWindow.setupUi(self)
        self.login_setup_control()
        self.RegisterWindow = None
        self.client = None
        self.ip = "127.0.0.1"
        self.port = 6666
        self.start()
        self.database = sql.SQL()
