import sys
import socket
from getpass import getpass

BUFF_SIZE = 1024

class Command:
    def __init__(self):
        self.mail = None
        self.ip = None
        self.mail_count = None
        self.server_socket = None

    def user(self, name: str):
        return "USER " + name + "\r\n"

    def password(self, password: str):
        return "PASS " + password + "\r\n"

    def quit(self):
        return "QUIT\r\n"

    def status(self):
        return "STAT\r\n"

    def list(self, msg: int = ''):
        if msg == '':
            return "LIST\r\n"
        else:
            return "LIST " + str(msg) + "\r\n"

    def retrive(self, msg: int):
        if self.mail_count >= 1:
            while True:
                mail_number = int(input('Enter the number of the mail you want to read:'))
                if not str(mail_number).isdigit():
                    continue
                elif not 1 <= mail_number <= self.mail_count:
                    continue
                else:
                    mail_number = int(mail_number)
                    break
            self.server_socket.send(("RETR " + str(msg) + "\r\n").encode('utf-8'))
            reply = self.server_socket.recv(BUFF_SIZE).decode('utf-8')
            print('Receive message: %s' % reply)
            if reply[0] != '+':
                return False

    def delete(self, msg: int):
        return str("DELE " + str(msg) + "\r\n")

    def noop(self):
        return "NOOP\r\n"

    def last(self):
        return "LAST\r\n"

    def reset(self):
        return "RSET\r\n"

    def top(self, n: int, msg: int = ''):
        if n <= 0:
            return False
        if msg == '':
            return "TOP " + str(n) + "\r\n"
        else:
            return "TOP " + str(msg) + ' ' + str(n) + "\r\n"

