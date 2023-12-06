# Student ID: D1166506
# Name: 周嘉禾
import socket
import struct
import threading
from time import sleep

from PyQt6.QtCore import pyqtSignal, QThread
from . import message


class Server(QThread):
    server_signal = pyqtSignal(str)

    def __init__(self, ip, port):
        super().__init__()
        self.ip = ip
        self.port = port
        self.group = (ip, port)
        self.backlog = 5
        self.buf_size = 1024
        self.ttl = struct.pack('b', 1)
        self.serverSocket = None
        self.send_thread = threading.Thread(target=self.send)

    def run(self):
        self.connection()
        sleep(2)
        self.send_thread.start()

    def connection(self):
        self.serverSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
        self.serverSocket.settimeout(0.2)
        self.serverSocket.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, self.ttl)
        self.server_signal.emit(f"[SERVER] Starting up Multicasting Group Server on {self.group}")
        print(f"[SERVER] Starting up Multicasting Group Server on {self.group}")

    def send(self):
        try:
            count = 0
            while True:
                self.serverSocket.sendto(str(count).encode('utf-8'), self.group)
                self.server_signal.emit(f"[Server] Send: {count}")
                print(f"[Server] Send: {count} to {self.group}")
                count += 1
                sleep(2)
        except Exception as e:
            print(f'[ERROR] Other exception in server.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            data, (rip, rport) = self.serverSocket.recvfrom(self.buf_size)
            data = data.decode('utf-8')
            msg = "\nReceive message from IP: " + str(rip) + " port: " + str(rport)
            print(msg)
            self.server_signal.emit(f"[Server] Receive: {data}")
        except socket.timeout:
            print("[ERROR] Server receive timeout.")
        except Exception as e:
            print(f'[ERROR] Other exception in server.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.serverSocket.close()
