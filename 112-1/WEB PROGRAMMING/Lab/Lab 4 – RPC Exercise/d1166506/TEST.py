from PyQt6.QtWidgets import QApplication, QWidget, QScrollArea, QVBoxLayout, QSizePolicy
from UI import comment


class CommentWidget(QWidget):
    def __init__(self, author, content, parent=None):
        super().__init__(parent)
        self.ui = comment.Ui_Form()
        self.ui.setupUi(self)
        self.initUI(author, content)

    def initUI(self, author, content):
        self.ui.Author_label.setText(author)
        self.ui.Comment_label.setText(content)
        self.ui.Comment_label.setMaximumWidth(300)
        self.ui.Comment_label.setScaledContents(True)
        self.ui.Comment_label.setFixedSize(self.ui.Comment_label.sizeHint())


if __name__ == "__main__":
    import sys

    app = QApplication(sys.argv)
    widget = CommentWidget("John Doe", "This is a very long comment. " * 20)

    scroll_area = QScrollArea()
    scroll_area.setWidget(widget)
    scroll_area.setMinimumWidth(300)
    scroll_area.setMinimumHeight(300)
    scroll_area.setWidgetResizable(True)

    layout = QVBoxLayout()
    layout.addWidget(scroll_area)

    main_widget = QWidget()
    main_widget.setLayout(layout)
    main_widget.show()

    sys.exit(app.exec())
