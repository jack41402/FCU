# Student ID: D1166506
# Name: 周嘉禾
import os.path
import socket
from PyQt6.QtCore import pyqtSignal, QThread
from . import message
import ssl

SERVER_CERT = r".\openssl\server.pem"
SERVER_KEY = r".\openssl\server.key"


class Client(QThread):
    client_signal = pyqtSignal(str)

    def __init__(self, ip, port, number):
        super().__init__()
        self.ip = ip
        self.port = port
        self.buf_size = 1024
        self.number = number
        self.clientSocket = None
        self.client_ssl = None

    def run(self):
        try:
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
            self.close()
        except Exception as e:
            print(f'[ERROR] Other exception in client.run: {e}, line ', e.__traceback__.tb_lineno)

    def connection(self):
        try:
            # Get path of certificate and key
            CLIENT_CERT = r".\openssl\client.pem"
            CLIENT_KEY = r".\openssl\client.key"

            # Verify server Certificate
            print(os.getcwd())
            ctx = ssl.create_default_context(ssl.Purpose.SERVER_AUTH, cafile=SERVER_CERT)
            ctx.load_cert_chain(certfile=CLIENT_CERT, keyfile=CLIENT_KEY)

            # Create a TCP client socket
            self.clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

            # Wrap socket
            self.client_ssl = ctx.wrap_socket(self.clientSocket, server_side=False, server_hostname=self.ip)
            self.client_signal.emit("[CLIENT] Wrap ssl client socket successfully.")

            print("Connecting to %s port %s" % (self.ip, self.port))
            self.client_ssl.connect((self.ip, self.port))
            self.client_signal.emit("[CLIENT] Connected successfully.")
        except Exception as e:
            print(f'[ERROR] Other exception in client.connection: {e}, line ', e.__traceback__.tb_lineno)

    def send(self, msg: str):
        try:
            message.send_msg(self.client_ssl, str(msg))
            return True
        except Exception as e:
            print(f'[ERROR] Other exception in client.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            msg = "Receive message from IP: " + str(self.ip) + " port: " + str(self.port)
            print(msg)
            server_msg = message.receive_msg(self.client_ssl)
            return server_msg
        except Exception as e:
            print(f'[ERROR] Other exception in client.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        try:
            self.client_ssl.close()
        except Exception as e:
            print(f'[ERROR] Other exception in client.close: {e}, line ', e.__traceback__.tb_lineno)
