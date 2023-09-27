import sys
import socket
from tcp import message

PORT = 8888
BUF_SIZE = 1024


def main():
    if len(sys.argv) < 2:
        print("Usage: python3 client.py ServerIP")
        exit(1)
    while True:
        num = input("Please input an positive integer: ")
        if num.isdigit() and int(num) > 0:
            break
    num = int(num)
    print("The data you input: Integer=%d" % num)

    server_IP = socket.gethostbyname(sys.argv[1])
    cSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("Connecting to %s port %s" % (server_IP, PORT))
    cSocket.connect((server_IP, PORT))
    while True:
        if num - 1 == 0:
            print("\n**** The number is zero. Closing the connection.\n")
            message.send_msg(cSocket, "END")
            break
        else:
            num -= 1
            message.send_msg(cSocket, str(num))

        msg = "Receive message from IP: " + str(server_IP) + " port: " + str(PORT)
        print(msg)
        server_msg = message.receive_msg(cSocket)
        if server_msg == 0:
            print("Receive END message. Closing the connection.")
            break
        else:
            num = server_msg
    cSocket.close()


if __name__ == "__main__":
    main()
