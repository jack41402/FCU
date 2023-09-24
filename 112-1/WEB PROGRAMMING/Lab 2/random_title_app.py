from PyQt6.QtWidgets import QApplication, QMainWindow, QPushButton
from PyQt6.QtCore import QSize
from random import choice

random_titles = [
    'My App',
    'My App',
    'Still My App',
    'Still My App',
    'What on earth',
    'What on earth',
    'This is surprising',
    'This is surprising',
    'Game Over'
]


class MainWindow(QMainWindow):
	# creating class attribute
	Class_Status = True

	def __init__(self):
		# creating instance attribute
		self.Instance_Status = True

		super().__init__()
		self.button = QPushButton("Push Me !!")
		self.button.pressed.connect(self.On_Press)
		self.windowTitleChanged.connect(self.On_Title_Change)

		self.setWindowTitle("Random Titles")
		self.setCentralWidget(self.button)
		self.setFixedSize(QSize(400, 300))
		self.show()

	def On_Press(self):
		new_title = choice(random_titles)
		self.setWindowTitle(new_title)
		return

	def On_Title_Change(self, data):
		print("[TRACE] Setting title to:", data)
		
		if (data == "Game Over"):
			print("[WARNING] Game over, locking down button......")
			self.button.setText("Game Over Bro !!")
			self.button.setEnabled(False)

		return

def main():
	app = QApplication([])
	window = MainWindow()
	app.exec()
	return

if __name__ == "__main__":
	main()