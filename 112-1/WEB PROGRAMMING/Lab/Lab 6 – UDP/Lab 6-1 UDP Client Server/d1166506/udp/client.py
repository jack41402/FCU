# Student ID: D1166506
# Name: 周嘉禾
import socket
import time
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
            while not self.isInterruptionRequested():
                if number - 1 == 0 and is_receive:
                    print("\n**** The number is zero. Closing the connection.\n")
                    self.client_signal.emit("[CLIENT] The number is zero. Closing the connection.")
                    self.send("END")
                    self.client_signal.emit("[CLIENT] Send: \"END\" message.")
                    break
                elif number - 1 != 0 and is_receive:
                    number -= 1
                    self.send(str(number))
                    self.client_signal.emit("[CLIENT] Send: %d" % number)
                try:
                    server_msg = self.receive()
                except socket.timeout:
                    number = self.number
                    self.send(str(number))
                    self.client_signal.emit("[CLIENT] Timeout. Retransmitting message: %d..." % number)
                    self.clear()
                    is_receive = False
                    continue
                if server_msg == 0:
                    print("Receive END message. Closing the connection.")
                    self.client_signal.emit("[CLIENT] Receive: \"END\" message.")
                    self.client_signal.emit("[CLIENT] Closing the connection.")
                    break
                elif server_msg is None or server_msg > number:
                    is_receive = False
                    continue
                elif server_msg != 0 and server_msg is not None:
                    number = server_msg
                    self.client_signal.emit("[CLIENT] Receive: %d" % server_msg)
                    is_receive = True
            self.close()
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

    def clear(self):
        try:
            self.clientSocket.settimeout(0.5)
            start_time = time.time()
            while time.time() - start_time < 0.5:
                self.receive()
            self.clientSocket.settimeout(self.timeout)
            time.sleep(0.5)
        except socket.timeout:
            self.clientSocket.settimeout(self.timeout)
            time.sleep(0.5)
            print(f'[ERROR] Timeout in client.clear')
        except Exception as e:
            print(f'[ERROR] Other exception in client.clear: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.clientSocket.close()

