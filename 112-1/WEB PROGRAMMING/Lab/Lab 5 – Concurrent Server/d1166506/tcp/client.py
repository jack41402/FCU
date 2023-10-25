# Student ID: D1166506
# Name: 周嘉禾
import socket
import threading
from PyQt6.QtCore import pyqtSignal, QThread
from . import message


class Client(QThread):
    client_signal = pyqtSignal(int, str)

    def __init__(self, ip, port, number, index):
        super().__init__()
        self.ip = ip
        self.port = port
        self.buf_size = 1024
        self.number = number
        self.clientSocket = None
        self.index = index

    def run(self):
        try:
            self.connection()
            self.send(str(self.index))
            while True:
                if self.number - 1 == 0:
                    print("\n**** The number is zero. Closing the connection.\n")
                    self.client_signal.emit(self.index, "[CLIENT] The number is zero. Closing the connection.")
                    self.send("END")
                    self.client_signal.emit(self.index, "[CLIENT] Send: \"END\" message.")
                    break
                else:
                    self.number -= 1
                    self.send(str(self.number))
                    self.client_signal.emit(self.index, "[CLIENT] Send: %d" % self.number)
                server_msg = self.receive()
                if server_msg == 0:
                    print("Receive END message. Closing the connection.")
                    self.client_signal.emit(self.index, "[CLIENT] Receive: \"END\" message.")
                    self.client_signal.emit(self.index, "[CLIENT] Closing the connection.")
                    break
                else:
                    self.number = server_msg
                    self.client_signal.emit(self.index, "[CLIENT] Receive: %d" % server_msg)
            self.close()
        except Exception as e:
            print(f'[ERROR] Other exception in client.run: {e}, line ', e.__traceback__.tb_lineno)

    def connection(self):
        try:
            self.clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            print("Connecting to %s port %s\n" % (self.ip, self.port))
            self.clientSocket.connect((self.ip, self.port))
            self.client_signal.emit(self.index, "[CLIENT] Connected successfully.")
        except Exception as e:
            print(f'[ERROR] Other exception in client.connection: {e}, line ', e.__traceback__.tb_lineno)

    def send(self, msg: str):
        try:
            message.send_msg(self.clientSocket, str(msg))
            return True
        except Exception as e:
            print(f'[ERROR] Other exception in client.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            msg = "Receive message from IP: " + str(self.ip) + " port: " + str(self.port)
            print(msg)
            server_msg = message.receive_msg(self.clientSocket)
            return server_msg
        except Exception as e:
            print(f'[ERROR] Other exception in client.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.clientSocket.close()
