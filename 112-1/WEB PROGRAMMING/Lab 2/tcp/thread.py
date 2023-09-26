import time
from PyQt6 import QtCore, QtGui, QtWidgets
from PyQt6.QtCore import QThread, pyqtSignal
from . import server


class ServerThread(QThread):
    server_started = pyqtSignal()
    server_stopped = pyqtSignal()

    def __init__(self, server):
        super().__init__()
        self.server = server
        # self.signal =

    def run(self):
        self.server.run()
        time.sleep(200)
        # ServerThread.server_started.emit()

        # self.server.close()
        # self.server_stopped.emit()


class ClientThread(QThread):
    client_started = pyqtSignal()
    client_stopped = pyqtSignal()

    def __init__(self, client):
        super().__init__()
        self.client = client

    def run(self):
        self.client.run()
        # self.client_started.emit()

        # self.client.close()
        # self.client_stopped.emit()
class MyReceiver:
    def handle_signal(self):
        print("Signal received!")
