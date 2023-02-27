"""
        Created on 2019/12/18 10:33
        ————————————————————————————————————————————————————————————————————
        @File Name            :    cal.py
        @Author                 :    Frank
        @Description        :
        
        ————————————————————————————————————————————————————————————————————
        @Change Activity:
    
"""
from math import cos
import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QStatusBar
import json

from UI_flowrate import Ui_MainWindow


class flowrate(QMainWindow, Ui_MainWindow):
    # para = {"realsl":"", "st1":"", "st2":'', 'diameter':'', 'theorysl':'', 'angle':'', 'sounddelay1':'', 'sounddelay2':''}
    sv = float()
    fv = float()
    wfr = float()
    sfr = float()
    cnt = 0
    
    def __init__(self, parent=None):
        """
            初始化操作，创建相关触发联系
        :param parent:
        """
        super().__init__(parent)
        self.setupUi(self)
        # para = {"realsl":"", "st1":"", "st2":'', 'diameter':'', 'theorysl':'', 'angle':'', 'sounddelay1':'', 'sounddelay2':''}
        # a = json.dumps(para)
        # with open('para.json', 'w+') as f:
        #     f.write(a)
        
        with open('para.json', 'r+') as f:
            self.para = json.loads(f.read())
        self.st1 = float(self.para["st1"])
        self.st2 = float(self.para["st2"])
        self.diameter = float(self.para["diameter"])
        self.tsl = float(self.para["theorysl"])
        self.rsl = float(self.para["realsl"])
        self.angle = float(self.para["angle"])
        self.sd1 = float(self.para["realsl"])
        self.sd2 = float(self.para["realsl"])
        self.press = float(self.para["press"])
        self.chang = float(self.para["chang"])
        self.kuan = float(self.para["kuan"])
        self.radius = float(self.para["radius"])
        
        # 设置实例
        self.SetItems()
        # 设置信号与槽
        self.CreateSignalSlot()
        self.showdata()
    
    def CreateSignalSlot(self):
        self.cal_btn.clicked.connect(self.showdata)
        self.save_btn.clicked.connect(self.savedata)
    
    def SetItems(self):
        self.st1_line.setText(str(self.st1))
        self.st2_line.setText(str(self.st2))
        self.realsl_line.setText(str(self.rsl))
        self.diameter_line.setText(str(self.diameter))
        self.angle_line.setText(str(self.angle))
        self.statusBar = QStatusBar()
        self.setStatusBar(self.statusBar)

    def savedata(self):
        with open(str(self.cnt)+'.txt', 'w+') as f:
            f.write("声时1："+str(self.st1)+'\n')
            f.write("声时2："+str(self.st2)+'\n')
            f.write("理论声程："+str(self.tsl)+'\n')
            f.write("实际声程："+str(self.rsl)+'\n')
            f.write("直径："+str(self.diameter)+'\n')
            f.write("角度："+str(self.angle)+'\n')
            f.write("长："+str(self.chang)+'\n')
            f.write("宽："+str(self.kuan)+'\n')
            f.write("半径："+str(self.radius)+'\n')
            f.write("声延时1：" + str(self.sd1)+'\n')
            f.write("声延时2：" + str(self.sd2)+'\n')
            f.write("压力值："+str(self.press)+'\n')

    def showdata(self):
        self.st1 = float(self.st1_line.text())
        self.st2 = float(self.st2_line.text())
        self.rsl = float(self.realsl_line.text())
        self.diameter = float(self.diameter_line.text())
        self.angle = float(self.angle_line.text())
        
        self.sv, self.fv, self.wfr, self.sfr = self.cal(self.rsl, self.st1, self.st2, self.angle, self.diameter)
        self.sv_line.setText('{:.3f}'.format(self.sv))
        self.fv_line.setText('{:.3f}'.format(self.fv))
        self.wfr_line.setText('{:.3f}'.format(self.wfr))
        
        self.cnt += 1
        self.statusBar.showMessage(str(self.cnt))
    
    def cal(self, rsl, st1, st2, angle, diameter, tsl=None, chang=None, kuan=None, radius=None, sd1=None, sd2=None, press=None):
        """
            将声时换算成瞬时量
        :param rsl:    实际声程 单位 mm
        :param st1:    声时1 单位 ns
        :param st2:    声时2 单位 ns
        :param angle: 角度 单位 °
        :param diameteriad: 直径 单位 mm
        :param tsl: 理论声程单位 mm
        :param chang: 截面积长 mm
        :param kuan: 截面积宽 mm
        :param radius: 半径 mm
        :param sd1: 声延时1 ns
        :param sd2: 声延时2 ns
        :param press: 压力值 KPa
        :return:
        """
        PI = 3.14159
        
        self.sv = rsl*(st1+st2)/st1/st2/2 * 1e6
        print(self.sv)
        self.sv = 2*rsl / (st1+st2) * 1e6
        print(self.sv)
        self.fv = ((rsl / st1) - (rsl / st2)) / 2 / cos(angle / 180 * PI) * 1e6
        print(self.fv)
        self.wfr = self.fv * PI * ((diameter / 2) ** 2) * 3.6
        print(self.wfr)
        self.sfr = 0
        
        # 返回 声速、流速、工况瞬时量、标况瞬时量
        return self.sv, self.fv, self.wfr, self.sfr


if __name__ == '__main__':
    app = QApplication(sys.argv)
    # w = flowrate(50.850, 174783.656, 176923.156, 60, 48)
    w = flowrate()
    w.show()
    sys.exit(app.exec_())
