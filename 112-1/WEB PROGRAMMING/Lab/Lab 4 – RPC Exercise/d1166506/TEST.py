# Student ID: D1166506
# Name: 周嘉禾
from PyQt6 import QtWidgets
from controller import Login_controller

if __name__ == '__main__':
    import sys
    app = QtWidgets.QApplication(sys.argv)
    LoginWindow = Login_controller(app)
    LoginWindow.show()
    sys.exit(app.exec())
