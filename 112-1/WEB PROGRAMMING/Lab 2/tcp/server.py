import socket
import struct
import binascii
from PyQt6.QtCore import pyqtSignal
from . import message


class Server:
    server_signal = pyqtSignal(str)
    def __init__(self, ip, port):
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

    def connection(self):
        self.serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
        print("Starting up server on port: %s" % self.port)
        self.serverSocket.bind(('', self.port))
        self.serverSocket.listen(self.backlog)
        print("Waiting to receive message from client\n")
        self.client, (self.rip, self.rport) = self.serverSocket.accept()
        #self.server_signal.emit("Can you read me ?")


    def send(self):
        if self.number - 1 != 0:
            self.number -= 1
            message.send_msg(self.client, str(self.number))
        else:
            print("\n**** The number is zero. Closing the connection.\n")
            message.send_msg(self.client, "END")
            return 0

    def receive(self):
        num = message.receive_msg(self.client)
        msg = "\nReceive message from IP: " + str(self.rip) + " port: " + str(self.rport)
        print(msg)
        if num == 0:
            print("Receive END message. Closing the connection.")
            return 0

    def close(self):
        self.client.close()
        self.serverSocket.close()
