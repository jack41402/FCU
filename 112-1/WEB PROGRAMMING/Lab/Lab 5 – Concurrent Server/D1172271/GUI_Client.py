# Coded by Eric Chen, D1172271
# ISTM Purdue
#
# @Copyright /  All right reserved
# DESC: GUI Countdown Client


from PyQt6.QtWidgets import QApplication, QMainWindow
from Library.GUI import Panel


# DESC: The all-in-one class that hanles everything
class MainWindow(QMainWindow):
	def __init__(self):
		super().__init__()
		self.panel = Panel.Client_Panel()
		self.setCentralWidget(self.panel)


def main():
	app = QApplication([])
	window = MainWindow()
	window.show()
	app.exec()
	return


if __name__ == "__main__":
	main()