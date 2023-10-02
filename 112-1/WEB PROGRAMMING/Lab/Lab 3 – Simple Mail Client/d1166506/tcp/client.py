# Student ID: D1166506
# Name: 周嘉禾
import socket
from PyQt6.QtCore import pyqtSignal, QThread
import message


class Client(QThread):
    client_signal = pyqtSignal(str)

    def __init__(self, ip="10.0.1.3", port, number):
        super().__init__()
        self.ip = ip
        self.port = port
        self.buf_size = 1024
        self.number = number
        self.clientSocket = None

    def run(self):
        self.connection()
        while True:
            if self.number - 1 == 0:
                print("\n**** The number is zero. Closing the connection.\n")
                self.client_signal.emit("[CLIENT] The number is zero. Closing the connection.")
                self.send("END")
                self.client_signal.emit("[CLIENT] Send: \"END\" message.")
                break
            else:
                self.number -= 1
                self.send(str(self.number))
                self.client_signal.emit("[CLIENT] Send: %d" % self.number)
            server_msg = self.receive()
            if server_msg == 0:
                print("Receive END message. Closing the connection.")
                self.client_signal.emit("[CLIENT] Receive: \"END\" message.")
                self.client_signal.emit("[CLIENT] Closing the connection.")
                break
            else:
                self.number = server_msg
                self.client_signal.emit("[CLIENT] Receive: %d" % server_msg)

    def connection(self):
        self.clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print("Connecting to %s port %s" % (self.ip, self.port))
        self.clientSocket.connect((self.ip, self.port))
        self.receive()
        self.client_signal.emit("[CLIENT] Connected successfully.")

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
