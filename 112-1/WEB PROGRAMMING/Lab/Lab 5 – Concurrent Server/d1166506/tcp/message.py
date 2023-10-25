import sys
import socket
import struct
import binascii

BUF_SIZE = 1024


def analyze_msg(msg: str):
    try:
        s = struct.Struct('!' + 'I')
        msg_code = s.unpack(msg)[0]
        if msg_code == 1:
            return "int"
        elif msg_code == 2:
            return "str"
        else:
            return "ERROR"
    except Exception as e:
        print(f'[ERROR] Other exception in message.analyze_msg: {e}, line ', e.__traceback__.tb_lineno)


def receive_msg(socket_stream: socket):
    try:
        server_msg = socket_stream.recv(BUF_SIZE)
        if server_msg:
            msg_type = analyze_msg(server_msg[:4])
            if msg_type == "int":
                s = struct.Struct('!' + 'I')
                try:
                    unpacked_data = s.unpack(server_msg[4:8])
                except socket.error as e:
                    print("Socket error: %s" % str(e))
                except Exception as e:
                    print("Other exception: %s" % str(e))

                print("Receive value: ", binascii.hexlify(server_msg))
                num = unpacked_data[0]
                print("The data you receive: Integer=%d\n" % num)
                return int(num)
            elif msg_type == "str":
                s = struct.Struct('!' + 'I')
                str_length = s.unpack(server_msg[4:8])[0]
                s = struct.Struct('!' + '%ds' % str_length)
                try:
                    unpacked_data = s.unpack(server_msg[8:8 + str_length])
                except socket.error as e:
                    print("Socket error: %s" % str(e))
                except Exception as e:
                    print("Other exception: %s" % str(e))

                print("Receive value: ", binascii.hexlify(server_msg))
                msg = unpacked_data[0].decode('utf-8')
                print("The data you receive: String=%s\n" % msg)
                if msg == "END":
                    return 0
            else:
                print("Error: Unknown data type. Ending the process.\n")
                exit(1)
    except Exception as e:
        print(f'[ERROR] Other exception in message.receive_msg: {e}, line ', e.__traceback__.tb_lineno)


def send_msg(socket_stream: socket, msg: str):
    try:
        if msg.isdigit():
            msg_type = 1
            s = struct.Struct('!' + 'I' + 'I')
            packed_data = s.pack(msg_type, int(msg))
        else:
            msg_type = 2
            s = struct.Struct('!' + 'I' + 'I' + '%ds' % len(msg))
            packed_data = s.pack(msg_type, len(msg), msg.encode('utf-8'))

        print("Packed value: ", binascii.hexlify(packed_data))
        try:
            print("Send: %s" % packed_data)
            if msg_type == 1:
                print("The data you send: Integer=%d\n" % int(msg))
            elif msg_type == 2:
                print("The data you send: String=%s\n" % msg)
            else:
                print("Type error: Unknown data type. Ending the process.\n")
                exit(1)
            socket_stream.send(packed_data)
        except socket.error as e:
            print("Socket error: %s" % str(e))
            return 1
        except Exception as e:
            print("Other exception: %s" % str(e))
            return 2
        return 0
    except Exception as e:
        print(f'[ERROR] Other exception in message.send_msg: {e}, line ', e.__traceback__.tb_lineno)
