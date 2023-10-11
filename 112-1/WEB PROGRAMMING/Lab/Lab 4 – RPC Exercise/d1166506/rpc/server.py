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
        self.server = None

        self.database = sql.SQL()

    def run(self):
        self.connection()

    def connection(self):
        try:
            print("Starting up server on port: %s" % self.port)
            self.server = SimpleXMLRPCServer(("localhost", self.port))
            self.server.serve_forever()
            print("[SERVER] Waiting for connection...")
        except Exception as e:
            print(f'[ERROR] Other exception in server.connection: {e}')

    def registry(self):
        self.server.registry(self.login, "login")
        self.server.registry(self.register, "register")
        self.server.registry(self.create, "create")
        self.server.registry(self.subject, "subject")

    def login(self, username: str, password: str):
        try:
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
        except Exception as e:
            print(f'[ERROR] Other exception in server.login: {e}')

    def register(self, username: str, password: str, confirm_password: str):
        try:
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
                maxId = self.database.findMaxId("user_information")
                self.database.insertInfo("user_information",
                                         {"id": maxId, "username": username, "password": password})
                print("[INFO] Register successfully.")
                return True
        except Exception as e:
            print(f'[ERROR] Other exception in server.register: {e}')

    def create(self, title: str, content: str, username: str):
        try:
            if not title:
                print("[ERROR] TITLE CAN'T BE EMPTY.")
            elif not content:
                print("[ERROR] CONTENT CAN'T BE EMPTY.")
            else:
                maxId = self.database.findMaxId("forum")
                user_id = self.database.findInfo("user_information", "username", username)
                user_id = user_id[0][0]
                self.database.insertInfo("forum",
                                         {"id": maxId, "title": title, "content": content, "date": "NOW()", "user_id": user_id})
        except Exception as e:
            print(f'[ERROR] Other exception in server.create: {e}')

    def subject(self):
        try:
            article = self.database.getTable("forum")
            for row in article:
                print(row)
        except Exception as e:
            print(f'[ERROR] Other exception in server.subject: {e}')

    def reply(self):
        pass

    def discussion(self):
        pass

    def delete(self):
        pass

    def close(self):
        pass
