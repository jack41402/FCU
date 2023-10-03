# Student ID: D1166506
# Name: 周嘉禾
import socket
from PyQt6.QtCore import pyqtSignal, QThread
from . import message


class Client(QThread):
    client_error_signal = pyqtSignal(str)

    def __init__(self, ip: str, port: int):
        super().__init__()
        self.ip = ip
        self.port = port
        self.buf_size = 1024
        self.clientSocket = None
        self.run()


    def run(self):
        self.connection()

    def connection(self):
        self.clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print("Connecting to %s port %s" % (self.ip, self.port))
        self.clientSocket.connect((self.ip, self.port))
        self.receive()
        print("[CLIENT] Connected successfully.")

    def send(self, msg: str):
        message.send_msg(self.clientSocket, str(msg))
        return True

    def receive(self):
        try:
            msg = "Receive message from IP: " + str(self.ip) + " port: " + str(self.port)
            print(msg)
            server_msg = message.receive_msg(self.clientSocket)
            if server_msg is not None:
                return server_msg
        except Exception as e:
            print("Other exception in client.receive: %s" % str(e))

    def close(self):
        self.clientSocket.close()
