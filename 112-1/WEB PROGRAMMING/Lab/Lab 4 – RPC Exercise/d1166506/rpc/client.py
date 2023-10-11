# Student ID: D1166506
# Name: 周嘉禾
import socket
import xmlrpc.client
from PyQt6.QtCore import pyqtSignal, QThread
from . import message


class Client(QThread):
    client_error_signal = pyqtSignal(str)

    def __init__(self, ip: str, port: int):
        super().__init__()
        self.ip = ip
        self.port = port
        self.address = f'https://{self.ip}:{self.port}/'
        self.proxy = None
        # CHECK HTTPS
        self.run()

    def run(self):
        self.connection()

    def connection(self):
        print("Connecting to %s port %s" % (self.ip, self.port))
        self.proxy = xmlrpc.client.ServerProxy(self.address)
        print("[CLIENT] Connected successfully.")

    def close(self):
        self.clientSocket.close()
