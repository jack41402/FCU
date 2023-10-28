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
        self.backlog = 5
        self.buf_size = 1024
        self.number = None
        self.serverSocket = None
        self.client = None
        self.rip = None
        self.rport = None

    def run(self):
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

    def connection(self):
        self.serverSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        print("Starting up server on port: %s" % self.port)
        self.serverSocket.bind(('', self.port))
        self.server_signal.emit("[SERVER] Waiting for connection...")

    def send(self, msg: str):
        message.send_msg(self.client, str(msg))
        return True

    def receive(self):
        num = message.receive_msg(self.client)
        msg = "\nReceive message from IP: " + str(self.rip) + " port: " + str(self.rport)
        print(msg)
        return num

    def close(self):
        self.client.close()
        self.serverSocket.close()
