import re

from PyQt5 import QtCore
from PyQt5.QtCore import QTimer
from PyQt5.QtCore import Qt

from designer.UI_hint import Ui_Form_Hint
from ser import glob
import sys

from PyQt5.QtWidgets import QMainWindow, QApplication, QDialog, QMessageBox

from designer.UI_serial import Ui_Form_serial



class Hint(QDialog):
    diameter = float()
    theorysl = float()
    realsl = float()
    angle = float()
    sounddelay1 = float()
    sounddelay2 = float()
    fixedpress = float()

    def __init__(self):
        """
            初始化操作，创建相关触发联系
        :param parent:
        """
        super().__init__()
        # self.mw = mw
        self.setWindowFlags(Qt.WindowStaysOnTopHint)  # 子窗口置顶
        self.form = Ui_Form_Hint()
        self.form.setupUi(self)
        self.show()
        # # 设置实例
        # self.SetItems()
        # 设置信号与槽
        # self.CreateSignalSlot()

    def SetItems(self):
        self.pushButton.setText(Ui_Form_Hint._translate("Form_Hint", "读取完毕"))


    def CreateSignalSlot(self):
        self.form.pushButton.clicked.connect(self.close)
        # print("111111111111111111111111")

    def close(self):
        self.close()
        # print("1111111111")

    def SetItems(self):
        pass

    def showdata(self):
        pass

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Hint()
    ex.show()
    sys.exit(app.exec_())