import threading
from PyQt6.QtCore import pyqtSignal
from PyQt6.QtWidgets import QWidget, QMainWindow, QTextBrowser, QVBoxLayout
from PyQt6 import uic
from home import Ui_MainWindow
from multicasting import validate, server, border_router, broadcast_controller, client
import sys

MULTICAST_GROUP1 = '225.3.2.1'
MULTICAST_GROUP2 = '225.6.7.8'
PORT = 6666


class MainWindow_controller(QMainWindow):
    def __init__(self):
        super(MainWindow_controller, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.server = None
        self.border_router = None
        self.broadcast_controller = None
        self.client = None
        self.client_list = []
        self.ip = None
        self.port = None
        self.group_ip = None
        self.group_port = None
        self.backlog = 15

        self.setup_control()

    def setup_control(self):
        self.ui.treeWidget.itemClicked.connect(self.display)
        self.ui.btn_Run.clicked.connect(self.RunClicked)
        self.ui.btn_Exit.clicked.connect(self.ExitClicked)
        self.ui.btn_Join.clicked.connect(self.JoinClicked)
        self.ui.btn_Close.clicked.connect(self.CloseClicked)

    def RunClicked(self):
        try:
            msg_IP_Address = self.ui.lineEdit_IP_Address.text()
            msg_Port = self.ui.lineEdit_Port.text()

            self.ip = msg_IP_Address if msg_IP_Address != "" else MULTICAST_GROUP1
            self.port = msg_Port if msg_Port != "" else PORT

            self.start()
        except Exception as e:
            print(f'[ERROR] Other exception in MainWindow_controller.RunClicked: {e}, line ', e.__traceback__.tb_lineno)

    def ExitClicked(self):
        sys.exit(-1)

    def JoinClicked(self):
        msg_IP_Address = self.ui.lineEdit_Multicasting_IP.text()
        msg_Port = self.ui.lineEdit_Multicasting_Port.text()

        self.group_ip = msg_IP_Address if msg_IP_Address != "" else MULTICAST_GROUP2
        self.group_port = msg_Port if msg_Port != "" else 6666
        if not self.client:
            self.client = client.Client(self.group_ip, self.group_port)
            self.client.client_signal.connect(self.updateClient)
            self.client.start()

    def CloseClicked(self):
        self.client.close()

    def start(self):
        try:
            if not self.server:
                self.server = server.Server(self.ip, self.port)
                self.server.server_signal.connect(self.updateServer)
                self.server.start()
            if not self.border_router:
                self.border_router = border_router.BorderRouter(self.ip, self.port)
                self.border_router.border_router_signal.connect(self.updateBorderRouter)
                self.border_router.start()
            if not self.broadcast_controller:
                self.broadcast_controller = broadcast_controller.BroadcastController()
                self.broadcast_controller.broadcast_controller_signal.connect(self.updateBroadcastController)
                self.broadcast_controller.start()
        except Exception as e:
            print(f'[ERROR] Other exception in MainWindow_controller.start: {e}, line ', e.__traceback__.tb_lineno)

    def display(self, item):
        index = self.ui.treeWidget.indexOfTopLevelItem(item)
        self.ui.stackedWidget.setCurrentIndex(index)

    def updateServer(self, msg):
        self.ui.textBrowser_Server.append(msg)

    def updateBorderRouter(self, msg):
        self.ui.textBrowser_Border_Router.append(msg)

    def updateBroadcastController(self, msg):
        self.ui.textBrowser_Broadcast_Controller.append(msg)

    def updateClient(self, msg):
        self.ui.textBrowser_Client.append(msg)

    def closeEvent(self, event):
        if self.server.send_thread.is_alive():
            self.server.send_thread.exit()
        event.accept()

    # def createProducerTab(self):
    #     try:
    #         producerWidget = QWidget()
    #         producerUI = self.producer_ui
    #         producerUI.btn_Produce.clicked.connect(self.push)
    #         producerUI.textBrowser.setProperty("index", 0, "type", "Producer")
    #         self.producer.producer_signal.connect(self.update)
    #         producerUI.setupUi(producerWidget)
    #         self.ui.tabWidget_Producer.addTab(producerWidget, f"Producer {len(self.producer_tab)}")
    #         # self.producer_tab.append(self.ui.tabWidget_Producer)
    #         # self.producer_tab[-1].client_signal.connect(producerUI.textBrowser.updateBrowser())
    #     except Exception as e:
    #         print(f'[ERROR] Other exception in MainWindow_controller.createProducerTab: {e}, line ',
    #               e.__traceback__.tb_lineno)
    #
    # def createConsumerTab(self):
    #     try:
    #         consumerWidget = QWidget()
    #         consumerUI = self.consumer_ui
    #         consumerUI.btn_Consume.clicked.connect(self.pull)
    #         consumerUI.textBrowser.setProperty("index", 0, "type", "Consumer")
    #         self.consumer.consumer_signal.connect(self.update)
    #         consumerUI.setupUi(consumerWidget)
    #         self.ui.tabWidget_Consumer.addTab(consumerWidget, f"Consumer {len(self.consumer_tab)}")
    #         # self.consumer_tab[-1].client_signal.connect(consumerUI.textBrowser.updateBrowser)
    #     except Exception as e:
    #         print(f'[ERROR] Other exception in MainWindow_controller.createConsumerTab: {e}, line ',
    #               e.__traceback__.tb_lineno)

    def updateBrowser(self, index: int, send_type: str, text: str):
        try:
            if index == self.textBrowser.property("index") and send_type == self.textBroser.property("type"):
                self.textBrowser.append(text)
        except Exception as e:
            print(f'[ERROR] Other exception in MainWindow_controller.updateBrowser: {e}, line ',
                  e.__traceback__.tb_lineno)

    # callback of a custom singal in server thread
    # def createBrowser(self):
    #     try:
    #         text_browser = TextBrowser(len(self.client_list))
    #         widget = text_browser
    #         self.ui.tabWidget.addTab(widget, f"Client {len(self.client_list)}")
    #         self.client_list[-1].client_signal.connect(text_browser.updateBrowser)
    #         self.server.server_signal.connect(text_browser.updateBrowser)
    #     except Exception as e:
    #         print(f'[ERROR] Other exception in MainWindow_controller.createBrowser: {e}, line ',
    #               e.__traceback__.tb_lineno)

    # def MessageBox(self, msg_type: str, msg: str):
    #     print("WRONG")
    #     mbox = QtWidgets.QMessageBox(self)
    #     if msg_type == "information":
    #         mbox.information(self, 'information', msg)
    #     elif msg_type == "question":
    #         mbox.question(self, 'question', msg)
    #     elif msg_type == "warning":
    #         mbox.warning(self, 'warning', msg)
    #     elif msg_type == "critical":
    #         mbox.critical(self, 'critical', msg)


class TextBrowser(QWidget):
    def __init__(self, index):
        super().__init__()
        self.text_browser = QTextBrowser()
        layout = QVBoxLayout()
        layout.addWidget(self.text_browser)
        self.setLayout(layout)
        self.text_browser.setProperty("index", index)
        self.lock = threading.Lock()

    def updateBrowser(self, index: int, text: str):
        try:
            if index == self.text_browser.property("index"):
                self.text_browser.append(text)
        except Exception as e:
            print(f'[ERROR] Other exception in TextBrowser.updateBrowser: {e}, line ', e.__traceback__.tb_lineno)
