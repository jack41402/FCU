import sys
import socket
import struct
import binascii

BUF_SIZE = 1024


def analyze_msg(msg: str):
    s = struct.Struct('!' + 'I')
    msg_code = s.unpack(msg)[0]
    if msg_code==1:
        return "int"
    elif msg_code==2:
        return "str"
    else:
        return "ERROR"

def receive_msg(socket_stream: socket):
    server_msg = socket_stream.recv(BUF_SIZE)
    msg_type = analyze(server_msg[:4])

    if msg_type=="int":
        s = struct.Struct('!' + 'I')
        try:
            unpacked_data = s.unpack(server_msg[4:8])
        except socket.error as e:
            print("Socket error: %s" % str(e))
        except Exception as e:
            print("Other exception: %s" % str(e))

        print("Receive value: ", binascii.hexlify(server_msg))
        num = unpacked_data[0].decode('utf-8')
        print("The data you receive: Integer=%d\n" % num)
        return num
    elif msg_type=="str":
        s = struct.Struct('!' + 'I')
        str_length = s.unpack(server_msg[4:8])[0]
        s = struct.Struct('!' + '%ds' % str_length)
        try:
            unpacked_data = s.unpack(server_msg[8:8+str_length])
        except socket.error as e:
            print("Socket error: %s" % str(e))
        except Exception as e:
            print("Other exception: %s" % str(e))

        print("Receive value: ", binascii.hexlify(server_msg))
        msg = unpacked_data[0].decode('utf-8')
        print("The data you receive: String=%s\n" % msg)
        if msg=="END":
            print("Receive END message. Closing the connection.")
            return 0
    else:
        print("Error: Unknown data type. Ending the process.\n")
        exit(1)

def send_msg(socket_stream: socket , msg: str):
    if msg.isdigit():
        msg_type = b'0x01'
        s = struct.Struct('!' +'I' + 'I')
        packed_data = s.pack(msg_type , int(msg))
    else:
        msg_type = b'0x02'
        s = struct.Struct('!' + 'I' + 'I' + '%ds' % len(msg))
        packed_data = s.pack(msg_type , len(msg) , msg.encode('utf-8'))

    print("Packed value: ", binascii.hexlify(packed_data))
    try:
        print("Send: %s" % packed_data)
        if msg_type==b'0x01':
            print("The data you send: Integer=%d\n" % num)
        elif msg_type==b'0x02':
            print("The data you send: String=%s\n" % msg)
        else:
            print("Type error: Unknown data type. Ending the process.\n")
            exit(1)
        cSocket.send(packed_data)
    except socket.error as e:
        print("Socket error: %s" % str(e))
        return 1
    except Exception as e:
        print("Other exception: %s" % str(e))
        return 2
    return 0