# Student ID: D1166506
# Name: 周嘉禾
import socket
from PyQt6.QtCore import pyqtSignal, QThread
from . import message
import ssl

SERVER_CERT = r".\openssl\server.pem"
SERVER_KEY = r".\openssl\server.key"
CLIENT_CERT = r".\openssl\client.pem"
CLIENT_KEY = r".\openssl\client.key"


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
        self.client_ssl = None
        self.client = None
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
            self.serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
            print("Starting up server on port: %s" % self.port)
            self.serverSocket.bind(('', self.port))
            self.serverSocket.listen(self.backlog)
            print("Waiting to receive message from client\n")

            self.client, (self.rip, self.rport) = self.serverSocket.accept()
            self.server_signal.emit("[SERVER] Waiting for connection...")

            # Create  context & Load Certificate
            ctx = ssl.SSLContext(ssl.PROTOCOL_TLSv1_2)
            ctx.verify_mode = ssl.CERT_REQUIRED
            ctx.load_cert_chain(certfile=SERVER_CERT, keyfile=SERVER_KEY)
            ctx.load_verify_locations(cafile=CLIENT_CERT)

            self.client_ssl = ctx.wrap_socket(self.client, server_side=True)
            self.server_signal.emit("[SERVER] SSL established. Peer certificate: ", str(self.client_ssl.getpeercert()))
            self.server_signal.emit("[SERVER] Cipher be used: ", str(self.client_ssl.cipher()))
        except Exception as e:
            print(f'[ERROR] Other exception in server.connection: {e}, line ', e.__traceback__.tb_lineno)

    def send(self, msg: str):
        try:
            message.send_msg(self.client_ssl, str(msg))
            return True
        except Exception as e:
            print(f'[ERROR] Other exception in server.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            num = message.receive_msg(self.client_ssl)
            msg = "\nReceive message from IP: " + str(self.rip) + " port: " + str(self.rport)
            print(msg)
            return num
        except Exception as e:
            print(f'[ERROR] Other exception in server.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        try:
            self.client_ssl.close()
            self.serverSocket.close()
        except Exception as e:
            print(f'[ERROR] Other exception in server.close: {e}, line ', e.__traceback__.tb_lineno)
