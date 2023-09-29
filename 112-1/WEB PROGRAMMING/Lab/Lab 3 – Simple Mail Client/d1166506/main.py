####################################################
#  Network Programming - Unit 3 Application based on TCP         
#  Program Name: pop3client.py                                      			
#  The program is a simple POP3 client.            		
#  2021.08.03                                                   									
####################################################
import sys
import socket
from getpass import getpass
import command

PORT = 110
BUFF_SIZE = 1024  # Receive buffer size


def ParseMessage(msg):
    line = []
    newstring = ''
    for i in range(len(msg)):
        if (msg[i] == '\n'):
            line.append(newstring)
            newstring = ''
        else:
            newstring += msg[i]
    return line


# end ParseMessage

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 pop3client.py ServerIP")
        exit(1)

    # Get server IP
    serverIP = socket.gethostbyname(sys.argv[1])

    # Get username & password
    name = input('Username: ')
    password = getpass('Password: ')

    # Create a TCP client socket
    cSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('Connecting to %s port %s' % (serverIP, PORT))
    cSocket.connect((serverIP, PORT))

    mail = command.Command()

    for i in range(1):
        try:
            # receive server greeting message
            reply = cSocket.recv(BUFF_SIZE).decode('utf-8')
            print('Receive message: %s' % reply)
            if reply[0] != '+':
                break

            # Username
            cmd = 'USER ' + name + '\r\n'
            cSocket.send(cmd.encode('utf-8'))
            reply = cSocket.recv(BUFF_SIZE).decode('utf-8')
            print('Receive message: %s' % reply)
            if reply[0] != '+':
                break

            # Password
            cmd = 'PASS ' + password + '\r\n'
            cSocket.send(cmd.encode('utf-8'))
            reply = cSocket.recv(BUFF_SIZE).decode('utf-8')
            print('Receive message: %s' % reply)
            if reply[0] != '+':
                break

            # List [Method 1]
            cmd = 'LIST\r\n'
            cSocket.send(cmd.encode('utf-8'))
            reply = cSocket.recv(BUFF_SIZE).decode('utf-8')
            print('Receive message: %s' % reply)
            if reply[0] != '+':
                break

            # Count mails
            line = ParseMessage(reply)
            mail_count = int(len(line) - 2)
            print('Mailbox has %d mails\n' % mail_count)

            # Delete mail
            # if mail_count >= 1:
            #     while True:
            #         mail_number = int(input('Enter the number of the mail you want to delete:'))
            #         if not str(mail_number).isdigit():
            #             continue
            #         elif not 1 <= mail_number <= mail_count:
            #             continue
            #         else:
            #             mail_number = int(mail_number)
            #             break
            #     cSocket.send(mail.delete(mail_number).encode('utf-8'))
            #     reply = cSocket.recv(BUFF_SIZE).decode('utf-8')
            #     print('Receive message: %s' % reply)
            #     if reply[0] != '+':
            #         break

            # List mail information
            if mail_count >= 1:
                while True:
                    mail_number = int(input('Enter the number of the mail you want to read:'))
                    if not str(mail_number).isdigit():
                        continue
                    elif not 1 <= mail_number <= mail_count:
                        continue
                    else:
                        mail_number = int(mail_number)
                        break
                cSocket.send(mail.retrive(mail_number).encode('utf-8'))
                reply = cSocket.recv(BUFF_SIZE).decode('utf-8')
                print('Receive message: %s' % reply)
                if reply[0] != '+':
                    break

            # Quit
            cmd = 'QUIT\r\n'
            cSocket.send(cmd.encode('utf-8'))

        except socket.error as e:
            print('Socket error: %s' % str(e))
        except Exception as e:
            print('Other exception: %s' % str(e))
    # end for

    print('Closing connection.')
    cSocket.close()


# end of main


if __name__ == '__main__':
    main()
