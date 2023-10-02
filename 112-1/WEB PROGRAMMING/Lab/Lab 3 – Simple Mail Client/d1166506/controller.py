from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import QTableWidgetItem, QMainWindow

from home import Mailbox
from tcp import validate, client
import sys


class MainWindow_controller(QMainWindow):
    def __init__(self):
        super(MainWindow_controller, self).__init__()
        self.clicked_counter = None
        self.mailbox = Mailbox()
        self.mailbox.setupUi(self)
        self.setup_control()
        self.server = None
        self.client = None
        self.ip = None
        self.port = None
        self.num = None
        self.backlog = 5

    def setup_control(self):
        self.mailbox.select_all_checkbox.stateChanged.connect(self.toggle_select_all)
        self.mailbox.mail_table.doubleClicked.connect(self.show_mail_content)
        self.mailbox.delete_button.clicked.connect(self.delete_selected_items)  # 连接点击事件到删除操作

        self.mailbox.btn_Run.clicked.connect(self.RunClicked)
        self.mailbox.btn_Exit.clicked.connect(self.ExitClicked)
        self.mailbox.btn_Clear.clicked.connect(self.ClearClicked)

    def add_mail(self, sender, subject, date, time, content):
        row_position = self.mailbox.mail_table.rowCount()
        self.mailbox.mail_table.insertRow(row_position)

        # Create mail info
        item = QTableWidgetItem()
        item.setCheckState(Qt.CheckState.Unchecked)
        self.mail_table.setItem(row_position, 0, item)

        # Create row item
        self.mail_table.setItem(row_position, 1, QTableWidgetItem(sender))
        self.mail_table.setItem(row_position, 2, QTableWidgetItem(subject))
        self.mail_table.setItem(row_position, 3, QTableWidgetItem(date))
        self.mail_table.setItem(row_position, 4, QTableWidgetItem(time))

        # Save mail content at first column in each mail
        item = self.mail_table.item(row_position, 1)
        item.setData(Qt.ItemDataRole.UserRole, content)

    def show_mail_content(self, index):
        row = index.row()
        content_item = self.mail_table.item(row, 1)
        content = content_item.data(Qt.ItemDataRole.UserRole)
        self.mail_content.clear()
        self.mail_content.insertPlainText(content)
        self.mail_content.moveCursor(QTextCursor.MoveOperation.Start)

    def toggle_select_all(self):
        for row in range(self.mail_table.rowCount()):
            item = self.mail_table.item(row, 0)
            if item is not None:
                if self.select_all_checkbox.checkState() == Qt.CheckState.Checked:
                    item.setCheckState(Qt.CheckState.Checked)
                else:
                    item.setCheckState(Qt.CheckState.Unchecked)


    def RunClicked(self):
        msg_IP_Address = self.mailbox.lineEdit_IP_Address.text()
        msg_Server_Port = self.mailbox.lineEdit_Server_Port.text()
        msg_Number = self.mailbox.lineEdit_Number.text()
        validator = validate.Validate()
        # validator.valid_warning.connect(self.MessageBox)
        if validator.checker(msg_IP_Address, msg_Server_Port, msg_Number):
            print("[INFO] Validation success.")
        else:
            print("[INFO] Validation Failed")

        self.ip = validator.ip
        self.port = validator.port
        self.num = validator.num
        self.start()

    def ExitClicked(self):
        sys.exit(-1)

    def ClearClicked(self):
        self.mailbox.textBrowser.setText("")

    def start(self):
        self.server = server.Server(self.ip, self.port)
        self.client = client.Client(self.ip, self.port, self.num)
        self.server.server_signal.connect(self.UpdateBrowser)
        self.client.client_signal.connect(self.UpdateBrowser)
        self.server.start()
        self.client.start()

    # callback of a custom singal in server thread
    def UpdateBrowser(self, data):
        self.mailbox.textBrowser.append(data)

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
