# Student ID: D1166506
# Name: 周嘉禾
import socket
from PyQt6.QtCore import pyqtSignal, QThread
from . import message
from database import sql
from xmlrpc.server import SimpleXMLRPCServer, SimpleXMLRPCRequestHandler


class Server(QThread):
    server_signal = pyqtSignal(str)

    def __init__(self, ip, port):
        super().__init__()
        self.ip = ip
        self.port = port
        self.serverSocket = None

        self.database = sql.SQL()

    def run(self):
        self.connection()

    def connection(self):

        print("Starting up server on port: %s" % self.port)

        print("[SERVER] Waiting for connection...")

    def registry(self):


    def login(self, username: str, password: str):
        user_info = self.database.findInfo("user_information", "username", username)
        if not username:
            print("[ERROR] USERNAME CAN'T BE EMPTY.")
            return False
        elif not password:
            print("[ERROR] PASSWORD CAN'T BE EMPTY.")
            return False
        elif len(user_info) == 0:
            print("[ERROR] USERNAME DOES NOT EXIST.")
            return False
        elif password != user_info[0][2]:
            print("[ERROR] PASSWORD INCORRECT.")
            return False
        else:
            print("[INFO] Login successfully.")
            return True

    def register(self, username: str, password: str, confirm_password: str):
        user_info = self.database.findInfo("user_information", "username", username)
        print(user_info)
        if user_info:
            print("[ERROR] USERNAME ALREADY EXIST.")
            return False
        elif not password:
            print("[ERROR] PASSWORD CAN'T BE EMPTY.")
            return False
        elif password != confirm_password:
            print("[ERROR] PASSWORD DOESN'T MATCH.")
            return False
        else:
            self.database.insertInfo("user_information", {"username": username, "password": password})
            print("[INFO] Register successfully.")
            return True

    def create(self):
        pass

    def subject(self):
        pass

    def reply(self):
        pass

    def discussion(self):
        pass

    def delete(self):
        pass

    def close(self):
        self.client.close()
        self.serverSocket.close()
