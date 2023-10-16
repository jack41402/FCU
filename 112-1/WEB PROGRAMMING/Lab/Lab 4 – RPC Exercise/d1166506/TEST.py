import sys
from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QScrollArea, QSizePolicy, QLayout
from UI import comment  # Assuming you have saved the form in a file named comment_form.py

app = QApplication(sys.argv)
window = QWidget()
window.setWindowTitle("Scroll Area Example")
window.setGeometry(100, 100, 400, 400)

# Create a container widget and layout to hold the forms
container_widget = QWidget()
container_layout = QVBoxLayout()
container_layout.setSpacing(10)  # Adjust the spacing as needed

for i in range(10):
    # Create instances of the Ui_Form
    form = comment.Ui_Form()
    form_widget = QWidget()
    form.setupUi(form_widget)
    form.Comment_label.setFixedWidth(300)
    form.Comment_label.setText("Test message in scroll area" * i)
    form.Floor_Time_label.setText("B%d, %d days ago" % (i, 10-i))
    form_widget.setSizePolicy(QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum)  # Set the size policy
    form_widget.setMinimumHeight(65+form.Comment_label.sizeHint().height())
    print(65+form.Comment_label.sizeHint().height())
    container_layout.addWidget(form_widget)

container_layout.setSizeConstraint(QLayout.SizeConstraint.SetMaximumSize)
container_widget.setLayout(container_layout)

# Create a scroll area and set the container widget as its content
scroll_area = QScrollArea()
scroll_area.setMinimumSize(350, 300)
scroll_area.setWidgetResizable(True)  # Allows the scroll area to resize its contents

scroll_area.setWidget(container_widget)

window_layout = QVBoxLayout()
window_layout.addWidget(scroll_area)
window.setLayout(window_layout)

window.show()
sys.exit(app.exec())
