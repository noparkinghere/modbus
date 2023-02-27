import sys
import time

from PyQt5 import QtCore, QtGui
from PyQt5.QtCore import QThread, QTimer, QEventLoop
from PyQt5.QtWidgets import QApplication, QMessageBox, QWidget, QPushButton


# from PyQt5.QtWidgets import QMainWindow, QApplication, QDialog

class TimerMessageBox(QMessageBox):
    def __init__(self, timeout=3, parent=None):
        super(TimerMessageBox, self).__init__(parent)
        self.setWindowTitle("wait")
        self.time_to_wait = timeout
        self.setText("wait (closing automatically in {0} secondes.)".format(timeout))
        self.setStandardButtons(QMessageBox.NoButton)
        self.timer = QtCore.QTimer(self)
        self.timer.setInterval(1000)
        self.timer.timeout.connect(self.changeContent)
        self.timer.start()

    def changeContent(self):
        self.time_to_wait -= 1
        self.setText("wait (closing automatically in {0} secondes.)".format(self.time_to_wait))
        if self.time_to_wait <= 0:
            self.close()

    def closeEvent(self, event):
        self.timer.stop()
        event.accept()
        pass

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = TimerMessageBox()
    ex.show()
    sys.exit(app.exec_())


#
# class Example(QWidget):
#     def __init__(self):
#         super(Example, self).__init__()
#         btn = QPushButton('Button', self)
#         btn.resize(btn.sizeHint())
#         btn.move(50, 50)
#         self.setWindowTitle('Example')
#         btn.clicked.connect(self.warning)
#
#     def warning(self):
#         messagebox = TimerMessageBox(5, self)
#         messagebox.exec_()
#
#
# def main():
#     app = QApplication(sys.argv)
#     ex = Example()
#     ex.show()
#     sys.exit(app.exec_())
#
#


