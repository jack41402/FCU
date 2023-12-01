# Student ID: D1166506
# Name: 周嘉禾
import socket
import threading
import time

from PyQt6.QtCore import pyqtSignal, QThread
from . import message
import select


class Consumer(QThread):
    consumer_signal = pyqtSignal(str)

    def __init__(self, ip, consumer_port, index):
        super().__init__()
        self.ip = ip
        self.consumer_port = consumer_port
        self.buf_size = 1024
        self.lock = threading.Lock()
        self.consumer = None
        self.timeout_thread = threading.Thread(target=self.timeout)
        self.input = []
        self.output = []
        self.index = index
        self.enable = 0

    def run(self):
        try:
            if self.consumer is None:
                self.connection()
                self.input.append(self.consumer)
        except Exception as e:
            print(f'[ERROR] Other exception in consumer.run: {e}, line ', e.__traceback__.tb_lineno)

    def consume(self):
        try:
            self.send("CON")
            self.enable += 1
            self.consumer_signal.emit("[CONSUMER] Send: \"CON\"")
            while True:
                print("[INFO] Try to fetch message.\n")
                try:
                    readable, writable, exceptional = select.select(self.input, self.output, self.input, 2)
                except select.error as e:
                    print(f'[ERROR] Catch select.error in consumer.select: {e}, line ', e.__traceback__.tb_lineno)
                    break
                except Exception as e:
                    print(f'[ERROR] Other exception in consumer.select: {e}, line ', e.__traceback__.tb_lineno)
                    continue
                if not (readable or writable or exceptional):
                    self.enable += 1
                    if not self.timeout_thread.is_alive():
                        self.timeout_thread.start()
                else:
                    self.enable -= 1
                    print("Enable: ", self.enable)
                for s in readable:
                    try:
                        data = self.receive(s)
                        msg_type = data[0]
                        print(data)
                        if data:
                            if msg_type == "SRV":
                                self.consumer_signal.emit("[CONSUMER] Receive: %d" % data[1])
                                return data[1]
                            else:
                                print("[ERROR] Unexpected message type.")
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
        except Exception as e:
            print(f'[ERROR] Other exception in consumer.pull: {e}, line ', e.__traceback__.tb_lineno)

    def timeout(self):
        while self.enable:
            print("[INFO] Timeout without fetching message.\n")
            self.consumer_signal.emit("[CONSUMER] TIMEOUT. Waiting for data...")
            time.sleep(2)

    def connection(self):
        try:
            self.consumer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.consumer.connect((self.ip, self.consumer_port))
            self.consumer.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
            self.consumer_signal.emit("[CONSUMER] Connected successfully.")
        except Exception as e:
            print(f'[ERROR] Other exception in consumer.connection: {e}, line ', e.__traceback__.tb_lineno)

    def send(self, msg: str):
        try:
            message.send_msg(self.consumer, str(msg))
            return True
        except Exception as e:
            print(f'[ERROR] Other exception in consumer.send: {e}, line ', e.__traceback__.tb_lineno)

    def receive(self, client):
        try:
            raddr = client.getpeername()
            laddr = client.getsockname()
            data = message.receive_msg(client)
            msg = "\nReceive message on :" + str(laddr) + " from : " + str(raddr)
            print(msg)
            return data
        except Exception as e:
            print(f'[ERROR] Other exception in consumer.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.consumer.close()
