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
    print("Waiting to receive message from client")
    client, (rip, rport) = serverSocket.accept()
    while True:
        client_msg = client.recv(BUF_SIZE)
        if client_msg:
            msg = "Receive message from IP: " + str(rip) + " port: " + str(rport)
            print(msg)
            print("Receive value: ", binascii.hexlify(client_msg))
            s = struct.Struct('!' + "I")
            unpacked_data = s.unpack(client_msg)
            print("The data you receive:\n Integer=%d\n" % unpacked_data[0])
            if unpacked_data[0]-1 != 0:
                record = tuple(unpacked_data[0]-1)
                s = struct.Struct('!' + 'I')
                packed_data = s.pack(*record)
                try:
                    print('Send: %s' % packed_data)
                    serverSocket.send(packed_data)
                except socket.error as e:
                    print('Socket error: %s' % str(e))
                except Exception as e:
                    print('Other exception: %s' % str(e))
                finally:
                    print('Closing connection.')
                    # Close the TCP socket
                    serverSocket.close()
        else:
            client.close()
            serverSocket.close()


if __name__ == "__main__":
    main()
