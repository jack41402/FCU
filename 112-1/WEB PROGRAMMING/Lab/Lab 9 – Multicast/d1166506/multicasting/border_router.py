# Student ID: D1166506
# Name: 周嘉禾
import socket
import struct
import threading
from time import sleep
from PyQt6.QtCore import pyqtSignal, QThread
from . import message


class BorderRouter(QThread):
    border_router_signal = pyqtSignal(str)

    def __init__(self, group_ip, group_port):
        super().__init__()
        self.group_ip = group_ip
        self.group_port = group_port
        self.group = (group_ip, group_port)
        self.ip = '127.0.0.1'
        self.port = 7777
        self.backlog = 5
        self.buf_size = 1024
        self.ttl = struct.pack('b', 1)
        self.borderRouterSocket = None
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
            # listen to multicasting group
            self.borderRouterSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self.borderRouterSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
            self.borderRouterSocket.bind(('', self.group_port))
            self.join_group(self.borderRouterSocket, self.group_ip, True)
            self.border_router_signal.emit(f"[Border Router] Listening on Multicasting Group {self.group}")
            print(f"[Border Router] Listening on Multicasting Group {self.group}")

            # create tcp server
            self.serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.serverSocket.bind((self.ip, self.port))  # Choose any available port
            self.serverSocket.listen(self.backlog)
            self.border_router_signal.emit(f"[Border Router] Starting up TCP Server on {self.port}")
            print(f"[Border Router] Starting up TCP Server on {self.port}")
            self.border_router_signal.emit("[Border Router] Waiting for connection...")

            # accept connection
            self.clientSocket, (self.rip, self.rport) = self.serverSocket.accept()
            self.border_router_signal.emit(f"[Border Router] Accept connection from {(self.rip, self.rport)}")
            print(f"[Border Router] Accept connection from {(self.rip, self.rport)}")
        except Exception as e:
            print(f'[ERROR] Other exception in border_router.connection: {e}, line ', e.__traceback__.tb_lineno)

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
            print(f'[ERROR] Other exception in border_router.join_group: {e}, line ', e.__traceback__.tb_lineno)

    def send(self):
        try:
            while True:
                data = self.receive()
                self.border_router_signal.emit(f"[Border Router] Receive: {data}")
                self.clientSocket.send(str(data).encode('utf-8'))
                self.border_router_signal.emit(f"[Border Router] Send: {data}")
        except Exception as e:
            print(f'[ERROR] Other exception in border_router.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            data, (rip, rport) = self.borderRouterSocket.recvfrom(self.buf_size)
            data = data.decode('utf-8')
            print(f"\n[Border Router] Receive {data} from IP: {str(rip)}, port: {str(rport)}")
            return data
        except socket.timeout:
            print("[ERROR] Server receive timeout.")
        except Exception as e:
            print(f'[ERROR] Other exception in border_router.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.borderRouterSocket.close()
