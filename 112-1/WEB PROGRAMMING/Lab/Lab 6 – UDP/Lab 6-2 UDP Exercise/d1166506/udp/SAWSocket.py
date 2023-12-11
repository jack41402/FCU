####################################################
#  Network Programming - Unit 5  User Datagram Protocol          
#  Program Name: SAWSocket.py
#  This program implements stop and wait protocol based on UDP.          		
#  2021.07.19                                                 									
####################################################
import socket
import threading
import time
import struct

import random

BufSize = 1024
DEBUG = True

# Define TCP flags as macros/constants
URG = 0b100000
ACK = 0b010000
PSH = 0b001000
RST = 0b000100
SYN = 0b000010
FIN = 0b000001


class SAWSocket:
    def __init__(self, port, addr='', SlidingWindow=1):  # addr == '' if server
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        if addr == '':  # Server side
            self.isServer = True
            self.PeerAddr = ''
            self.PeerPort = 0
            # Bind 	on any incoming interface with port, '' is any interface
            self.socket.bind(('', port))
        else:  # Client side
            self.isServer = False
            self.PeerAddr = socket.gethostbyname(addr)
            self.PeerPort = port
        # end if

        # Variables share between process and daemon
        # these variable must be accessed in the critical section
        self.CS_busy = False  # True if CS_buf contains data
        self.CS_sn_send = 0  # sequence number for send DATA
        self.CS_sn_receive = 0  # sequence number for next DATA
        self.CS_ack_sn = 0  # sequence number for acknowledgement
        self.CS_running = True  # True after SAWsocket is active (created)
        self.CS_buf = ''  # for message buffer
        self.CS_length = 0  # received message length

        # constant
        self.SocketIdle = float(1.0)  # 1 sec
        self.SleepIdle = float(0.1)  # 0.1 sec
        self.BufSize = BufSize
        self.lock = threading.Lock()  # for synchronization
        self.condition = threading.Condition()
        self.ReceiveDaemon = None  # receive daemon

        # Sliding Window
        self.window_size = SlidingWindow
        self.send_window = []  # To track sent packets and their status
        self.receive_window = []  # To track received packets and their status
        self.send_status = []
        self.next_sequence_to_send = 0
        self.expected_sequence_to_receive = 0

    # end of __init__()

    def get_sn_receive(self):
        self.lock.acquire()
        sn_receive = self.CS_sn_receive
        self.lock.release()
        return sn_receive

    # end of get_sn_receive()

    def get_sn_send(self):
        self.lock.acquire()
        sn_send = self.CS_sn_send
        self.lock.release()
        return sn_send

    # end of get_sn_send()

    def add_sn_receive(self):
        self.lock.acquire()
        self.CS_sn_receive = (self.CS_sn_receive + 1) % self.window_size
        sn_receive = self.CS_sn_receive
        self.lock.release()
        return sn_receive

    # end of add_sn_receive()

    def add_sn_send(self):
        self.lock.acquire()
        self.CS_sn_send = (self.CS_sn_send + 1) % self.window_size
        sn_send = self.CS_sn_send
        self.lock.release()
        return sn_send

    # end of add_sn_send()

    def receive_ack(self, sn):
        self.lock.acquire()
        self.CS_ack_sn = sn
        with self.condition:
            self.condition.notify()
        self.lock.release()

    # end of receive_ack()

    def get_ack_sn(self):
        self.lock.acquire()
        ack_sn = self.CS_ack_sn
        self.lock.release()
        return ack_sn

    # end of get_ack_sn()

    def has_data(self):
        self.lock.acquire()
        busy = self.CS_busy
        self.lock.release()
        return busy

    # end of has_data()

    def copy2CS_buf(self, src_buf):
        self.lock.acquire()
        self.CS_buf = src_buf
        self.CS_busy = True
        self.lock.release()

    # end of copy2CS_buf()

    def copy4CS_buf(self):
        self.lock.acquire()
        ret_msg = self.CS_buf
        self.CS_busy = False
        self.lock.release()
        return ret_msg

    # end of copy4CS_buf()

    def wait_data(self):
        with self.condition:
            self.condition.wait()

    # end of wait_data()

    def data_ready(self):
        with self.condition:
            self.condition.notify()

    # end of data_ready()

    def wait_ack(self):
        with self.condition:
            self.condition.wait(self.SocketIdle)

    # end of wait_ack()

    def is_running(self):
        self.lock.acquire()
        running = self.CS_running
        self.lock.release()
        return running

    # end of is_running()

    def accept(self):
        if not self.isServer:
            print('accept() can only be called by server!!')
            exit(1)

        # Wait for SYN
        syn_data, (rip, rport) = self.socket.recvfrom(self.BufSize)
        syn_packet = Protocol()
        syn_packet.parse(syn_data)
        # if not syn_packet.is_flag_set(SYN) and syn_packet.count_flags() is 1:
        #     print("[ERROR] Server accept failed.")
        self.PeerAddr = rip
        self.PeerPort = rport

        if DEBUG:
            print('Connect from IP: ' + str(self.PeerAddr) + ' port: ' + str(self.PeerPort))

        # Send SYN/ACK
        syn_ack_packet = Protocol(flags=SYN | ACK, sequence=syn_packet.sequence + 1, ack_number=syn_packet.sequence + 1)
        syn_ack_data = syn_ack_packet.pack()
        self.socket.sendto(syn_ack_data, (self.PeerAddr, self.PeerPort))

        # Wait for ACK
        ack_data, _ = self.socket.recvfrom(self.BufSize)
        ack_packet = Protocol()
        ack_packet.parse(ack_data)

        if DEBUG:
            print('Connection from: ' + str(self.PeerAddr) + ':' + str(self.PeerPort) + ' established')

        # Create ReceiveDaemon
        self.ReceiveDaemon = ReceiveDaemon(self.socket, self.PeerAddr, self.PeerPort, self)

    # end of accept()

    def connect(self):
        if self.isServer:
            print('connect() can only be called by client!!')
            exit(1)

        # Sending SYN
        syn_packet = Protocol(flags=SYN, sequence=0, ack_number=0)
        syn_data = syn_packet.pack()
        self.socket.sendto(syn_data, (self.PeerAddr, self.PeerPort))

        if DEBUG:
            print('Connect to: ' + str(self.PeerAddr) + ' port: ' + str(self.PeerPort))

        # Receiving SYN/ACK
        syn_ack_data, _ = self.socket.recvfrom(self.BufSize)
        syn_ack_packet = Protocol()
        syn_ack_packet.parse(syn_ack_data)

        # Sending ACK
        ack_packet = Protocol(flags=ACK, sequence=syn_ack_packet.sequence, ack_number=syn_ack_packet.ack_number + 1)
        ack_data = ack_packet.pack()
        self.socket.sendto(ack_data, (self.PeerAddr, self.PeerPort))

        if DEBUG:
            print('Connection to: ' + str(self.PeerAddr) + ':' + str(self.PeerPort) + ' established')

        # Create ReceiveDaemon
        self.ReceiveDaemon = ReceiveDaemon(self.socket, self.PeerAddr, self.PeerPort, self, self.window_size)

    def send(self, msg, enforce=False):
        if len(self.send_window) < self.window_size:
            self.send_window.append(msg)
        elif len(self.send_window) == self.window_size or enforce:
            self.send_status = [False * len(self.send_window)]
            size = self.window_size if not enforce else len(self.send_window)
            for i in range(size):
                packed_data = Protocol(flags=PSH | ACK, dest_port=self.PeerPort, ack_number=i)
                packet = (packed_data, (self.PeerAddr, self.PeerPort))
                self.socket.sendto(*packet)
                ack_thread = threading.Thread(target=self.send_packet, args=(packet, i,), name="send"+str(i))
                ack_thread.start()
            self.send_window.clear()
        # end while

    # end of send()

    def send_packet(self, packet, ack_number):
        while not self.send_status[ack_number]:
            # wait ACK
            self.wait_ack()

            ack_sn = self.get_ack_sn()
            if ack_sn == ack_number + 1:
                self.send_status[ack_number] = True
            elif DEBUG:
                # send message
                self.socket.sendto(*packet)
                print('Send failed !! SN = ' + str(ack_number+1))

    def receive(self):
        sn = self.get_sn_receive()
        if not self.has_data():
            self.wait_data()
        ret_msg = self.copy4CS_buf()
        self.add_sn_receive()
        return ret_msg

    # end of receive()

    def close(self, msg_FIN=None):
        if self.isServer:
            # Server-side: Receive FIN
            # fin_data, _ = self.socket.recvfrom(self.BufSize)
            # fin_packet = Protocol()
            # fin_packet.parse(fin_data)

            # Send ACK for received FIN
            ack_fin_packet = Protocol(flags=ACK, dest_port=self.PeerPort, ack_number=msg_FIN.sequence + 1)
            ack_fin_data = ack_fin_packet.pack()
            self.socket.sendto(ack_fin_data, (self.PeerAddr, self.PeerPort))

            # Send FIN
            fin_packet = Protocol(flags=FIN, dest_port=self.PeerPort)
            fin_data = fin_packet.pack()
            self.socket.sendto(fin_data, (self.PeerAddr, self.PeerPort))

            # Wait for ACK
            ack_data, _ = self.socket.recvfrom(self.BufSize)
            ack_packet = Protocol()
            ack_packet.parse(ack_data)
        else:
            # Client-side: Send FIN
            fin_packet = Protocol(flags=FIN, dest_port=self.PeerPort)
            fin_data = fin_packet.pack()
            self.socket.sendto(fin_data, (self.PeerAddr, self.PeerPort))

            # Wait for ACK
            ack_fin_received = False
            while not ack_fin_received:
                ack_fin_data, _ = self.socket.recvfrom(self.BufSize)
                ack_fin_packet = Protocol()
                ack_fin_packet.parse(ack_fin_data)
                if ack_fin_packet.is_flag_set(ACK):
                    ack_fin_received = True

            # Wait for FIN
            ack_fin_received = False
            while not ack_fin_received:
                ack_fin_data, _ = self.socket.recvfrom(self.BufSize)
                ack_fin_packet = Protocol()
                ack_fin_packet.parse(ack_fin_data)
                if ack_fin_packet.is_flag_set(FIN):
                    ack_fin_received = True

            # Send ACK for received FIN
            ack_packet = Protocol(flags=ACK, dest_port=self.PeerPort, ack_number=ack_fin_packet.sequence + 1)
            ack_data = ack_packet.pack()
            self.socket.sendto(ack_data, (self.PeerAddr, self.PeerPort))
        self.CS_running = False
        time.sleep(1)
        self.socket.close()
        self.ReceiveDaemon.join()

    # end of close()


# end of class SAWSocket


class ReceiveDaemon(threading.Thread):
    def __init__(self, socket, sAddr, sPort, SAWSocket, SlidingWindow=1):
        super().__init__(name='ReceiveDaemon')
        self.socket = socket
        self.peerAddr = sAddr
        self.peerPort = sPort
        self.SAWSocket = SAWSocket
        self.SlidingWindow = SlidingWindow
        self.running = True
        self.start()

    # end of __init__()

    def run(self):
        while self.SAWSocket.is_running():
            # Receive a message
            recv_msg, (rip, rport) = self.socket.recvfrom(self.SAWSocket.BufSize)

            received_packet = Protocol()
            received_packet.parse(recv_msg)  # Parse the received bytes into the Protocol object

            if received_packet.is_flag_set(FIN) and received_packet.count_flags() is 1:
                self.clear()
                self.SAWSocket.close()

            if received_packet.is_flag_set(PSH | ACK) and received_packet.count_flags() is 2:
                if len(self.SAWSocket.receive_window) < self.SlidingWindow:
                    self.SAWSocket.receive_window.append(received_packet.message)
                    msg = Protocol(flags=ACK, ack_number=received_packet.ack_number+1)
                    self.SAWSocket.send(msg)
            if len(self.SAWSocket.receive_window) == self.SlidingWindow or received_packet.is_flag_set(URG | ACK):
                self.clear()

            ack_packet = Protocol(flags=ACK, ack_number=received_packet.ack_number+1)
            ack_packet.sequence = received_packet.ack_number
            ack_packet.ack_number = received_packet.sequence + len(received_packet.message)
            ack_bytes = ack_packet.pack()
            self.socket.sendto(ack_bytes, (self.peerAddr, self.peerPort))
        # end of while
        if DEBUG:
            print('Receive daemon closed()')

        # end of run()

    def clear(self):
        self.SAWSocket.copy2CS_buf(self.SAWSocket.receive_window)
        self.SAWSocket.receive_window.clear()
        print("Buffer flush\n")


# end of class ReceiveD


class Protocol:
    def __init__(self, source_port=0, dest_port=0, sequence=0, ack_number=0, data_offset=5, flags=0, window=0,
                 urgent_ptr=0, options=b'', message=None):
        self.source_port = source_port
        self.dest_port = dest_port
        self.sequence = sequence
        self.ack_number = ack_number
        self.data_offset = data_offset
        self.flags = flags
        self.window = window
        self.checksum = 0  # Placeholder for checksum
        self.urgent_ptr = urgent_ptr
        self.options = options
        self.message = message.encode('utf-8') if isinstance(message, str) else message  # Encode string to bytes

    def pack(self):
        tcp_header = struct.pack('!HHIIHHHH',
                                 self.source_port, self.dest_port,
                                 self.sequence, self.ack_number,
                                 (self.data_offset << 12) | self.flags,
                                 self.window, self.checksum,
                                 self.urgent_ptr)

        packet = tcp_header + self.options + self.message
        self.checksum = self.calculate_checksum(packet)  # Calculate checksum
        tcp_header = struct.pack('!HHIIHHHH',
                                 self.source_port, self.dest_port,
                                 self.sequence, self.ack_number,
                                 (self.data_offset << 12) | self.flags,
                                 self.window, self.checksum,
                                 self.urgent_ptr)
        packet = tcp_header + self.options + self.message
        return packet

    def parse(self, data):
        tcp_header = struct.unpack('!HHIIHHHH', data[:20])
        self.source_port = tcp_header[0]
        self.dest_port = tcp_header[1]
        self.sequence = tcp_header[2]
        self.ack_number = tcp_header[3]
        self.data_offset = (tcp_header[4] >> 12) & 0x0F
        self.flags = tcp_header[4] & 0x3FF
        self.window = tcp_header[5]
        self.checksum = tcp_header[6]
        self.urgent_ptr = tcp_header[7]
        # self.options = data[20:40]  # Assuming options are between 0 and 320 bits (40 bytes)
        self.message = data[20:].decode('utf-8')  # Message starts after header and options

    def calculate_checksum(self, data):
        # Implementation of checksum calculation
        # Placeholder implementation, replace with actual checksum calculation logic
        return 0xFFFF  # Return a placeholder checksum value

    # Helper methods to control flags using defined constants
    def set_flag(self, flag):
        self.flags |= flag

    def clear_flag(self, flag):
        self.flags &= ~flag

    def is_flag_set(self, flag):
        return (self.flags & flag) == flag

    def count_flags(self):
        # Check flags number
        flags = bin(self.flags).count('1')
        return flags


if __name__ == '__main__':
    print('Hello!!')
