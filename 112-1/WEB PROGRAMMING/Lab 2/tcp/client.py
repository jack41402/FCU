import sys
import socket
import struct
import binascii
from PyQt6 import *
from . import message


class Client:
    def __init__(self, ip, port, number):
        self.ip = ip
        self.port = port
        self.buf_size = 1024
        self.number = number
        self.clientSocket = None

    def run(self):
        self.connection()

    def connection(self):
        self.clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print("Connecting to %s port %s" % (self.ip, self.port))
        self.clientSocket.connect((self.ip, self.port))
        print("I am connected")

    def send(self):
        if self.number - 1 == 0:
            print("\n**** The number is zero. Closing the connection.\n")
            message.send_msg(self.clientSocket, "END")
        else:
            self.number -= 1
            message.send_msg(self.clientSocket, str(self.number))

    def receive(self):
        msg = "Receive message from IP: " + str(self.ip) + " port: " + str(self.port)
        print(msg)
        server_msg = message.receive_msg(self.clientSocket)
        if server_msg == 0:
            print("Receive END message. Closing the connection.")
            return 0
        else:
            num = server_msg

    def close(self):
        self.clientSocket.close()
