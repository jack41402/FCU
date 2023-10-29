# Student ID: D1166506
# Name: 周嘉禾
import socket
from PyQt6.QtCore import pyqtSignal, QThread
from . import message


class Client(QThread):
    client_signal = pyqtSignal(str)

    def __init__(self, ip, port, number):
        super().__init__()
        self.ip = ip
        self.port = port
        self.buf_size = 1024
        self.number = number
        self.timeout = 0.01
        self.clientSocket = None

    def run(self):
        try:
            self.connection()
            self.clientSocket.settimeout(self.timeout)
            number = self.number
            is_receive = True
            while True:
                if not is_receive:
                    self.send(str(number))
                elif number - 1 == 0:
                    print("\n**** The number is zero. Closing the connection.\n")
                    self.client_signal.emit("[CLIENT] The number is zero. Closing the connection.")
                    self.send("END")
                    self.client_signal.emit("[CLIENT] Send: \"END\" message.")
                    break
                elif number - 1 != 0:
                    number -= 1
                    self.send(str(number))
                    self.client_signal.emit("[CLIENT] Send: %d" % number)
                try:
                    server_msg = self.receive()
                    print("RECEIVED!!!")
                    is_receive = True
                except socket.timeout:
                    print("TIMEOUT!!!")
                    self.client_signal.emit("[CLIENT] Timeout. Retransmitting message: %d..." % number)
                    is_receive = False
                    continue
                if server_msg == 0:
                    print("Receive END message. Closing the connection.")
                    self.client_signal.emit("[CLIENT] Receive: \"END\" message.")
                    self.client_signal.emit("[CLIENT] Closing the connection.")
                    break
                elif server_msg != 0 and server_msg is not None:
                    number = server_msg
                    self.client_signal.emit("[CLIENT] Receive: %d" % server_msg)
        except Exception as e:
            print(f'[ERROR] Other exception in client.run: {e}, line ', e.__traceback__.tb_lineno)

    def connection(self):
        try:
            self.clientSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            print("Connecting to %s port %s" % (self.ip, self.port))
        except Exception as e:
            print(f'[ERROR] Other exception in client.connection: {e}, line ', e.__traceback__.tb_lineno)

    def send(self, msg: str):
        try:
            message.send_msg(self.clientSocket, str(msg), (self.ip, self.port))
            return True
        except Exception as e:
            print(f'[ERROR] Other exception in client.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            server_msg, (rip, rport) = message.receive_msg(self.clientSocket)
            msg = "Receive message from IP: " + str(rip) + " port: " + str(rport)
            print(msg)
            return server_msg
        except socket.timeout:
            raise TimeoutError("Receive operation timed out in client.receive")
        except Exception as e:
            print(f'[ERROR] Other exception in client.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.clientSocket.close()
