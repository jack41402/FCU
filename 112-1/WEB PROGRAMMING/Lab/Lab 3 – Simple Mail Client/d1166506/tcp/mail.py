import sys
import socket
from .client import Client
from PyQt6.QtCore import pyqtSignal, QThread
from getpass import getpass

BUF_SIZE = 1024


class Mail(QThread):
    mail_error_signal = pyqtSignal(str)

    def __init__(self, ip, port):
        super().__init__()
        self.client = Client(ip, port)
        self.clientSocket = self.client.clientSocket
        self.format = {
            "length": int,
            "header": {},
            "content": str
        }
        self.content = {}

    def parseLength(self, msg: str, with_number: bool = False):
        try:
            if not with_number:
                line = msg.split('\n')
                del line[0], line[-1]
                for i in line:
                    mail_format = self.format
                    key, value = i.split(' ', 1)
                    mail_format["length"] = int(value)
                    self.content[key] = mail_format
                return True
            elif with_number:
                respond, key, value = msg.split(' ')
                mail_format = self.format
                mail_format["length"] = value
                self.content[key] = mail_format
                return True
            else:
                return False
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    def parseContent(self, mail: str, msg: int):
        try:
            # 找到 header 和 body 的分隔位置
            separator = "\r\n\r\n"
            separator_index = mail.find(separator)

            # 檢查是否找到分隔符號
            if separator_index != -1:
                header = mail[1:separator_index]  # 提取 header 部分
                self.content[msg]["content"] = mail[separator_index + len(separator):-3]  # 提取 body 部分
                separator = "octets"
                separator_index = header.find(separator)
                header = header[separator_index + len("octets"):]  # 提取拿掉伺服器回應的 header 部分

                header_lines = header.split('\n')

                for line in header_lines:
                    if ':' in line:
                        key, value = line.split(':', 1)
                        self.content[msg]["header"][key.strip()] = value.strip()
                time = self.content[msg]["header"]["Date"].split(' ', 4)
                date = self.content[msg]["header"]["Date"][:-len(time[4])]
                self.content[msg]["header"]["Date"] = date
                time = time[4].split()[0]
                self.content[msg]["header"]["Time"] = time
                print("Subject: %s" % self.content[msg]["header"].get('Subject', ''))
                print("From: %s" % self.content[msg]["header"].get('From', ''))
                print("To: %s" % self.content[msg]["header"].get('To', ''))
                print("Date: %s" % self.content[msg]["header"].get('Date', ''))
                print("\n\nContent:\n")
                print(self.content[msg]["content"])

            else:
                print("Separator not found in the mail content.")

        except Exception as e:
            print("Other exception in mail.parseContent: %s" % str(e))
            return False

    def validate(self, msg: int):
        try:
            if not str(msg).isdigit():
                print("[ERROR] MAIL NUMBER SHOULD BE POSITIVE INTEGER.")
                return False
            elif self.content.get(msg, -1)["length"] == -1:
                print("[ERROR] MAIL NUMBER %d DOESN\'T EXIST." % msg)
                return False
            else:
                return True
        except Exception as e:
            print("Other exception in mail.validate: %s" % str(e))
            return False

    def send_command(self, command):
        try:
            self.client.send(command)
            server_msg = self.client.receive()
            if server_msg is not None:
                return server_msg
        except Exception as e:
            print("Other exception in mail.send_command: %s" % str(e))
            return False

    def user(self, name: str):
        try:
            error = self.send_command("USER " + name + "\r\n")
            if error[0] == '-':
                self.mail_error_signal.emit("USER ERROR")
                return False
            elif error[0] == '+':
                return error
        except Exception as e:
            print("Other exception in mail.user: %s" % str(e))
            return False

    def password(self, password: str):
        try:
            error = self.send_command("PASS " + password + "\r\n")
            if error[0] == '-':
                self.mail_error_signal.emit("PASSWORD ERROR")
                return False
            elif error[0] == '+':
                return error
        except Exception as e:
            print("Other exception in mail.password: %s" % str(e))
            return False

    def quit(self):
        try:
            self.send_command("QUIT\r\n")
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    def status(self):
        try:
            self.send_command("STAT\r\n")
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    def list(self, msg: int = ''):
        try:
            if msg == '':
                server_msg = self.send_command("LIST\r\n")
            elif self.validate(msg):
                server_msg = self.send_command("LIST " + str(msg) + "\r\n")
            return server_msg
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    def retrive(self, msg: int):
        try:
            if self.validate(msg):
                mail = self.send_command("RETR " + str(msg) + "\r\n")
                self.parseContent(mail, msg)
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    def delete(self, msg: int):
        try:
            if self.validate(msg):
                self.send_command("DELE " + str(msg) + "\r\n")
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    def noop(self):
        try:
            self.send_command("NOOP\r\n")
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    def last(self):
        try:
            self.send_command("LAST\r\n")
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    def reset(self):
        try:
            self.send_command("RSET\r\n")
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    # Check if exceed maximum lines
    def top(self, n: int, msg: int = ''):
        try:
            if n <= 0:
                return False
            if msg == '':
                return "TOP " + str(n) + "\r\n"
            elif self.validate(msg):
                return "TOP " + str(msg) + ' ' + str(n) + "\r\n"
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False
