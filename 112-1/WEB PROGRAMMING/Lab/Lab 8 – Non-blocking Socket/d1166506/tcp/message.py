import sys
import socket
import struct
import binascii
import threading


def analyze_msg(msg: str):
    try:
        with threading.Lock():
            s = struct.Struct('!' + 'I')
            msg_code = s.unpack(msg)[0]
            print("Message code: ", msg_code)
            if msg_code == 1:
                return "PRO"
            elif msg_code == 2:
                return "CON"
            elif msg_code == 3:
                return "SRV"
            elif msg_code == -1:
                return "ERR"
            else:
                return "ERROR"
    except Exception as e:
        print(f'[ERROR] Other exception in message.analyze_msg: {e}, line ', e.__traceback__.tb_lineno)


def receive_msg(socket_stream: socket, socket_object=None):
    try:
        with threading.Lock():
            msg_header = socket_stream.recv(4)
            print("\nMessage type: ", msg_header)
            if msg_header:
                msg_type = analyze_msg(msg_header)
                print("Message type: ", msg_type)
                if msg_type == "PRO" or msg_type == "SRV":
                    receive_msg = socket_stream.recv(4)
                    s = struct.Struct('!' + 'I')
                    try:
                        unpacked_data = s.unpack(receive_msg)
                    except socket.error as e:
                        print("Socket error: %s" % str(e))
                    except Exception as e:
                        print("Other exception: %s" % str(e))
                    print("Receive value: ", binascii.hexlify(receive_msg))
                    num = int(unpacked_data[0])
                else:
                    num = None
                if num is None:
                    print("The data you receive: \"%s\"" % msg_type)
                else:
                    print("The data you receive: \"%s\"=%d" % (msg_type, num))
                return msg_type, num
    except Exception as e:
        print(f'[ERROR] Other exception in message.receive_msg: {e}, line ', e.__traceback__.tb_lineno)


def send_msg(socket_stream: socket, msg: str, server=False):
    try:
        with threading.Lock():
            if msg.isdigit():
                s = struct.Struct('!' + 'I' + 'I')
                if server:
                    msg_type = 3
                else:
                    msg_type = 1
                packed_data = s.pack(msg_type, int(msg))
            else:
                if msg == "CON":
                    msg_type = 2
                elif msg == "ERR":
                    msg_type = -1
                else:
                    print("[ERROR] Unexpected string format.")
                    return False
                s = struct.Struct('!' + 'I')
                packed_data = s.pack(msg_type)

            print("\nPacked value: ", binascii.hexlify(packed_data))
            try:
                print("Send: %s" % packed_data)
                if msg_type == 1 or msg_type == 3:
                    print("The data you send: Integer=%d\n" % int(msg))
                elif msg_type == 2 or msg_type == -1:
                    print("The data you send: String=%s\n" % msg)
                else:
                    print("Type error: Unknown data type. Ending the process.\n")
                    exit(1)
                socket_stream.sendall(packed_data)
            except socket.error as e:
                print("Socket error: %s" % str(e))
                return False
            except Exception as e:
                print("Other exception: %s" % str(e))
                return False
            return True
    except Exception as e:
        print(f'[ERROR] Other exception in message.send_msg: {e}, line ', e.__traceback__.tb_lineno)
