# Student ID: D1166506
# Name: 周嘉禾
from PyQt6 import QtWidgets
from controller import MainWindow_controller

if __name__ == '__main__':
    import sys

    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow_controller()
    window.show()
    sys.exit(app.exec())
