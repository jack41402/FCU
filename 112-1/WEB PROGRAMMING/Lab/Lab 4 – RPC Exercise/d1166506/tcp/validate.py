from UI import login
import IPy

ui = login.Ui_Login()


class Validate:
    # valid_warning = pyqtSignal(str, str)

    def __init__(self):
        self.ip = None
        self.port = None
        self.num = None

    def check_ip(self, address: str):
        if not address:
            print("[ERROR] IP ADDRESS CAN'T BE EMPTY.\n")
            # self.valid_warning.emit("critical", "[ERROR] IP ADDRESS CAN'T BE EMPTY.")
            return False
        if address == "localhost":
            address = "127.0.0.1"
        try:
            IPy.IP(address)
            print("[INFO] IP is correct.\n")
            self.ip = address
            return True
        except Exception as e:
            print("Other exception: %s" % str(e))
            print("[ERROR] WRONG IP ADDRESS.\n")
            return False

    def check_port(self, port: int):
        if not port:
            print("[ERROR] PORT CAN'T BE EMPTY.\n")
            return False
        else:
            port = int(port)

        if not str(port).isdigit():
            print("[ERROR] PORT ISN'T A INTEGER.\n")
            print("[INFO] Port number should be 1~65535.\n")
            return False
        elif not 1 <= port <= 65535:
            print("[ERROR] PORT IS OUT OF RANGE.")
            print("[INFO] Port number should be 1~65535.\n")
            return False
        else:
            print("[INFO] PORT is correct.\n")
            self.port = port
            return True

    def checker(self, msg_IP_Address: str, msg_Server_Port: int):
        if not self.check_ip(msg_IP_Address):
            ui.lineEdit_IP_Address.setText("")
            return False
        if not self.check_port(msg_Server_Port):
            ui.lineEdit_Server_Port.setText("")
            return False

        print("IP: %s" % self.ip)
        print("PORT: %s" % self.port)
        return True
