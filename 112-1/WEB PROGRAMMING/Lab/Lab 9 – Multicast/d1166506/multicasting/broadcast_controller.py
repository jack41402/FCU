# Student ID: D1166506
# Name: 周嘉禾
import socket
import struct
import threading
from time import sleep
from PyQt6.QtCore import pyqtSignal, QThread
from . import message


class BroadcastController(QThread):
    broadcast_controller_signal = pyqtSignal(str)

    def __init__(self, group_ip='225.6.7.8', group_port=6666):
        super().__init__()
        self.group_ip = group_ip
        self.group_port = group_port
        self.group = (group_ip, group_port)
        self.ip = '127.0.0.1'
        self.port = 7777
        self.backlog = 5
        self.buf_size = 1024
        self.ttl = struct.pack('b', 1)
        self.broadcastControllerSocket = None
        self.serverSocket = None
        self.clientSocket = None
        self.rip = None
        self.rport = None
        self.send_thread = threading.Thread(target=self.send)

    def run(self):
        self.connection()
        self.send_thread.start()

    def connection(self):
        try:
            # create multicasting group
            self.broadcastControllerSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self.broadcastControllerSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
            self.broadcastControllerSocket.settimeout(0.2)
            self.broadcastControllerSocket.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, self.ttl)
            self.broadcast_controller_signal.emit(f"[Broadcast Controller] Starting up Multicasting Group Server on {self.group}")
            print(f"[Broadcast Controller] Starting up Multicasting Group Server on {self.group}")

            # connect to tcp server
            self.clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            print(f"[Broadcast Controller] Connecting to {self.ip, self.port}")
            self.clientSocket.connect((self.ip, self.port))
            self.broadcast_controller_signal.emit("[Broadcast Controller] Connected successfully.")
        except Exception as e:
            print(f'[ERROR] Other exception in broadcast_controller.connection: {e}, line ', e.__traceback__.tb_lineno)

    def join_group(self, s, group_addr, flag):
        # flag = True (join) / False (leave)
        # Join the multicast group, a socket can join multiple multicast group
        # Join the multicast group by using setsockopt() to change the IP_ADD_MEMBERSHIP option
        # Leave the multicast group by using setsockopt() to change the IP_DROP_MEMBERSHIP option
        # Convert an IPv4 address from dotted-quad string format to 32-bit packed binary format, as a bytes object four characters in length.
        try:
            group = socket.inet_aton(group_addr)
            mreq = struct.pack('4sL', group, socket.INADDR_ANY)
            if flag:
                cmd = socket.IP_ADD_MEMBERSHIP
            else:
                cmd = socket.IP_DROP_MEMBERSHIP

            s.setsockopt(socket.IPPROTO_IP, cmd, mreq)
        except Exception as e:
            print(f'[ERROR] Other exception in broadcast_controller.join_group: {e}, line ', e.__traceback__.tb_lineno)

    def send(self):
        try:
            while True:
                data = self.receive()
                self.broadcast_controller_signal.emit(f"[Broadcast Controller] Receive: {data}")
                self.broadcastControllerSocket.sendto(str(data).encode('utf-8'), self.group)
                self.broadcast_controller_signal.emit(f"[Broadcast Controller] Send: {data}")
        except Exception as e:
            print(f'[ERROR] Other exception in broadcast_controller.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            data = self.clientSocket.recv(self.buf_size)
            data = data.decode('utf-8')
            print(f"\n[Broadcast Controller] Receive {data} from IP: {str(self.ip)}, port: {str(self.port)}")
            return data
        except socket.timeout:
            print("[ERROR] Server receive timeout.")
        except Exception as e:
            print(f'[ERROR] Other exception in broadcast_controller.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.broadcastControllerSocket.close()
