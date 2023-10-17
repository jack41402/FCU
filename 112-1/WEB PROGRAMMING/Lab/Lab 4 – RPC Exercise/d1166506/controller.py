import sys

from PyQt6 import QtGui
from PyQt6.QtCore import pyqtSignal, Qt, QSize
from PyQt6.QtWidgets import QMainWindow, QListWidgetItem, QLabel, QWidget, QVBoxLayout, QApplication
from UI import login, register, forum, post, comment
from rpc import client
import datetime


class Login_controller(QMainWindow):
    login_signal = pyqtSignal(str)

    def __init__(self):
        super(Login_controller, self).__init__()
        self.LoginWindow = login.Ui_Login()
        self.LoginWindow.setupUi(self)
        self.login_setup_control()
        self.RegisterWindow = None
        self.ForumWindow = None
        self.client = None
        self.ip = "127.0.0.1"
        self.port = 6666
        self.start()

    def login_setup_control(self):
        try:
            self.LoginWindow.Login_button.clicked.connect(self.LoginClicked)
            self.LoginWindow.Register_label.linkActivated.connect(self.RegisterClicked)
            print("[INFO] Login setup successfully.")
        except Exception as e:
            print(f'[ERROR] Other exception in Login_controller.login_setup_control: {e}')

    def LoginClicked(self):
        try:
            username = self.LoginWindow.Username_lineEdit.text()
            password = self.LoginWindow.Password_lineEdit.text()
            try_login = self.client.proxy.login(username, password)
            if try_login is False:
                self.LoginWindow.Password_lineEdit.setText("")
            elif try_login is True:
                self.close()
                if self.RegisterWindow:
                    self.RegisterWindow.close()
                self.client.username = username
                self.ForumWindow = Forum_controller(self.client)
                self.ForumWindow.show()
                self.close()
        except Exception as e:
            print(f'[ERROR] Other exception in Login_controller.LoginClicked: {e}')

    def RegisterClicked(self):
        try:
            if not self.RegisterWindow:
                self.RegisterWindow = Register_controller()
            self.RegisterWindow.LoginWindow = self
            self.RegisterWindow.client = self.client
            self.hide()
            self.LoginWindow.Username_lineEdit.setText("")
            self.LoginWindow.Password_lineEdit.setText("")
            self.RegisterWindow.show()
        except Exception as e:
            print(f'[ERROR] Other exception in Login_controller.RegisterClicked: {e}')

    def start(self):
        self.client = client.Client(self.ip, self.port)
        # self.client.client_signal.connect(self.UpdateBrowser)
        self.client.start()

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


class Register_controller(QMainWindow):
    def __init__(self):
        super(Register_controller, self).__init__()
        self.RegisterWindow = register.Ui_Register()
        self.RegisterWindow.setupUi(self)
        self.register_setup_control()

        self.LoginWindow = None
        self.client = None

    def register_setup_control(self):
        try:
            self.RegisterWindow.Register_button.clicked.connect(self.RegisterClicked)
            self.RegisterWindow.Login_label.linkActivated.connect(self.LoginClicked)
            print("[INFO] Register setup successfully.")
        except Exception as e:
            print(f'[ERROR] Other exception in Register_controller.register_setup_control: {e}')

    def RegisterClicked(self):
        try:
            username = self.RegisterWindow.Username_lineEdit.text()
            password = self.RegisterWindow.Password_lineEdit.text()
            confirm_password = self.RegisterWindow.Confirm_Password_lineEdit.text()
            try_register = self.client.register(username, password, confirm_password)
            if try_register is False:
                self.RegisterWindow.Password_lineEdit.setText("")
                self.RegisterWindow.Confirm_Password_lineEdit.setText("")
            elif try_register is True:
                self.close()
                self.LoginWindow.show()
        except Exception as e:
            print(f'[ERROR] Other exception in Register_controller.RegisterClicked: {e}')

    def LoginClicked(self):
        try:
            self.hide()
            self.RegisterWindow.Username_lineEdit.setText("")
            self.RegisterWindow.Password_lineEdit.setText("")
            self.RegisterWindow.Confirm_Password_lineEdit.setText("")
            self.LoginWindow.show()
        except Exception as e:
            print(f'[ERROR] Other exception in Register_controller.LoginClicked: {e}')


class Forum_controller(QMainWindow):
    def __init__(self, client):
        super(Forum_controller, self).__init__()
        self.ForumWindow = forum.Ui_Forum()
        self.ForumWindow.setupUi(self)
        self.forum_setup_control()
        self.client = client
        self.PostWindow = None
        self.updateArticle()
        self.scroll_area_layout = QVBoxLayout()
        self.scroll_area_widget = QWidget()
        self.scroll_area_layout.setSpacing(0)


    def forum_setup_control(self):
        try:
            self.ForumWindow.Post_pushButton.clicked.connect(self.PostClicked)
            self.ForumWindow.Delete_pushButton.clicked.connect(self.DeleteClicked)
            self.ForumWindow.Article_listWidget.itemClicked.connect(self.showArticle)
        except Exception as e:
            print(f'[ERROR] Other exception in Forum_controller.Forum_setup_control: {e}')

    def PostClicked(self):
        try:
            self.PostWindow = Post_controller()
            self.PostWindow.client = self.client
            self.PostWindow.show()
        except Exception as e:
            print(f'[ERROR] Other exception in Forum_controller.PostClicked: {e}')

    def DeleteClicked(self):
        pass

    def showAll(self, item):
        try:
            post = item.data(Qt.ItemDataRole.UserRole)

            self.showArticle(post)
            self.showComment()
            self.scroll_area_widget.setLayout(self.scroll_area_layout)
            self.ForumWindow.scrollArea.setWidget(self.scroll_area_widget)
        except Exception as e:
            print(f'[ERROR] Other exception in Forum_controller.showAll: {e}')

    def showArticle(self, post):
        try:
            print("show article", post)
            form_widget = QWidget()
            form = comment.Ui_Form()
            form.setupUi(form_widget)
            form.Reply_pushButton.setText("Comment")
            form.Reply_pushButton.setProperty("info", {"type": "comment", "floor": 0})
            form.Reply_pushButton.clicked.connect(self.comment)
            form.Author_label.setText(post.header)
            form.Comment_label.setText(post.content)
            form.Comment_label.setFixedHeight(max(500, form.Comment_label.sizeHint().height()))
            form.Floor_Time_label.setText("")
            if post.author is not self.client.username:
                form.Delete_pushButton.hide()
            self.scroll_area_layout.addWidget(form_widget)
        except Exception as e:
            print(f'[ERROR] Other exception in Forum_controller.showArticle: {e}')

    def showComment(self):
        try:
            pass
        except Exception as e:
            print(f'[ERROR] Other exception in Forum_controller.showComment: {e}')

    def updateArticle(self):
        try:
            result = self.client.subject()
            if result is not None:
                for row in result:
                    post = Post(row[0], row[1], row[2], row[3], row[4], self.client.user(row[4])[0][2])
                    item = QListWidgetItem(post.title)
                    item.setData(Qt.ItemDataRole.UserRole, post)
                    print(item.data(Qt.ItemDataRole.UserRole))
                    item.setFont(QtGui.QFont("Arial", 12))  # Set font and size
                    item.setSizeHint(QSize(100, 25))
                    self.ForumWindow.Article_listWidget.addItem(item)
        except Exception as e:
            print(f'[ERROR] Other exception in Forum_controller.updateArticle: {e}')

    def comment(self):
        try:
            button = QApplication(sys.argv).sender()
            print(button.property("info"))
        except Exception as e:
            print(f'[ERROR] Other exception in Forum_controller.comment: {e}')


class Post_controller(QMainWindow):
    def __init__(self):
        super(Post_controller, self).__init__()
        self.PostWindow = post.Ui_Post()
        self.PostWindow.setupUi(self)
        self.post_setup_control()
        self.client = None

    def post_setup_control(self):
        try:
            self.PostWindow.Post_pushButton.clicked.connect(self.PostClicked)
            self.PostWindow.Cancel_pushButton.clicked.connect(self.CancelClicked)
        except Exception as e:
            print(f'[ERROR] Other exception in Forum_controller.Forum_setup_control: {e}')

    def PostClicked(self):
        try:
            title = self.PostWindow.Title_lineEdit.text()
            content = self.PostWindow.Content_textEdit.toPlainText()
            self.client.post(title, content)
            self.close()
        except Exception as e:
            print(f'[ERROR] Other exception in Forum_controller.PostClicked: {e}')

    def CancelClicked(self):
        pass


class Post:
    def __init__(self, post_id: int, title: str, content: str, time: datetime, author_id: int, author: str):
        self.post_id = post_id
        self.title = title
        self.content = content
        self.time = time
        self.author_id = author_id
        self.author = author
        self.header = title + '\n' + author + '\n' + time.strftime("%Y-%m-%d %H:%M:%S")
