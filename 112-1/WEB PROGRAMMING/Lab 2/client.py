import sys
import socket
import struct
import binascii

PORT = 8888
BUF_SIZE = 1024


def main():
    print("TEST\n\n")
    if len(sys.argv) < 2:
        print("Usage: python3 client.py ServerIP")
        exit(1)
    while True:
        num = input("Please input an positive integer: ")
        if num.isdigit():
            break
    num = int(num)
    print("The data you input:\n Integer=%d" % num)

    server_IP = socket.gethostbyname(sys.argv[1])
    cSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("Connecting to %s port %s" % (server_IP, PORT))
    cSocket.connect((server_IP, PORT))
    while True:
        record = tuple(num)
        s = struct.Struct('!' + 'I')
        packed_data = s.pack(*record)
        print("Packed value: ", binascii.hexlify(packed_data))
        try:
            print("Send: %s" % packed_data)
            cSocket.send(packed_data)
        except socket.error as e:
            print("Socket error: %s" % str(e))
        except Exception as e:
            print("Other exception: %s" % str(e))
        finally:
            print("Closing connection.")
            cSocket.close()
        server_msg = cSocket.recv(BUF_SIZE)
        if server_msg:
            unpacked_data = s.unpack(server_msg)
            if unpacked_data[0] - 1 != 0:
                num = unpacked_data[0] - 1
            else:
                cSocket.close()
        else:
            cSocket.close()


if __name__ == "__main__":
    main()
