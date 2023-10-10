# Student ID: D1166506
# Name: 周嘉禾
from PyQt6 import QtWidgets
from controller import Login_controller
from rpc import server

if __name__ == '__main__':
    import sys

    server = server.Server("127.0.0.1", 6666)
    server.start()
    app = QtWidgets.QApplication(sys.argv)
    LoginWindow = Login_controller()
    LoginWindow.show()
    server.close()
    sys.exit(app.exec())
