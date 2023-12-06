# Student ID: D1166506
# Name: 周嘉禾
import socket
import struct
import threading
from time import sleep
from PyQt6.QtCore import pyqtSignal, QThread
from . import message


class Client(QThread):
    client_signal = pyqtSignal(str)

    def __init__(self, group_ip, group_port):
        super().__init__()
        self.group_ip = group_ip
        self.group_port = group_port
        self.group = (group_ip, group_port)
        self.buf_size = 1024
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
            self.clientSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self.clientSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
            self.clientSocket.bind(('', self.group_port))
            self.join_group(self.clientSocket, self.group_ip, True)
            self.client_signal.emit(f"[Client] Listening on Multicasting Group {self.group}")
            print(f"[Client] Listening on Multicasting Group {self.group}")
        except Exception as e:
            print(f'[ERROR] Other exception in client.connection: {e}, line ', e.__traceback__.tb_lineno)

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
            print(f'[ERROR] Other exception in client.join_group: {e}, line ', e.__traceback__.tb_lineno)

    def send(self):
        try:
            while True:
                data = self.receive()
                self.client_signal.emit(f"[Client] Receive: {data}")
        except Exception as e:
            print(f'[ERROR] Other exception in client.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self):
        try:
            data, (rip, rport) = self.clientSocket.recvfrom(self.buf_size)
            data = data.decode('utf-8')
            print(f"\n[Client] Receive {data} from IP: {str(rip)}, port: {str(rport)}")
            return data
        except socket.timeout:
            print("[ERROR] Server receive timeout.")
        except Exception as e:
            print(f'[ERROR] Other exception in client.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.borderRouterSocket.close()
