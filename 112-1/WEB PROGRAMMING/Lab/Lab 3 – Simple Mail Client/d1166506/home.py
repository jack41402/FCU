import sys
from PyQt6 import QtWidgets
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QTextCursor
from PyQt6.QtWidgets import (QApplication, QMainWindow, QTableWidget, QTableWidgetItem, QVBoxLayout, QWidget,
                             QSplitter, QHeaderView, QHBoxLayout, QCheckBox, QTextBrowser, QAbstractItemView,
                             QPushButton)


class Mailbox(object):
    def setupUi(self, MainWindow):
        MainWindow.setWindowTitle('Mailbox')
        MainWindow.setGeometry(100, 100, 1000, 600)

        # Create mail table
        self.mail_table = QTableWidget(MainWindow)
        self.mail_table.setShowGrid(False)
        self.mail_table.setSortingEnabled(True)
        self.mail_table.setSelectionBehavior(QTableWidget.SelectionBehavior.SelectRows)
        self.mail_table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)

        # Hide horizontal header, and only show vertical header
        header = QHeaderView(Qt.Orientation.Horizontal, self.mail_table)
        self.mail_table.setHorizontalHeader(header)
        header.setSectionsClickable(True)  # 允许点击表头

        self.mail_table.setColumnCount(5)
        self.mail_table.setHorizontalHeaderLabels(['', 'From', 'Subject', 'Date', 'Time'])

        # Create text browser to show mail content
        self.mail_content = QTextBrowser(MainWindow)
        self.mail_content.setReadOnly(True)

        # Create select all checkbox
        self.select_all_checkbox = QCheckBox('Select All', MainWindow)
        self.select_all_checkbox.setChecked(False)  # 设置"Select All"复选框初始状态为不选中

        # Create horizontal layout to place checkbox
        checkbox_layout = QHBoxLayout()
        checkbox_layout.addWidget(self.select_all_checkbox)

        # Create splitter between mail table and mail content
        splitter = QSplitter(Qt.Orientation.Horizontal)
        splitter.addWidget(self.mail_table)
        splitter.addWidget(self.mail_content)

        # Create horizontal layout to place mail table
        main_layout = QVBoxLayout()
        main_layout.addLayout(checkbox_layout)
        main_layout.addWidget(splitter)

        # Create central widget as main layout
        central_widget = QWidget()
        central_widget.setLayout(main_layout)
        MainWindow.setCentralWidget(central_widget)

        # Add example mails
        # self.add_mail('Sender 1', 'Subject 1', 'Date 1', 'Time 1', 'Content 1')
        # self.add_mail('Sender 2', 'Subject 2', 'Date 2', 'Time 2', 'Content 2')
        # self.add_mail('Sender 3', 'Subject 3', 'Date 3', 'Time 3', 'Content 3')

        # Adjust checkbox width
        self.mail_table.setColumnWidth(0, 20)


if __name__ == '__main__':
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Mailbox()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec())
