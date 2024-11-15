import socket
import threading
from PyQt6.QtCore import pyqtSignal, QThread
from . import message


class Server(QThread):
    server_signal = pyqtSignal(int, str)

    def __init__(self, ip, port):
        super().__init__()
        self.serverSocket = None
        self.client = None
        self.ip = ip
        self.port = port
        self.backlog = 15
        self.buf_size = 1024
        self.lock = threading.Lock()
        self.client_index = None
        self.startup()

    def counter(self):
        try:
            with self.lock:
                self.connection()
                self.client_index = self.receive()
                print("Client index: ", self.client_index)

                while True:
                    number = self.receive()
                    if number == 0:
                        print("Receive END message. Closing the connection.")
                        self.server_signal.emit(self.client_index, "[SERVER] Receive: \"END\" message.")
                        self.server_signal.emit(self.client_index, "[SERVER] Closing the connection.")
                        break
                    if number - 1 != 0:
                        number -= 1
                        self.send(str(number))
                        self.server_signal.emit(self.client_index, "[SERVER] Send: %d" % number)
                    else:
                        print("\n**** The number is zero. Closing the connection.\n")
                        self.server_signal.emit(self.client_index, "[SERVER] The number is zero. Closing the connection.")
                        self.send("END")
                        self.server_signal.emit(self.client_index, "[SERVER] Send: \"END\" message.")
                        break
                self.client.close()
        except Exception as e:
            print(f'[ERROR] Other exception in server.run: {e}, line ', e.__traceback__.tb_lineno)

    def startup(self):
        try:
            self.serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
            print("Starting up server on port: %s\n" % self.port)
            self.serverSocket.bind(('', self.port))
            self.serverSocket.listen(self.backlog)
            # self.serverSocket.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
            print("Waiting to receive message from client\n")
        except Exception as e:
            print(f'[ERROR] Other exception in server.startup: {e}, line ', e.__traceback__.tb_lineno)

    def connection(self):
        try:
            self.client, (self.rip, self.rport) = self.serverSocket.accept()
        except Exception as e:
            print(f'[ERROR] Other exception in server.connection: {e}, line ', e.__traceback__.tb_lineno)

    def send(self, msg: str):
        try:
            message.send_msg(self.client, str(msg))
            return True
        except Exception as e:
            print(f'[ERROR] Other exception in server.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            num = message.receive_msg(self.client)
            msg = "\nReceive message from IP: " + str(self.rip) + " port: " + str(self.rport)
            print(msg)
            return num
        except Exception as e:
            print(f'[ERROR] Other exception in server.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.serverSocket.close()


class Thread(threading.Thread):
    def __init__(self, t, *args):
        threading.Thread.__init__(self, target=t, args=args)
        self.start()
