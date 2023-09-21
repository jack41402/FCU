import socket
import struct
import binascii

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
    s = struct.Struct('!' + 'I')
    while True:
        client_msg = client.recv(BUF_SIZE)
        if len(client_msg) < s.size:
            break
        if client_msg:
            msg = "\nReceive message from IP: " + str(rip) + " port: " + str(rport)
            print(msg)
            print("Receive value: ", binascii.hexlify(client_msg))
            s = struct.Struct('!' + "I")
            unpacked_data = s.unpack(client_msg)
            print("The data you receive: Integer=%d\n" % unpacked_data[0])
            if unpacked_data[0]-1 != 0:
                packed_data = s.pack(unpacked_data[0]-1)
                try:
                    print("Send: %s" % packed_data)
                    print("The data you send: Integer=%d\n" % (unpacked_data[0]-1))
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
                break
    client.close()
    serverSocket.close()


if __name__ == "__main__":
    main()
