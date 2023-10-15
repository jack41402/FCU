from PyQt6 import QtCore
from PyQt6.QtWidgets import QApplication, QMainWindow, QScrollArea, QWidget, QVBoxLayout, QLabel

class ScrollableLabelArea(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Scrollable Label Example")
        self.setGeometry(100, 100, 400, 600)

        main_widget = QWidget(self)
        self.setCentralWidget(main_widget)

        # Create a scroll area
        scroll_area = QScrollArea(main_widget)
        scroll_area.setWidgetResizable(True)
        main_layout = QVBoxLayout(main_widget)
        main_layout.addWidget(scroll_area)

        # Create a content widget within the scroll area
        content_widget = QWidget()
        scroll_area.setWidget(content_widget)
        content_layout = QVBoxLayout(content_widget)

        # Header label
        header_label = QLabel("Header Text")
        header_label.setAlignment(QtCore.Qt.AlignmentFlag.AlignCenter)
        content_layout.addWidget(header_label)

        # Content label
        content_label = QLabel("Content Text")
        content_label.setAlignment(QtCore.Qt.AlignmentFlag.AlignCenter)
        content_layout.addWidget(content_label)

        # Comment label
        comment_label = QLabel("Comment Text")
        comment_label.setAlignment(QtCore.Qt.AlignmentFlag.AlignCenter)
        content_layout.addWidget(comment_label)

        # Reply label
        reply_label = QLabel("Reply Text")
        reply_label.setAlignment(QtCore.Qt.AlignmentFlag.AlignCenter)
        content_layout.addWidget(reply_label)

        # Adjust label text dynamically
        # For example, change the content label text
        new_content_text = "New Content Text"
        content_label.setText(new_content_text)

if __name__ == "__main__":
    app = QApplication([])
    window = ScrollableLabelArea()
    window.show()
    app.exec()
