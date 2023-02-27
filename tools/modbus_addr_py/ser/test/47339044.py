import sys
import PyQt5
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *

# This is our window from QtCreator
import mainwindow_auto


class DataCaptureThread(QThread):
    def collectProcessData(self):
        print ("Collecting Process Data")

    def __init__(self, *args, **kwargs):
        QThread.__init__(self, *args, **kwargs)
        self.dataCollectionTimer = QTimer()
        self.dataCollectionTimer.moveToThread(self)
        self.dataCollectionTimer.timeout.connect(self.collectProcessData)

    def run(self):
        self.dataCollectionTimer.start(1000)
        loop = QEventLoop()
        loop.exec_()


class MainWindow(QMainWindow, mainwindow_auto.Ui_MainWindow):
    def __init__(self):
        super(self.__class__, self).__init__()
        self.setupUi(self) # gets defined in the UI file
        self.btnStart.clicked.connect(self.pressedStartBtn)
        self.btnStop.clicked.connect(self.pressedStopBtn)

    def pressedStartBtn(self):
        self.lblAction.setText("STARTED")
        self.dataCollectionThread = DataCaptureThread()
        self.dataCollectionThread.start()
        while True:
            # print("ok")
            pass
    def pressedStopBtn(self):
        self.lblAction.setText("STOPPED")
        self.dataCollectionThread.terminate()


def main():
     # a new app instance
     app = QApplication(sys.argv)
     form = MainWindow()
     form.show()
     sys.exit(app.exec_())

if __name__ == "__main__":
     main()