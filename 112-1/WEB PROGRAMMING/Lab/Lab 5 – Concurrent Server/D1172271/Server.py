# Coded by Eric Chen, D1172271
# ISTM Purdue
#
# @Copyright /  All right reserved
# DESC: Concurrent Countdown Server

import time
from Library.Core import Networking, Utils


INTERFACE = "0.0.0.0"
PORT = 6666
BACKLOG = 5

# A custom override concurrent server implementation
class CountdownServer(Networking.ConcurrentServer):
    def __init__(self, interface, port, backlog):
        super().__init__(interface, port, backlog)
        self.datatype = None
        self.countdown = None


    # custom transmission loop override
    def transmission_loop(self, connection):
        # proceed countdown in the loop
        while True:
            buffer = self.receive(connection)

            # check if the client dropped connection, causing recv to return None
            if not (buffer):
                print("[WARNING] Client connection dropped abruptly, aborting......\n")
                break

            else:
                self.datatype = buffer[0]
                self.countdown = buffer[1]

            # server response will based on the data type
            if (self.datatype == Utils.EncodeType.INT):
                # debug show
                print("[INFO] Receive: {}".format(self.countdown))

                if (self.countdown > 0): # not reach zero yet
                    if not (self.send(connection, Utils.EncodeType.INT, self.countdown - 1)):
                        break

                elif (self.countdown == 0): # just reached zero now
                    self.send(connection, Utils.EncodeType.STR, "[TERMINATE]")
                    break    

            elif (self.datatype == Utils.EncodeType.STR):
                if (self.countdown == "[TERMINATE]"):
                    print("[INFO] Received the \'[TERMINATE]\' command from client, closing conenction......\n")
                    break

                else:
                    print("[WARNING] Got an unrecognized command \'{}\', ignoring......\n".format(self.countdown))

        return


# EP
def main():
    server = CountdownServer(INTERFACE, PORT, BACKLOG)
    print("[INFO] Starting the concurrent server on {interface}:{port}......\n".format(interface=INTERFACE, port=PORT))
    
    # start concurrent server
    server.start_service()

    # stop concurrent server
    time.sleep(100)
    server.stop_service()
    return


if __name__ == "__main__":
    main()