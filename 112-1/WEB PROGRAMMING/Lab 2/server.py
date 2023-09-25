import socket
import struct
import binascii
from PyQt6 import *

import tcp

PORT = 8888
backlog = 5
BUF_SIZE = 1024


def main():
    serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
    print("Starting up server on port: %s" % PORT)
    serverSocket.bind(('', PORT))
    serverSocket.listen(backlog)
    print("Waiting to receive message from client\n")
    client, (rip, rport) = serverSocket.accept()
    while True:
        num = tcp.receive_msg(client)
        msg = "\nReceive message from IP: " + str(rip) + " port: " + str(rport)
        print(msg)
        if num == 0:
            print("Receive END message. Closing the connection.")
            break
        if num - 1 != 0:
            num -= 1
            tcp.send_msg(client, str(num))
        else:
            print("\n**** The number is zero. Closing the connection.\n")
            tcp.send_msg(client, "END")
            break
    client.close()
    serverSocket.close()


if __name__ == "__main__":
    main()
