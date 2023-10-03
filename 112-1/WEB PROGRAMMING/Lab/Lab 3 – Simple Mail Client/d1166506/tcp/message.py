import sys
import socket
import struct
import binascii

BUF_SIZE = 1024


def receive_msg(socket_stream: socket):
    server_msg = socket_stream.recv(BUF_SIZE)
    if server_msg:
        try:
            server_reply = server_msg.decode('utf-8')
            print('Receive message: %s' % server_reply)
            return server_reply
        except socket.error as e:
            print("Socket error: %s" % str(e))
        except Exception as e:
            print("Other exception: %s" % str(e))


def send_msg(socket_stream: socket, msg: str):
    if msg:
        try:
            print("Send: %s" % msg)
            socket_stream.send(msg.encode('utf-8'))
        except socket.error as e:
            print("Socket error: %s" % str(e))
        except Exception as e:
            print("Other exception: %s" % str(e))
        return True
    else:
        return False
