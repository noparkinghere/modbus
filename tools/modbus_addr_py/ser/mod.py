"""
        Created on 2019/12/19 21:01
        ————————————————————————————————————————————————————————————————————
        @File Name            :    mod.py
        @Author                 :    Frank
        @Description        :
        
        ————————————————————————————————————————————————————————————————————
        @Change Activity:
    
"""

import sys

from PyQt5.QtWidgets import QApplication, QDialog, QMessageBox
from PyQt5 import QtWidgets
from PyQt5.uic.properties import QtCore

from designer.UI_hint import Ui_Form_Hint
from designer.UI_mod import Ui_Form_mod
from . import glob, data
from struct import pack, unpack
from PyQt5 import QtCore, QtGui
from PyQt5.QtCore import QThread, QTimer, QEventLoop, Qt
from PyQt5.QtWidgets import QApplication, QMessageBox, QWidget, QPushButton

class ReBootWait(QMessageBox):
    def __init__(self, timeout=60, parent=None):
        # super(ReBootWait, self).__init__(parent)
        # self.form.setupUi(self)
        # self.setWindowFlags(Qt.WindowStaysOnTopHint)
        super().__init__()

        self.setWindowFlags(Qt.WindowStaysOnTopHint)        # 子窗口置顶
        self.form = Ui_Form_Hint()
        self.form.setupUi(self)
        self.show()

        self.setWindowTitle("wait")
        self.time_to_wait = timeout
        self.setText("等待{0}下位机重启，禁止任何操作！".format(timeout))
        self.show()
        self.setStandardButtons(QMessageBox.NoButton)
        self.timer = QtCore.QTimer(self)
        self.timer.setInterval(1000)
        self.timer.timeout.connect(self.changeContent)
        self.timer.start()

    def changeContent(self):
        self.time_to_wait -= 1
        self.setText("等待{0}下位机重启，禁止任何操作！".format(self.time_to_wait))
        if self.time_to_wait <= 0:
            self.close()

    def closeEvent(self, event):
        self.timer.stop()
        event.accept()
        pass


class mod(QDialog):
    diameter = float()
    theorysl = float()
    realsl = float()
    angle = float()
    sounddelay1 = float()
    sounddelay2 = float()
    fixedpress = float()
    
    def __init__(self, mw):
        """
            初始化操作，创建相关触发联系
        :param parent:
        """
        super().__init__()
        
        self.mw = mw
        self.form = Ui_Form_mod()
        self.form.setupUi(self)
        # self.show()
        # # 设置实例
        # self.SetItems()
        # 设置信号与槽
        self.CreateSignalSlot()
        self.test()
        self.mw.setWindowOpacity(0.8)
    
    def closeEvent(self, QCloseEvent):
        super().closeEvent(QCloseEvent)
        self.mw.setWindowOpacity(1)
        
        

    def test(self):
        data_single = {"测量值":1.1, "标准点":1.1, "修正误差":1.1}
        data_mod = []
        for i in range(10):
            data_mod.append(data_single)
        
        for i in range(10):
            self.form.mod_table.setItem(i, 0, QtWidgets.QTableWidgetItem(str(data_mod[i]["测量值"])))
            self.form.mod_table.setItem(i, 1, QtWidgets.QTableWidgetItem(str(data_mod[i]["标准点"])))
            self.form.mod_table.setItem(i, 2, QtWidgets.QTableWidgetItem(str(data_mod[i]["修正误差"])))

    def CreateSignalSlot(self):
        self.form.set_btn.clicked.connect(self.changePara)
        self.form.read_btn.clicked.connect(self.readPara)
    
    def changePara(self):
        # self.form.mod_table.setItem(line, i, QtWidgets.QTableWidgetItem(data[i]))
        data_single = {"测量值":None, "标准点":None, "修正误差":None}
        data_mod = []
        for i in range(10):
            for j in range(2):
                data_single["测量值"] = float(self.form.mod_table.item(i, j).text())
                data_single["标准点"] = float(self.form.mod_table.item(i, j+1).text())
            data_mod.append(data_single)

        # TODO 测试代码，
        self.amend(data_mod)          # 计算补入最后一列数据
        
        send_data = b'Z'
        cnt = 0
        for i in data_mod:
            send_data += pack('<f', i["标准点"])
            send_data += pack('<f', i["修正误差"])
            self.form.mod_table.setItem(cnt, 2, QtWidgets.QTableWidgetItem(str(i["修正误差"])))
            cnt += 1

        # glob.com.write()
    
        bcc = 0
        for i in range(len(send_data)):
            bcc ^= send_data[i]
    
        send_data += bytes.fromhex((hex(bcc))[2:])
        glob.com.writeData(send_data)
    
    def readPara(self):
        glob.com.writeData(b'Z')
        glob.g_rev_data = bytes(glob.com.readAll())
        
        # is_checked(glob.g_rev_data) == True:
        if len(glob.g_rev_data)==47 and data.is_checked(glob.g_rev_data)==True:
            rev_data = unpack('<f', glob.g_rev_data[1:-2])

        # 读取的是标准点和修正误差，同发送的值是相同的类型
        for i in range(20):
            self.form.mod_table.setItem(i//2, i%2+1, QtWidgets.QTableWidgetItem(rev_data[i]))

        # self.tableWidget.setItem(line, i, QtWidgets.QTableWidgetItem(data[i]))

    def amend(self, data):
        """
        数据修正，折线修正
        :return:
        """
        # TODO 计算出修正误差的值
        for i in data:
            i["修正误差"] = 1.1

if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = mod()
    w.show()
    sys.exit(app.exec_())