import sys
import socket
import struct
import binascii

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
    s = struct.Struct('!' + "I")
    error = False
    while True:
        if num - 1 == 0:
            print("\n**** The number is zero. Closing the connection.\n")
            break
        packed_data = s.pack(num - 1)
        print("Packed value: ", binascii.hexlify(packed_data))
        try:
            print("Send: %s" % packed_data)
            print("The data you send: Integer=%d\n" % (num - 1))
            cSocket.send(packed_data)
        except socket.error as e:
            print("Socket error: %s" % str(e))
        except Exception as e:
            print("Other exception: %s" % str(e))
        # finally:
        #     print("Closing connection.")
        #     cSocket.close()
        server_msg = cSocket.recv(BUF_SIZE)
        try:
            unpacked_data = s.unpack(server_msg)
        except BaseException as e:
            error = True
        if error:
            break
        msg = "Receive message from IP: " + str(server_IP) + " port: " + str(PORT)
        print(msg)
        print("Receive value: ", binascii.hexlify(server_msg))
        print("The data you receive: Integer=%d\n" % unpacked_data[0])
        if server_msg:
            unpacked_data = s.unpack(server_msg)
            num = unpacked_data[0]
        else:
            break
    cSocket.close()


if __name__ == "__main__":
    main()
