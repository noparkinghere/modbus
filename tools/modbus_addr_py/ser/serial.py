"""
        Created on 2019/12/11 19:53
        ————————————————————————————————————————————————————————————————————
        @File Name            :    serial.py
        @Author                 :    Frank
        @Description        :
        
        ————————————————————————————————————————————————————————————————————
        @Change Activity:
    
"""
import re

from PyQt5 import QtCore
from PyQt5.QtCore import QTimer
from PyQt5.QtCore import Qt
from ser import glob
import sys

from PyQt5.QtWidgets import QMainWindow, QApplication, QDialog, QMessageBox

from designer.UI_serial import Ui_Form_serial

cnt = 0

class serial(QDialog):
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
        self.setWindowFlags(Qt.WindowStaysOnTopHint)        # 子窗口置顶
        self.form = Ui_Form_serial()
        self.form.setupUi(self)
        self.show()
        # # 设置实例
        self.SetItems()
        # 设置信号与槽
        self.CreateSignalSlot()
    
    def CreateSignalSlot(self):
        self.form.send_btn.clicked.connect(self.senddata)
        self.form.repet_btn.clicked.connect(self.readPara)
        self.form.rev_Text.selectionChanged.connect(self.translate)
        self.form.clear_btn.clicked.connect(self.form.rev_Text.clear)
    
    def translate(self):
        res = 0
        for i in self.form.rev_Text.createMimeDataFromSelection().text().split():
            res = res*256 + int(i, 16)
        self.form.expdata_line.setText(str(res))
    
    def senddata(self):
        try:
            glob.com.write(bytes.fromhex(self.form.senddata_line.text()))
            # glob.com.write(bytes.fromhex("1234"))
        except:
            QMessageBox.critical(self, '错误', '请输入偶数位的二进制数如：22，AAAA')

    def readPara(self):
        pass

    
    def SetItems(self):
        self.timer = QTimer(self)    # 初始化一个定时器
        self.timer.timeout.connect(self.showdata)    # 计时结束调用operate()方法
        self.timer.start(200)    # 设置计时间隔 200ms 并启动


    def showdata(self):
        """
        子窗口实时跟踪显示收发的数据
        :return:
        """
        # 收到的数据判断显示
        if glob.g_rev_flag == True:
            glob.g_rev_flag = False
            
            if self.form.hex_box.isChecked():
                out = ' '.join([glob.g_rev_data.hex()[i * 2:i * 2 + 2] for i in range(len(glob.g_rev_data))])
            else:
                out = ' '.join([str(int(i)) for i in glob.g_rev_data])
            self.form.rev_Text.append(glob.getTime()+" < "+out)

            # self.form.rev_Text.insertPlainText(str(glob.g_rxData))

            # for i in glob.g_rxData:
            #     self.form.rev_Text.insertPlainText(i+' ')
                # self.form.rev_Text.insertPlainText(str(cnt)+'\n')
                # a = self.form.rev_Text.textCursor()
                # print(a.selectedText())
                # print('*'*6)
                # print(self.form.rev_Text.textCursor())
                # print(len(self.form.rev_Text.toPlainText()))
            # else:
            #     self.form.rev_Text.insertPlainText('\n')
        
        # 发送的数据判断显示
        if glob.g_send_flag == True:
            glob.g_send_flag = False
            if self.form.hex_box.isChecked():
                out = ' '.join([glob.g_send_data.hex()[i * 2:i * 2 + 2] for i in range(len(glob.g_send_data))])
                # self.form.rev_Text.setTextColor(0x00ff00)
            else:
                out = ' '.join([str(int(i)) for i in glob.g_send_data])
            self.form.rev_Text.append(glob.getTime()+" > " + out)
            glob.g_send_data = None
            # _translate = QtCore.QCoreApplication.translate
            # self.form.rev_Text.insertHtml(_translate("Form_serial",
            #                                  "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
            #                                  "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
            #                                  "p, li { white-space: pre-wrap; }\n"
            #                                  "</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
            #                                  "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">fsdf</span></p></body></html>"))
        


if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = serial()
    w.show()
    sys.exit(app.exec_())
