# Student ID: D1166506
# Name: 周嘉禾
import socket
from PyQt6.QtCore import pyqtSignal, QThread
import message
from mail import Mail


class Client(QThread):
    client_error_signal = pyqtSignal(str)

    def __init__(self, username: str, password: str, ip: str = "140.134.135.41", port: int = 110, ):
        super().__init__()
        self.ip = ip
        self.port = port
        self.username = username
        self.password = password
        self.buf_size = 1024
        self.clientSocket = None
        self.mail = None

    def run(self):
        self.connection()
        self.mail = Mail(self.clientSocket)
        error = self.mail.user(self.username)
        if error[0] == '-':
            self.client_error_signal.emit("USER ERROR")
            return False
        error = self.mail.password(self.password)
        if error[0] == '-':
            self.client_error_signal.emit("PASSWORD ERROR")
            return False
        self.mail.list()


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
        msg = "Receive message from IP: " + str(self.ip) + " port: " + str(self.port)
        print(msg)
        server_msg = message.receive_msg(self.clientSocket)
        return server_msg

    def close(self):
        self.clientSocket.close()
