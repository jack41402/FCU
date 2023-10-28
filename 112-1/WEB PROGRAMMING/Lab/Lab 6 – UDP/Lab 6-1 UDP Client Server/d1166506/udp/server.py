# Student ID: D1166506
# Name: 周嘉禾
import socket
from PyQt6.QtCore import pyqtSignal, QThread
from . import message


class Server(QThread):
    server_signal = pyqtSignal(str)

    def __init__(self, ip, port):
        super().__init__()
        self.ip = ip
        self.port = port
        self.buf_size = 1024
        self.number = None
        self.serverSocket = None
        self.rip = None
        self.rport = None

    def run(self):
        try:
            self.connection()
            while True:
                self.number = self.receive()
                if self.number == 0:
                    print("Receive END message. Closing the connection.")
                    self.server_signal.emit("[SERVER] Receive: \"END\" message.")
                    self.server_signal.emit("[SERVER] Closing the connection.")
                    break
                if self.number - 1 != 0:
                    self.number -= 1
                    self.send(str(self.number))
                    self.server_signal.emit("[SERVER] Send: %d" % self.number)
                else:
                    print("\n**** The number is zero. Closing the connection.\n")
                    self.server_signal.emit("[SERVER] The number is zero. Closing the connection.")
                    self.send("END")
                    self.server_signal.emit("[SERVER] Send: \"END\" message.")
                    break
            self.close()
        except Exception as e:
            print(f'[ERROR] Other exception in server.run: {e}, line ', e.__traceback__.tb_lineno)

    def connection(self):
        try:
            self.serverSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            print("Starting up server on port: %s" % self.port)
            self.serverSocket.bind(('', self.port))
            self.server_signal.emit("[SERVER] Waiting for connection...")
        except Exception as e:
            print(f'[ERROR] Other exception in server.connection: {e}, line ', e.__traceback__.tb_lineno)

    def send(self, msg: str):
        try:
            message.send_msg(self.serverSocket, str(msg), (self.ip, self.port))
            return True
        except Exception as e:
            print(f'[ERROR] Other exception in server.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            num, (self.rip, self.rport) = message.receive_msg(self.serverSocket)
            msg = "\nReceive message from IP: " + str(self.rip) + " port: " + str(self.rport)
            print(msg)
            return num
        except Exception as e:
            print(f'[ERROR] Other exception in server.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.serverSocket.close()
