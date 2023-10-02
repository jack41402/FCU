import sys
from PyQt6.QtCore import Qt, QSortFilterProxyModel
from PyQt6.QtGui import QTextCursor, QStandardItem, QStandardItemModel
from PyQt6.QtWidgets import QApplication, QMainWindow, QTableView, QTextEdit, QVBoxLayout, QWidget, QSplitter, QHeaderView, QStyledItemDelegate, QHBoxLayout, QCheckBox


class CheckboxDelegate(QStyledItemDelegate):
    def initStyleOption(self, option, index):
        super().initStyleOption(option, index)
        if index.column() == 0:
            option.displayAlignment = Qt.AlignmentFlag.AlignCenter
            option.decorationAlignment = Qt.AlignmentFlag.AlignCenter


class MailboxApp(QMainWindow):
    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.setWindowTitle('Mailbox')
        self.setGeometry(100, 100, 1000, 600)

        # 创建邮件表格
        self.mail_table = QTableView(self)
        self.mail_table.setSelectionBehavior(QTableView.SelectionBehavior.SelectRows)  # 设置选择行为
        self.mail_table.setShowGrid(False)  # 隐藏网格线
        self.mail_table.doubleClicked.connect(self.show_mail_content)

        # 隐藏水平标头，只显示垂直标头
        self.mail_table.setHorizontalHeader(QHeaderView(Qt.Orientation.Horizontal, self.mail_table))

        # 创建表格模型
        self.model = QStandardItemModel(self)
        self.model.setHorizontalHeaderLabels(['', 'From', 'Subject', 'Date', 'Time'])

        # 将表格模型设置给表格视图
        self.mail_table.setModel(self.model)

        # 设置复选框列宽度并固定
        self.mail_table.setColumnWidth(0, 30)
        self.mail_table.horizontalHeader().setSectionResizeMode(0, QHeaderView.ResizeMode.Fixed)

        # 创建右侧显示邮件内容的文本框
        self.mail_content = QTextEdit(self)
        self.mail_content.setReadOnly(True)

        # 创建底部的选择框
        self.select_all_checkbox = QCheckBox('Select All', self)

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

        # 调整行高以确保复选框位于行的中间
        self.adjust_row_height()

        # 使用自定义委托将复选框放置在行号旁边
        delegate = CheckboxDelegate(self)
        self.mail_table.setItemDelegateForColumn(0, delegate)

        # 禁止编辑表格内容
        self.mail_table.setEditTriggers(QTableView.EditTrigger.NoEditTriggers)

        # 连接"Select All"复选框的状态改变信号
        self.select_all_checkbox.stateChanged.connect(self.toggle_select_all)

        # 设置"Select All"复选框初始状态为选中
        self.select_all_checkbox.setChecked(True)

        # 初始化时全选所有邮件
        self.toggle_select_all(True)

        # 创建排序代理模型
        self.proxy_model = QSortFilterProxyModel(self)
        self.proxy_model.setSourceModel(self.model)
        self.mail_table.setModel(self.proxy_model)
        self.mail_table.setSortingEnabled(True)

    def add_mail(self, sender, subject, date, time, content):
        row_position = self.model.rowCount()
        self.model.insertRow(row_position)

        # 创建复选框
        checkbox_item = QStandardItem()
        checkbox_item.setCheckable(True)
        self.model.setItem(row_position, 0, checkbox_item)

        # 创建其他列项目
        self.model.setItem(row_position, 1, QStandardItem(sender))
        self.model.setItem(row_position, 2, QStandardItem(subject))
        self.model.setItem(row_position, 3, QStandardItem(date))
        self.model.setItem(row_position, 4, QStandardItem(time))

        # 将Content数据存储在模型中
        self.model.setData(self.model.index(row_position, 1), content, Qt.ItemDataRole.UserRole)

    def show_mail_content(self, index):
        row = index.row()
        content = self.model.data(self.model.index(row, 1), Qt.ItemDataRole.UserRole)  # 获取Content数据
        self.mail_content.clear()
        self.mail_content.insertPlainText(content)
        self.mail_content.moveCursor(QTextCursor.MoveOperation.Start)  # 移动光标到文本开头

    def adjust_row_height(self):
        for row in range(self.model.rowCount()):
            index = self.model.index(row, 0)
            checkbox_item = self.model.itemFromIndex(index)
            checkbox_height = checkbox_item.sizeHint().height()
            self.mail_table.setRowHeight(row, checkbox_height)

    def toggle_select_all(self, state):
        for row in range(self.model.rowCount()):
            item = self.model.item(row, 0)
            if item is not None:
                if state == Qt.CheckState.Checked:
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
