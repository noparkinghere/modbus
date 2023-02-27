"""
        Created on 2019/12/24 16:55
        ————————————————————————————————————————————————————————————————————
        @File Name            :    glob.py
        @Author                 :    Frank
        @Description        :    本文件主要用来定义全局变量
        
        ————————————————————————————————————————————————————————————————————
        @Change Activity:
    
"""

from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo
# from com import Com

com = QSerialPort()
g_rev_data = bytes()        # serial 窗口通过这个变量来数据交互
g_send_data = bytes()
g_rev_flag = False            # serial 窗口通过这个变量来确定刷新数据
g_send_flag = False            # serial 窗口通过这个变量来确定刷新数据

def getTime():
    import time
    # time.strftime("%B %d, %H:%M:%S", time.localtime())
    return (time.strftime('%H:%M:%S')+'.'+str(int(time.time()*1000)%1000))


