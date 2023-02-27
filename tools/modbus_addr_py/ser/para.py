"""
        Created on 2019/12/11 19:54
        ————————————————————————————————————————————————————————————————————
        @File Name            :    para.py
        @Author                 :    Frank
        @Description        :
        
        ————————————————————————————————————————————————————————————————————
        @Change Activity:
    
"""
import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QDialog
from designer.UI_para import Ui_Form_para
from struct import pack, unpack
from . import glob, data

class para(QDialog):
    
    def __init__(self, mw):
        """
            初始化操作，创建相关触发联系
        :param parent:
        """
        super().__init__()

        # self.area = float()
        # self.angle_1 = float()
        # self.len_1 = float()
        # self.delay_11 = float()
        # self.delay_12 = float()
        # self.angle_2 = float()
        # self.len_2 = float()
        # self.delay_21 = float()
        # self.delay_22 = float()
        # self.fixed_temp = float()
        # self.fixed_press = float()

        self.mw = mw
        self.form = Ui_Form_para()
        self.form.setupUi(self)
        self.CreateSignalSlot()
        self.test()
        self.mw.setWindowOpacity(0.8)

    def closeEvent(self, QCloseEvent):
        super().closeEvent(QCloseEvent)
        self.mw.setWindowOpacity(1)
        
    def test(self):
        self.form.area_line.setText('1')
        self.form.angle_1_line.setText('1')
        self.form.len_1_line.setText('1')
        self.form.delay_11_line.setText('1')
        self.form.delay_12_line.setText('1')
        self.form.angle_2_line.setText('1')
        self.form.len_2_line.setText('1')
        self.form.delay_21_line.setText('1')
        self.form.delay_22_line.setText('1')
        self.form.fixed_temp_line.setText('1')
        self.form.fixed_press_line.setText('1')
        
    def CreateSignalSlot(self):
        self.form.set_btn.clicked.connect(self.changePara)
        self.form.read_btn.clicked.connect(self.readPara)
    
    def changePara(self):
        # self.area = self.area_line.text()
        # self.angle_1 = self.angle_1_line.text()
        # self.len_1 = self.len_1_line.text()
        # self.delay_11 = self.delay_11_line.text()
        # self.delay_12 = self.delay_12_line.text()
        # self.angle_2 = self.angle_2_line.text()
        # self.len_2 = self.len_2_line.text()
        # self.delay_21 = self.delay_21_line.text()
        # self.delay_22 = self.delay_22_line.text()
        # self.fixed_temp = self.fixed_temp_line.text()
        # self.fixed_press = self.fixed_press_line.text()
        com_data = b'W'
        com_data += pack('<f', float(self.form.area_line.text()))
        com_data += pack('<f', float(self.form.angle_1_line.text()))
        com_data += pack('<f', float(self.form.len_1_line.text()))
        com_data += pack('<f', float(self.form.delay_11_line.text()))
        com_data += pack('<f', float(self.form.delay_12_line.text()))
        com_data += pack('<f', float(self.form.angle_2_line.text()))
        com_data += pack('<f', float(self.form.len_2_line.text()))
        com_data += pack('<f', float(self.form.delay_21_line.text()))
        com_data += pack('<f', float(self.form.delay_22_line.text()))
        com_data += pack('<f', float(self.form.fixed_temp_line.text()))
        com_data += pack('<f', float(self.form.fixed_press_line.text()))
        # glob.com.write()
    
        bcc = 0
        for i in range(len(com_data)):
            bcc ^= com_data[i]
        
        com_data += bytes.fromhex((hex(bcc))[2:])
        glob.com.writeData(com_data)

    def readPara(self):
        glob.com.writeData(b'W')
        glob.g_rev_data = bytes(glob.com.readAll())
        # is_checked(glob.g_rev_data) == True:
        if len(glob.g_rev_data)==47 and data.is_checked(glob.g_rev_data)==True:
            rev_data = unpack('<f', glob.g_rev_data[1:-2])
        
        for i in rev_data:
            self.form.area_line.setText(str(i))
            self.form.angle_1_line.setText(str(i))
            self.form.len_1_line.setText(str(i))
            self.form.delay_11_line.setText(str(i))
            self.form.delay_12_line.setText(str(i))
            self.form.angle_2_line.setText(str(i))
            self.form.len_2_line.setText(str(i))
            self.form.delay_21_line.setText(str(i))
            self.form.delay_22_line.setText(str(i))
            self.form.fixed_temp_line.setText(str(i))
            self.form.fixed_press_line.setText(str(i))
        
if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = para()
    w.show()
    sys.exit(app.exec_())