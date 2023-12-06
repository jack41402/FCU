import socket
import threading
from PyQt6.QtCore import pyqtSignal, QThread
from . import message
import select
import queue

BUF_SIZE = 1024


class Server(QThread):
    server_signal = pyqtSignal(str)

    def __init__(self, ip, producer_port, consumer_port):
        super().__init__()
        self.serverSocket = None
        self.client = None
        self.client_index = None
        self.ip = ip
        self.producer_port = producer_port
        self.consumer_port = consumer_port
        self.backlog = 15
        self.buf_size = 1024
        self.server_list = []
        self.input = []
        self.output = []
        self.queue = queue.Queue(maxsize=5)
        self.request = queue.Queue()
        self.lock = threading.Lock()
        self.thread = threading.Thread(target=self.connection)
        self.startup()

    def startup(self):
        try:
            producer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            producer.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
            print("Starting up producer server on port: %s\n" % self.producer_port)
            self.server_signal.emit("[SERVER] Starting up producer server on port: %s\n" % self.producer_port)
            producer.bind(('', self.producer_port))
            producer.setblocking(False)
            producer.listen(self.backlog)
            self.input.append(producer)
            self.server_list.append(producer)

            consumer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            consumer.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
            print("Starting up consumer server on port: %s\n" % self.consumer_port)
            self.server_signal.emit("[SERVER] Starting up consumer server on port: %s\n" % self.consumer_port)
            consumer.bind(('', self.consumer_port))
            consumer.setblocking(False)
            consumer.listen(self.backlog)
            self.input.append(consumer)
            self.server_list.append(consumer)

            self.thread.start()
            print("Waiting to receive message from client\n")
            self.server_signal.emit("[SERVER] Waiting to receive message from client\n")
        except Exception as e:
            print(f'[ERROR] Other exception in server.startup: {e}, line ', e.__traceback__.tb_lineno)

    def connection(self):
        try:
            with self.lock:
                while True:
                    readable, writable, exceptional = select.select(self.input, self.output, self.input)
                    print("Readable: ", readable)
                    for s in readable:
                        if s in self.server_list:  # new connection
                            # Accept the incomming connection
                            connection, (rip, rport) = s.accept()
                            # Set the connection non-blocking
                            connection.setblocking(False)
                            # Add connection to inputs (listen message on the connection)
                            self.input.append(connection)
                            laddr = connection.getsockname()
                            msg = "Accept connection on port: %d from (%s, %d)" % (laddr[1], str(rip), rport)
                            print(msg)
                            self.server_signal.emit("[SERVER] Accept connection on port: %d from (%s, %d)" % (laddr[1], str(rip), rport))
                        else:  # receive data
                            try:
                                data = self.receive(s)
                                print("Data received: ", data)
                                msg_type = data[0]
                                if data:
                                    if msg_type == "PRO":
                                        print(f"[SERVER] Received producer request from {s.getpeername()}")
                                        self.server_signal.emit(f"[SERVER] Received producer request from {s.getpeername()}")
                                        if self.queue.full():
                                            print("[SERVER] Queue is full. Return ERROR.")
                                            self.server_signal.emit("[SERVER] Queue is full. Return ERROR.")
                                            self.send(s, "ERR")
                                        else:
                                            self.server_signal.emit("[SERVER] Put %d into queue" % data[1])
                                            self.queue.put(data[1])
                                        if not self.request.empty():
                                            consumer = self.request.get()
                                            num = self.queue.get()
                                            self.server_signal.emit(f"[SERVER] Send {num} to former request from {consumer.getpeername()}")
                                            self.send(consumer, num)
                                    elif msg_type == "CON":
                                        self.server_signal.emit(f"[SERVER] Received consumer request from {s.getpeername()}")
                                        if self.queue.empty():
                                            self.server_signal.emit(f"[SERVER] Queue is empty. Pending request.")
                                            self.request.put(s)
                                        else:
                                            num = self.queue.get()
                                            self.server_signal.emit(f"[SERVER] Get {num} from queue.")
                                            self.server_signal.emit(f"[SERVER] Send {num} to {s.getpeername()}")
                                            self.send(s, num)
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
            print(f'[ERROR] Other exception in server.connection: {e}, line ', e.__traceback__.tb_lineno)

    def send(self, client, msg: str):
        try:
            msg = str(msg)
            if msg.isdigit():
                client.send(f"SRV {msg}".encode('utf-8'))
            else:
                client.send(msg.encode('utf-8'))
            # message.send_msg(client, str(msg), server=True)
            return True
        except Exception as e:
            print(f'[ERROR] Other exception in server.send: {e}, line ', e.__traceback__.tb_lineno)

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
                if len(data) == 2:
                    data = (data[0], int(data[1]))
            else:
                return False
            return data
        except Exception as e:
            print(f'[ERROR] Other exception in server.receive: {e}, line ', e.__traceback__.tb_lineno)

    def close(self):
        self.serverSocket.close()


class Thread(threading.Thread):
    def __init__(self, t, *args):
        threading.Thread.__init__(self, target=t, args=args)
        self.start()
