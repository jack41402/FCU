# Form implementation generated from reading ui file 'register.ui'
#
# Created by: PyQt6 UI code generator 6.5.2
#
# WARNING: Any manual changes made to this file will be lost when pyuic6 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt6 import QtCore, QtGui, QtWidgets


class Ui_Register(object):
    def setupUi(self, Register):
        Register.setObjectName("Register")
        Register.resize(400, 350)
        self.Username_lineEdit = QtWidgets.QLineEdit(parent=Register)
        self.Username_lineEdit.setGeometry(QtCore.QRect(50, 60, 311, 31))
        self.Username_lineEdit.setObjectName("Username_lineEdit")
        self.Username_label = QtWidgets.QLabel(parent=Register)
        self.Username_label.setGeometry(QtCore.QRect(50, 40, 91, 16))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(12)
        self.Username_label.setFont(font)
        self.Username_label.setAlignment(QtCore.Qt.AlignmentFlag.AlignLeading|QtCore.Qt.AlignmentFlag.AlignLeft|QtCore.Qt.AlignmentFlag.AlignVCenter)
        self.Username_label.setObjectName("Username_label")
        self.Password_lineEdit = QtWidgets.QLineEdit(parent=Register)
        self.Password_lineEdit.setGeometry(QtCore.QRect(50, 120, 311, 31))
        self.Password_lineEdit.setEchoMode(QtWidgets.QLineEdit.EchoMode.Password)
        self.Password_lineEdit.setObjectName("Password_lineEdit")
        self.Password_label = QtWidgets.QLabel(parent=Register)
        self.Password_label.setGeometry(QtCore.QRect(50, 100, 91, 16))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(12)
        self.Password_label.setFont(font)
        self.Password_label.setAlignment(QtCore.Qt.AlignmentFlag.AlignLeading|QtCore.Qt.AlignmentFlag.AlignLeft|QtCore.Qt.AlignmentFlag.AlignVCenter)
        self.Password_label.setObjectName("Password_label")
        self.Register_button = QtWidgets.QPushButton(parent=Register)
        self.Register_button.setGeometry(QtCore.QRect(50, 240, 311, 31))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(12)
        self.Register_button.setFont(font)
        self.Register_button.setObjectName("Register_button")
        self.Already_have_an_account_label = QtWidgets.QLabel(parent=Register)
        self.Already_have_an_account_label.setGeometry(QtCore.QRect(80, 290, 181, 21))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(11)
        self.Already_have_an_account_label.setFont(font)
        self.Already_have_an_account_label.setAlignment(QtCore.Qt.AlignmentFlag.AlignRight|QtCore.Qt.AlignmentFlag.AlignTrailing|QtCore.Qt.AlignmentFlag.AlignVCenter)
        self.Already_have_an_account_label.setObjectName("Already_have_an_account_label")
        self.Login_label = QtWidgets.QLabel(parent=Register)
        self.Login_label.setGeometry(QtCore.QRect(270, 290, 51, 21))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(11)
        self.Login_label.setFont(font)
        self.Login_label.setAlignment(QtCore.Qt.AlignmentFlag.AlignLeading|QtCore.Qt.AlignmentFlag.AlignLeft|QtCore.Qt.AlignmentFlag.AlignVCenter)
        self.Login_label.setObjectName("Login_label")
        self.Confirm_Password_label = QtWidgets.QLabel(parent=Register)
        self.Confirm_Password_label.setGeometry(QtCore.QRect(50, 160, 141, 16))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(12)
        self.Confirm_Password_label.setFont(font)
        self.Confirm_Password_label.setAlignment(QtCore.Qt.AlignmentFlag.AlignLeading|QtCore.Qt.AlignmentFlag.AlignLeft|QtCore.Qt.AlignmentFlag.AlignVCenter)
        self.Confirm_Password_label.setObjectName("Confirm_Password_label")
        self.Confirm_Password_lineEdit = QtWidgets.QLineEdit(parent=Register)
        self.Confirm_Password_lineEdit.setGeometry(QtCore.QRect(50, 180, 311, 31))
        self.Confirm_Password_lineEdit.setEchoMode(QtWidgets.QLineEdit.EchoMode.Password)
        self.Confirm_Password_lineEdit.setObjectName("Confirm_Password_lineEdit")

        self.retranslateUi(Register)
        QtCore.QMetaObject.connectSlotsByName(Register)

    def retranslateUi(self, Register):
        _translate = QtCore.QCoreApplication.translate
        Register.setWindowTitle(_translate("Register", "Register"))
        self.Username_label.setText(_translate("Register", "Username"))
        self.Password_label.setText(_translate("Register", "Password"))
        self.Register_button.setText(_translate("Register", "Register"))
        self.Already_have_an_account_label.setText(_translate("Register", "Already have an account?"))
        self.Login_label.setText(_translate("Register", "<a href=\"register\">Sign in</a>\n"
""))
        self.Confirm_Password_label.setText(_translate("Register", "Confirm Password"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Register = QtWidgets.QWidget()
    ui = Ui_Register()
    ui.setupUi(Register)
    Register.show()
    sys.exit(app.exec())
