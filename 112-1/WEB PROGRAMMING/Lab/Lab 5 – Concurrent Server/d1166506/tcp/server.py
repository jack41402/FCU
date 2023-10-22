# Student ID: D1166506
# Name: 周嘉禾
import socket
import threading
from PyQt6.QtCore import pyqtSignal, QThread, QMutex, QMutexLocker
from . import message


class Server(QThread):
    server_signal = pyqtSignal(str)

    def __init__(self, ip, port):
        super().__init__()
        self.ip = ip
        self.port = port
        self.backlog = 5
        self.buf_size = 1024
        self.number = None
        self.serverSocket = None
        self.client = None
        self.rip = None
        self.rport = None
        self.lock = QMutex()

    def run(self):
        try:
            self.connection()
            with QMutexLocker(self.lock):
                print("Inside!!!")
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
        except Exception as e:
            print(f'[ERROR] Other exception in server.run: {e}, line ', e.__traceback__.tb_lineno)

    def connection(self):
        try:
            with QMutexLocker(self.lock):
                self.serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                self.serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
                print("Starting up server on port: %s\n" % self.port)
                self.serverSocket.bind(('', self.port))
                self.serverSocket.listen(self.backlog)
                print("Waiting to receive message from client\n")
                self.client, (self.rip, self.rport) = self.serverSocket.accept()
                self.server_signal.emit("[SERVER] Waiting for connection...")
        except Exception as e:
            print(f'[ERROR] Other exception in server.connection: {e}, line ', e.__traceback__.tb_lineno)

    def send(self, msg: str):
        try:
            message.send_msg(self.client, str(msg))
            return True
        except Exception as e:
            print(f'[ERROR] Other exception in server.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            num = message.receive_msg(self.client)
            msg = "\nReceive message from IP: " + str(self.rip) + " port: " + str(self.rport)
            print(msg)
            return num
        except Exception as e:
            print(f'[ERROR] Other exception in server.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.client.close()
        self.serverSocket.close()
