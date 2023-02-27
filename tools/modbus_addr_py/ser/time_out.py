import sys
from PyQt5 import QtCore, QtGui
from PyQt5.QtCore import QThread, QTimer
from PyQt5.QtWidgets import QApplication, QMessageBox, QWidget, QPushButton

class TimerMessageBox(QMessageBox):
    def collectProcessData(self):
        self.setWindowTitle("wait")
        self.time_to_wait = 3
        self.setText("wait (closing automatically in {0} secondes.)".format(timeout))
        self.setStandardButtons(QMessageBox.NoButton)
        self.timer = QTimer(self)
        self.timer.setInterval(1000)
        self.timer.timeout.connect(self.changeContent)
        self.timer.start()

    def __init__(self, timeout=3, parent=None):
        QThread.__init__(self)   #
        super(TimerMessageBox, self).__init__(parent)
        self.dataCollectionTimer = QTimer()
        self.dataCollectionTimer.moveToThread(self)
        self.dataCollectionTimer.timeout.connect(self.collectProcessData)


    def changeContent(self):
        self.time_to_wait -= 1
        self.setText("wait (closing automatically in {0} secondes.)".format(self.time_to_wait))
        if self.time_to_wait <= 0:
            self.close()

    def closeEvent(self, event):
        self.timer.stop()
        event.accept()
        pass
