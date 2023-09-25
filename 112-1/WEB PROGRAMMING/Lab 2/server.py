import socket
import struct
import binascii
from PyQt6 import *

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
        client_msg = client.recv(BUF_SIZE)
        if client_msg:
            try:
                unpacked_data = s.unpack(client_msg)
            except Exception as e:
                error = True
            if error:
                break
            msg = "\nReceive message from IP: " + str(rip) + " port: " + str(rport)
            print(msg)
            if unpacked_data[0].decode('utf-8') == "END":
                print("Receive END message. Closing the connection.")
                break
            print("Receive value: ", binascii.hexlify(client_msg))
            num = int(unpacked_data[0].decode('utf-8'))
            print("The data you receive: Integer=%d\n" % num)
            if num - 1 != 0:
                num = num - 1
                packed_data = s.pack(str(num).encode('utf-8'))
                try:
                    print("Send: %s" % packed_data)
                    print("The data you send: Integer=%d\n" % num)
                    client.send(packed_data)
                except socket.error as e:
                    print("Socket error: %s" % str(e))
                except Exception as e:
                    print("Other exception: %s" % str(e))
                # finally:
                #     print("Closing connection.")
                #     # Close the TCP socket
                #     serverSocket.close()
            else:
                print("\n**** The number is zero. Closing the connection.\n")
                packed_data = s.pack("END".encode('utf-8'))
                try:
                    print("Send: %s" % packed_data)
                    print("The data you send: String=\"END\"\n")
                    client.send(packed_data)
                except socket.error as e:
                    print("Socket error: %s" % str(e))
                except Exception as e:
                    print("Other exception: %s" % str(e))
                break
        else:
            break
    client.close()
    serverSocket.close()


if __name__ == "__main__":
    main()
