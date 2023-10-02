import sys
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QTextCursor
from PyQt6.QtWidgets import (QApplication, QMainWindow, QTableWidget, QTableWidgetItem, QVBoxLayout, QWidget,
                             QSplitter, QHeaderView, QHBoxLayout, QCheckBox, QTextBrowser, QAbstractItemView)


class MailboxApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Mailbox')
        self.setGeometry(100, 100, 1000, 600)

        # 创建邮件表格
        self.mail_table = QTableWidget(self)
        self.mail_table.setShowGrid(False)
        self.mail_table.setSortingEnabled(True)
        self.mail_table.setSelectionBehavior(QTableWidget.SelectionBehavior.SelectRows)
        self.mail_table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)
        self.mail_table.doubleClicked.connect(self.show_mail_content)

        # 隐藏水平标头，只显示垂直标头
        header = QHeaderView(Qt.Orientation.Horizontal, self.mail_table)
        self.mail_table.setHorizontalHeader(header)
        header.setSectionsClickable(True)  # 允许点击表头

        self.mail_table.setColumnCount(5)
        self.mail_table.setHorizontalHeaderLabels(['', 'From', 'Subject', 'Date', 'Time'])

        # 创建右侧显示邮件内容的文本框
        self.mail_content = QTextBrowser(self)
        self.mail_content.setReadOnly(True)

        # 创建底部的选择框
        self.select_all_checkbox = QCheckBox('Select All', self)
        self.select_all_checkbox.setChecked(False)  # 设置"Select All"复选框初始状态为不选中

        # 创建一个水平布局用于放置选择框和表格
        checkbox_layout = QHBoxLayout()
        checkbox_layout.addWidget(self.select_all_checkbox)

        # 创建可调整大小的分隔线
        splitter = QSplitter(Qt.Orientation.Horizontal)
        splitter.addWidget(self.mail_table)
        splitter.addWidget(self.mail_content)

        # 创建一个垂直布局用于放置选择框、表格和分隔线
        main_layout = QVBoxLayout()
        main_layout.addLayout(checkbox_layout)
        main_layout.addWidget(splitter)

        # 创建一个容器部件，将垂直布局设置为主窗口的中心部件
        central_widget = QWidget()
        central_widget.setLayout(main_layout)
        self.setCentralWidget(central_widget)

        # 添加一些示例邮件
        self.add_mail('Sender 1', 'Subject 1', 'Date 1', 'Time 1', 'Content 1')
        self.add_mail('Sender 2', 'Subject 2', 'Date 2', 'Time 2', 'Content 2')
        self.add_mail('Sender 3', 'Subject 3', 'Date 3', 'Time 3', 'Content 3')

        # 设置选择框列宽度较小
        self.mail_table.setColumnWidth(0, 20)

        # 连接"Select All"复选框的状态改变信号
        self.select_all_checkbox.stateChanged.connect(self.toggle_select_all)

    def add_mail(self, sender, subject, date, time, content):
        row_position = self.mail_table.rowCount()
        self.mail_table.insertRow(row_position)

        # 创建选择框
        item = QTableWidgetItem()
        item.setCheckState(Qt.CheckState.Unchecked)
        self.mail_table.setItem(row_position, 0, item)

        # 创建 "From" 列项目
        from_item = QTableWidgetItem(sender)
        self.mail_table.setItem(row_position, 1, from_item)

        # 创建其他列项目
        self.mail_table.setItem(row_position, 2, QTableWidgetItem(subject))
        self.mail_table.setItem(row_position, 3, QTableWidgetItem(date))
        self.mail_table.setItem(row_position, 4, QTableWidgetItem(time))

        # 将 Content 数据存储在模型中
        # 获取表格中的项目
        item = self.mail_table.item(row_position, 1)

        # 设置项目的数据
        item.setData(Qt.ItemDataRole.UserRole, content)

    def show_mail_content(self, index):
        row = index.row()
        content_item = self.mail_table.item(row, 1)
        content = content_item.data(Qt.ItemDataRole.UserRole)  # 获取 Content 数据
        self.mail_content.clear()
        self.mail_content.insertPlainText(content)
        self.mail_content.moveCursor(QTextCursor.MoveOperation.Start)  # 移动光标到文本开头

    def toggle_select_all(self):
        for row in range(self.mail_table.rowCount()):
            item = self.mail_table.item(row, 0)
            if item is not None:
                if self.select_all_checkbox.checkState() == Qt.CheckState.Checked:
                    item.setCheckState(Qt.CheckState.Checked)
                else:
                    item.setCheckState(Qt.CheckState.Unchecked)


def main():
    app = QApplication(sys.argv)
    ex = MailboxApp()
    ex.show()
    sys.exit(app.exec())


if __name__ == '__main__':
    main()
