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
        self.timeout = 0.01

    def run(self):
        try:
            self.connection()
            self.serverSocket.settimeout(self.timeout)
            while True:
                try:
                    number = self.receive()
                except socket.timeout:
                    self.server_signal.emit("[SERVER] Timeout. Retransmitting message: %d..." % number)
                    continue
                if number == 0:
                    print("Receive END message. Closing the connection.")
                    self.server_signal.emit("[SERVER] Receive: \"END\" message.")
                    self.server_signal.emit("[SERVER] Closing the connection.")
                    break
                if number - 1 != 0 and number != self.number:
                    self.server_signal.emit("[SERVER] Receive: %d" % number)
                    number -= 1
                    self.number = number
                    self.send(str(number))
                    self.server_signal.emit("[SERVER] Send: %d" % number)
                elif number - 1 == 0 and number != self.number:
                    print("\n**** The number is zero. Closing the connection.\n")
                    self.server_signal.emit("[SERVER] The number is zero. Closing the connection.")
                    self.send("END")
                    self.server_signal.emit("[SERVER] Send: \"END\" message.")
                    break
                else:
                    continue
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
            message.send_msg(self.serverSocket, str(msg), (self.rip, self.rport))
            return True
        except Exception as e:
            print(f'[ERROR] Other exception in server.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            client_msg, (self.rip, self.rport) = message.receive_msg(self.serverSocket)
            msg = "Receive message from IP: " + str(self.rip) + " port: " + str(self.rport)
            print(msg)
            return client_msg
        except socket.timeout:
            raise TimeoutError("Receive operation timed out in server.receive")
        except Exception as e:
            print(f'[ERROR] Other exception in server.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.serverSocket.close()
