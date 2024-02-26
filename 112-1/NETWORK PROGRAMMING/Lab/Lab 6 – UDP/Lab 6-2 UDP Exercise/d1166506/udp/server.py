# Student ID: D1166506
# Name: 周嘉禾
import socket
import time
from PyQt6.QtCore import pyqtSignal, QThread
from . import message


class Server(QThread):
    server_signal = pyqtSignal(str)

    def __init__(self, ip, port, SlidingWindow):
        super().__init__()
        self.ip = ip
        self.port = port
        self.buf_size = 1024
        self.number = None
        self.serverSocket = None
        self.rip = None
        self.rport = None
        self.SlidingWindow = SlidingWindow
        self.receive_msg = []

    def run(self):
        try:
            self.connection()
            count = 1
            while not self.isInterruptionRequested():
                number = self.receive()
                self.receive_msg.append("[SERVER] Receive: %d" % number)
                if number is None:
                    continue
                elif self.number is not None and number > self.number:
                    self.clear()
                if number == 0:
                    print("Receive END message. Closing the connection.")
                    for i in range(len(self.receive_msg)):
                        self.server_signal.emit(self.receive_msg[i])
                    self.receive_msg.clear()
                    self.server_signal.emit("[SERVER] Receive: \"END\" message.")
                    self.server_signal.emit("[SERVER] Closing the connection.")
                    break
                elif number - 1 != 0 and number != self.number:
                    if count % self.SlidingWindow == 0:
                        for i in range(len(self.receive_msg)):
                            self.server_signal.emit(self.receive_msg[i])
                        self.receive_msg.clear()
                        if number - 1 != 0:
                            number -= 1
                            self.number = number
                            self.send(str(number))
                            self.server_signal.emit("[SERVER] Send: %d" % number)
                        else:
                            continue
                    count += 1
                elif number - 1 == 0 and number != self.number:
                    print("\n**** The number is zero. Closing the connection.\n")
                    for i in range(len(self.receive_msg)):
                        self.server_signal.emit(self.receive_msg[i])
                    self.receive_msg.clear()
                    self.server_signal.emit("[SERVER] The number is zero. Closing the connection.")
                    self.send("END")
                    self.server_signal.emit("[SERVER] Send: \"END\" message.")
                    break
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

    def clear(self):
        try:
            start_time = time.time()
            self.serverSocket.settimeout(0.5)
            while time.time() - start_time < 0.5:
                self.receive()
            self.serverSocket.settimeout(None)
            time.sleep(0.5)
        except socket.timeout:
            self.serverSocket.settimeout(None)
            time.sleep(0.5)
            print(f'[ERROR] Timeout in server.clear')
        except Exception as e:
            print(f'[ERROR] Other exception in server.clear: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.serverSocket.close()
