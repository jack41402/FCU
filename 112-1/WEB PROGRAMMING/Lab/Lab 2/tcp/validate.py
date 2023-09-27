from PyQt6 import QtCore, QtGui, QtWidgets
from home import Ui_MainWindow
import socket
import IPy

ui = Ui_MainWindow()


class Validate:
    def __init__(self):
        self.ip = None
        self.port = None
        self.num = None

    def check_ip(self, address: str):
        global ui
        if not address:
            print("[ERROR] IP ADDRESS CAN'T BE EMPTY.\n")
            return False
        if address == "localhost":
            address = "127.0.0.1"
        try:
            IPy.IP(address)
            print("[INFO] IP is correct.\n")
            self.ip = address
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            print("[ERROR] WRONG IP ADDRESS.\n")
            return False

    def check_port(self, ip: str, port: int):
        if not port:
            print("[ERROR] PORT CAN'T BE EMPTY.\n")
            return False
        else:
            port = int(port)

        if not str(port).isdigit():
            print("[ERROR] PORT ISN'T A INTEGER.\n")
            print("[INFO] Port number should be 1~65535.\n")
            return False
        elif not 1 <= port <= 65535:
            print("[ERROR] PORT IS OUT OF RANGE.")
            print("[INFO] Port number should be 1~65535.\n")
            return False
        else:
            print("[INFO] PORT is correct.\n")
            self.port = port
            return True

    def check_number(self, number: int):
        if not number:
            print("[ERROR] NUMBER CAN'T BE EMPTY.\n")
            return False
        else:
            number = int(number)
        if not str(number).isdigit():
            print("[ERROR] NUMBER ISN'T A INTEGER.\n")
            print("[INFO] Number should be a positive integer.\n")
            return False
        if number < 1:
            print("[ERROR] NUMBER ISN'T A INTEGER.\n")
            print("[INFO] Number should be a positive integer.\n")
            return False
        try:
            print("[INFO] Number is correct.\n")
            self.num = number
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    def checker(self, msg_IP_Address: str, msg_Server_Port: int, msg_Number: int):
        if not self.check_ip(msg_IP_Address):
            ui.lineEdit_IP_Address.setText("")
            return False
        if not self.check_port(self.ip, msg_Server_Port):
            ui.lineEdit_Server_Port.setText("")
            return False
        if not self.check_number(msg_Number):
            ui.lineEdit_Number.setText("")
            return False

        print("IP: %s" % self.ip)
        print("PORT: %s" % self.port)
        print("NUMBER: %d" % self.num)
        return True
