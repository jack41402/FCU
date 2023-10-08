from PyQt6.QtCore import Qt
from PyQt6.QtGui import QTextCursor
from PyQt6.QtWidgets import QTableWidgetItem, QMainWindow
from UI import login, register
from database import sql
from tcp import validate
import sys


class Login_controller(QMainWindow):
    def __init__(self):
        super(Login_controller, self).__init__()
        self.LoginWindow = login.Ui_Login()
        self.LoginWindow.setupUi(self)
        self.login_setup_control()

        self.RegisterWindow = None

        self.ip = "127.0.0.1"
        self.port = 6666

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
            user_info = self.database.findInfo("user_information", "username", username)
            if not username:
                print("[ERROR] USERNAME CAN'T BE EMPTY.")
                self.LoginWindow.Password_lineEdit.setText("")
                return False
            elif not password:
                print("[ERROR] PASSWORD CAN'T BE EMPTY.")
                self.LoginWindow.Password_lineEdit.setText("")
                return False
            elif len(user_info) == 0:
                print("[ERROR] USERNAME DOES NOT EXIST.")
                self.LoginWindow.Password_lineEdit.setText("")
                return False
            elif password != user_info[0][2]:
                print("[ERROR] PASSWORD INCORRECT.")
                self.LoginWindow.Password_lineEdit.setText("")
                return False
            else:
                self.close()
                if self.RegisterWindow:
                    self.RegisterWindow.close()
                print("[INFO] Login successfully.")
                return True
        except Exception as e:
            print(f'[ERROR] Other exception in Login_controller.LoginClicked: {e}')

    def RegisterClicked(self):
        try:
            self.RegisterWindow = Register_controller()
            self.RegisterWindow.LoginWindow = self
            self.hide()
            self.LoginWindow.Username_lineEdit.setText("")
            self.LoginWindow.Password_lineEdit.setText("")
            self.RegisterWindow.show()
        except Exception as e:
            print(f'[ERROR] Other exception in Login_controller.RegisterClicked: {e}')

    # callback of a custom signal in server thread
    def ErrorHandler(self, error_msg):
        try:
            if error_msg == "USER ERROR":
                print("[ERROR] USER FAULT")
                self.LoginWindow.lineEdit_Username.setText("")
                self.LoginWindow.lineEdit_Password.setText("")
            elif error_msg == "PASSWORD ERROR":
                print("[ERROR] PASSWORD FAULT")
                self.LoginWindow.lineEdit_Password.setText("")
        except Exception as e:
            print("Other exception in MainWindow_controller.ErrorHandler: %s" % str(e))

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
            user_info = self.database.findInfo("user_information", "username", username)
            print(user_info)
            if user_info:
                print("[ERROR] USERNAME ALREADY EXIST.")
                self.RegisterWindow.Password_lineEdit.setText("")
                self.RegisterWindow.Confirm_Password_lineEdit.setText("")
                return False
            elif not password:
                print("[ERROR] PASSWORD CAN'T BE EMPTY.")
                self.RegisterWindow.Password_lineEdit.setText("")
                self.RegisterWindow.Confirm_Password_lineEdit.setText("")
                return False
            elif password != confirm_password:
                print("[ERROR] PASSWORD DOESN'T MATCH.")
                self.RegisterWindow.Password_lineEdit.setText("")
                self.RegisterWindow.Confirm_Password_lineEdit.setText("")
                return False
            else:
                self.database.insertInfo("user_information", {"username": username, "password": password})
                self.close()
                self.LoginWindow.show()
                print("[INFO] Register successfully.")
                return True
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
