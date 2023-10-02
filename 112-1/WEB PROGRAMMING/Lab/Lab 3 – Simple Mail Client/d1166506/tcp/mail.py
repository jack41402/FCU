import sys
import socket
from getpass import getpass

BUF_SIZE = 1024


class Mail:
    def __init__(self, client_socket: socket):
        self.format = {
            "length": int,
            "header": dict,
            "content": str
        }
        self.content = {}
        self.parseLength(self.list(), False)
        self.clientSocket = client_socket

    def parseLength(self, msg: str, with_number: bool = False):
        try:
            if not with_number:
                line = msg.split('\n')
                del line[0], line[-1]
                for i in line:
                    mail_format = self.format
                    key, value = i.split(' ', 1)
                    mail_format["length"] = value
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

    def parseContent(self, mail: str):
        try:
            header, _, body = mail.partition("\n\n")
            header_lines = header.split('\n')
            for line in header_lines:
                if ':' in line:
                    key, value = line.split(':', 1)
                    self.content[][key.strip()] = value.strip()
            print("Subject: %s" % header_dict.get('Subject', ''))
            print("From: %s" % header_dict.get('From', ''))
            print("To: %s" % header_dict.get('To', ''))
            print("Date: %s" % header_dict.get('Date', ''))
            print("\n\nContent:\n")
            print(body)
        except Exception as e:
            print("Other exception: %s" % str(e))
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
            print("Other exception: %s" % str(e))
            return False

    def send_command(self, msg: str):
        try:
            self.clientSocket.send(msg)
            server_msg = self.clientSocket.receive()
            return server_msg
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    def user(self, name: str):
        try:
            self.send_command("USER " + name + "\r\n")
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            return False

    def password(self, password: str):
        try:
            self.send_command("PASS " + password + "\r\n")
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
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
                self.parseContent(mail)
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
