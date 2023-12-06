# Student ID: D1166506
# Name: 周嘉禾
import socket
import threading
from PyQt6.QtCore import pyqtSignal, QThread
from . import message
import select

BUF_SIZE = 1024


class Producer(QThread):
    producer_signal = pyqtSignal(str)

    def __init__(self, ip, producer_port, index):
        super().__init__()
        self.ip = ip
        self.producer_port = producer_port
        self.buf_size = 1024
        self.lock = threading.Lock()
        self.producer = None
        self.input = []
        self.output = []
        self.index = index

    def run(self):
        try:
            if self.producer is None:
                self.connection()
                self.input.append(self.producer)
        except Exception as e:
            print(f'[ERROR] Other exception in producer.run: {e}, line ', e.__traceback__.tb_lineno)

    def produce(self, num):
        try:
            with self.lock:
                self.send(num)
                self.producer_signal.emit("[PRODUCER] Send: %d" % num)
                error = False
                while True:
                    print("[INFO] Try to fetch message.\n")
                    try:
                        readable, writable, exceptional = select.select(self.input, self.output, self.input, 1)
                    except select.error as e:
                        print(f'[ERROR] Catch select.error in producer.select: {e}, line ', e.__traceback__.tb_lineno)
                        break
                    except Exception as e:
                        print(f'[ERROR] Other exception in producer.select: {e}, line ', e.__traceback__.tb_lineno)
                        break
                    if not (readable or writable or exceptional):
                        print("[INFO] Send message successfully. Timeout without fetching message.\n")
                        self.producer_signal.emit("[PRODUCER] Send number successfully.")
                        break
                    for s in readable:
                        try:
                            data = self.receive(s)
                            msg_type = data[0]
                            if data:
                                if msg_type == "ERR":
                                    print("[ERROR] Server queue is full.")
                                    self.producer_signal.emit("[PRODUCER] ERROR. Server queue is full.")
                                    error = True
                                    break
                                else:
                                    print("[ERROR] Unexpected message type.")
                                    break
                            else:
                                # Close connection
                                print("[INFO] Close connection from: ", s.getpeername())
                                if s in self.output:
                                    self.output.remove(s)
                                self.input.remove(s)
                                s.close()
                        except ConnectionResetError:
                            print("[ERROR] Connection reset by peer")
                            pass
                    # end for readable

                    for s in exceptional:
                        print("[ERROR] Close : ", s)
                        self.input.remove(s)
                        s.close()

                    if error:
                        break
        except Exception as e:
            print(f'[ERROR] Other exception in producer.push: {e}, line ', e.__traceback__.tb_lineno)

    def connection(self):
        try:
            self.producer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            print("Connecting to %s port %s\n" % (self.ip, self.producer))
            print(self.ip)
            print(self.producer_port)
            self.producer.connect((self.ip, self.producer_port))
            self.producer.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
            self.producer_signal.emit("[PRODUCER] Connected successfully.")
        except Exception as e:
            print(f'[ERROR] Other exception in producer.connection: {e}, line ', e.__traceback__.tb_lineno)

    def send(self, msg: str):
        try:
            msg = str(msg)
            if msg.isdigit():
                self.producer.send(f"PRO {msg}".encode('utf-8'))
            # message.send_msg(self.producer, str(msg))
            return True
        except Exception as e:
            print(f'[ERROR] Other exception in producer.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self, client):
        try:
            raddr = client.getpeername()
            laddr = client.getsockname()
            # data = message.receive_msg(client)
            msg = "\nReceive message on :" + str(laddr) + " from : " + str(raddr)
            print(msg)
            data = client.recv(self.buf_size)
            if data:
                data = data.decode('utf-8').split(' ')
                if data[0] == "ERR":
                    return data
            else:
                return False
        except Exception as e:
            print(f'[ERROR] Other exception in producer.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.producer.close()
