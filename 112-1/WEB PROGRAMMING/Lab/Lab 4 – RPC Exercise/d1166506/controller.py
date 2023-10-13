from PyQt6.QtCore import pyqtSignal, Qt
from PyQt6.QtWidgets import QMainWindow, QListWidgetItem
from UI import login, register, forum, post
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

    def showArticle(self, item):
        try:
            article = item.data(Qt.ItemDataRole.UserRole)
            print("Article: ", article)
            print(article.title)
            print(article.author)
            print(article.time)
            header = article.title + '\n' + article.author + '\n' + article.time.strftime("%Y-%m-%d %H:%M:%S")
            print("Header: ", header)
            self.ForumWindow.Header_textBrowser.setText(header)
            self.ForumWindow.Content_textBrowser.setText(article.content)
        except Exception as e:
            print(f'[ERROR] Other exception in Forum_controller.showArticle: {e}')

    def updateArticle(self):
        try:
            result = self.client.subject()
            if result is not None:
                for row in result:
                    article = Article(row[0], row[1], row[2], row[3], row[4], self.client.user(row[4])[0][2])
                    # item["datetime"] = row[3].strftime("%Y-%m-%d %H:%M:%S")


                    # Convert the XML-RPC DateTime to a Python datetime object
                    # standard_datetime = datetime.datetime.strptime(str(row[3].datetime), '%Y%m%dT%H:%M:%S')
                    xmlrpc_datetime = row[3]

                    # # Convert the XML-RPC DateTime to a Python datetime object
                    # date_string = xmlrpc_datetime.isoformat()
                    # standard_datetime = datetime.fromisoformat(date_string)
                    standard_datetime = datetime.datetime.fromtimestamp(xmlrpc_datetime.timestamp())
                    print(standard_datetime)
                    print(type(row[3]))
                    print(standard_datetime)
                    print(type(standard_datetime))
                    print("row[3]: ", row[3].strftime("%Y-%m-%d %H:%M:%S"))
                    print("item.time: ", article.time.strftime("%Y-%m-%d %H:%M:%S"))
                    item = QListWidgetItem(article.title)
                    item.setData(Qt.ItemDataRole.UserRole, article)
                    print("Item data: ", item.data(Qt.ItemDataRole.UserRole))
                    self.ForumWindow.Article_listWidget.addItem(item)
        except Exception as e:
            print(f'[ERROR] Other exception in Forum_controller.updateArticle: {e}')


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


class Article:
    def __init__(self, article_id: int, title: str, content: str, time: datetime, author_id: int, author: str):
        self.article = article_id
        self.title = title
        self.content = content
        self.time = time
        self.author_id = author_id
        self.author = author
