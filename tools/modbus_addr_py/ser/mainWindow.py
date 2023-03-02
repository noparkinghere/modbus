"""
        Created on 2019/12/11 19:47
        ————————————————————————————————————————————————————————————————————
        @File Name            :    mainWindow.py
        @Author                 :    Frank
        @Description        :
        
        ————————————————————————————————————————————————————————————————————
        @Change Activity:
    
"""

import decimal
import json
import struct
import sys
import time
from collections import OrderedDict
import datetime

from PyQt5.QtCore import Qt

from PyQt5 import QtWidgets, QtCore, QtGui
from PyQt5.QtCore import QTimer
from PyQt5.QtGui import QIcon
from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo
from PyQt5.QtWidgets import QMessageBox, QMainWindow, QAbstractItemView, QApplication, QItemDelegate

from ser.data import DataHandle, calc_crc16, hex_to_float, float_to_hex, xor_check
from ser.hint import Hint
from ser.mod import mod, ReBootWait
from ser.para import para
from ser.serial import serial
from designer.Ui_MainWindow import Ui_MainWindow
import csv
from ser import glob, data
from ser.time_out import TimerMessageBox

NORMAL_MODE = "正常模式 （N）"
TEMP_MODE = "温度模式 （T）"
GAIN_MODE = "增益模式 （G）"
PRESS_MODE = "压力模式 （P）"

from threading import Thread
from time import sleep

g_break_flag = False
chg_flag = True


# 用于设置 table 列不可编辑
class EmptyDelegate(QItemDelegate):
    def __init__(self, parent):
        super(EmptyDelegate, self).__init__(parent)

    def createEditor(self, QWidget, QStyleOptionViewItem, QModelIndex):
        return None


class MyMainWindow(QMainWindow, Ui_MainWindow):
    portstate = False

    # 通信数据
    time = ''
    mode = ''
    flowRate = 0
    ch1SoundTime1 = int()
    ch1SoundTime2 = int()
    ch2SoundTime1 = int()
    ch2SoundTime2 = int()
    flowRatePos = 0
    flowRateNeg = 0
    gainUp = 0
    gainDw = 0
    temp = -273
    press = 101.325
    gain_up = 0
    gain_dn = 0
    send_char = None
    cnt = 0  # 数据条数
    aut_oldlist = []
    ROW_LEN = 20
    COL_LEN = 13
    saveTitle = ["时间", "模式", "流道a声时1(us)", "流道a声时2(us)", "流道b声时1(us)", "流道b声时2(us)", "正向累积量(L)"
        , "反向累积量(L)", "瞬时量(L/h)", "增益值1(u/d)", "增益值2(u/d)", "温度(°C)", "压力值(KPa)"]
    table_index = {}
    table_addr = []

    def __init__(self, parent=None):
        """
            初始化操作，创建相关触发联系
        :param parent:
        """
        super().__init__(parent)

        self.setupUi(self)
        # 设置实例
        self.set_items()
        # 设置信号与槽
        self.create_signal_slot()
        glob.g_rev_flag = False
        self.setWindowTitle("ttl转modbus测试工具")
        self.setWindowIcon(QIcon("./img.ico"))


    def set_items(self):
        """
            创建实例，界面上没有显示的内容
        :return:
        """
        self.row = []
        self.row_2 = []
        self.row_flag = 0


        glob.com = QSerialPort()
        self.data_item_cnt = 0
        # 设置列宽
        header = self.tableWidget.horizontalHeader()
        header.setSectionResizeMode(0, QtWidgets.QHeaderView.ResizeToContents)
        header.setSectionResizeMode(2, QtWidgets.QHeaderView.ResizeToContents)
        header.setSectionResizeMode(3, QtWidgets.QHeaderView.ResizeToContents)
        header.setSectionResizeMode(4, QtWidgets.QHeaderView.ResizeToContents)
        header.setSectionResizeMode(5, QtWidgets.QHeaderView.ResizeToContents)
        header.setSectionResizeMode(6, QtWidgets.QHeaderView.ResizeToContents)
        header.setSectionResizeMode(7, QtWidgets.QHeaderView.ResizeToContents)
        header.setSectionResizeMode(8, QtWidgets.QHeaderView.ResizeToContents)
        header.setSectionResizeMode(9, QtWidgets.QHeaderView.ResizeToContents)
        header.setSectionResizeMode(10, QtWidgets.QHeaderView.ResizeToContents)
        header.setSectionResizeMode(11, QtWidgets.QHeaderView.ResizeToContents)

        # table 控制整合数据
        with open("./code_create/auto_modbus.json", 'r', encoding='utf-8') as f:
            self.json_data = json.loads(f.read())

        for i in self.json_data["寄存器组"]:
            for j in i["数据块"]:
                rowPosition = self.tableWidget.rowCount()
                self.tableWidget.insertRow(rowPosition)
                # print(j["名称"])
                # 单元格坐标命名
                self.table_index[i["寄存器组名称"] + '_' + j["名称"]] = rowPosition

                self.table_addr.append((j["地址十六进制"], j["寄存器数"]))
                # self.tableWidget.item(0, 0).setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
                # print("*"*20)
                # self.table_index
                item = QtWidgets.QTableWidgetItem(i["寄存器组名称"] + '_' + j["名称"])
                item.setTextAlignment(QtCore.Qt.AlignLeading | QtCore.Qt.AlignVCenter)
                self.tableWidget.setItem(rowPosition, 0, item)
                item = QtWidgets.QTableWidgetItem('')
                item.setTextAlignment(QtCore.Qt.AlignCenter)
                self.tableWidget.setItem(rowPosition, 1, item)
                item = QtWidgets.QTableWidgetItem(j["取值下限"])
                item.setTextAlignment(QtCore.Qt.AlignCenter)
                self.tableWidget.setItem(rowPosition, 2, item)
                item = QtWidgets.QTableWidgetItem(j["取值上限"])
                item.setTextAlignment(QtCore.Qt.AlignCenter)
                self.tableWidget.setItem(rowPosition, 3, item)
                item = QtWidgets.QTableWidgetItem(j["解析"])
                item.setTextAlignment(QtCore.Qt.AlignCenter)
                self.tableWidget.setItem(rowPosition, 4, item)
                item = QtWidgets.QTableWidgetItem(j["类型"])
                item.setTextAlignment(QtCore.Qt.AlignCenter)
                self.tableWidget.setItem(rowPosition, 5, item)
                item = QtWidgets.QTableWidgetItem(j["寄存器数"])
                item.setTextAlignment(QtCore.Qt.AlignCenter)
                self.tableWidget.setItem(rowPosition, 6, item)
                item = QtWidgets.QTableWidgetItem(j["读写权限"])
                item.setTextAlignment(QtCore.Qt.AlignCenter)
                self.tableWidget.setItem(rowPosition, 7, item)
                item = QtWidgets.QTableWidgetItem(j["地址十六进制"])
                item.setTextAlignment(QtCore.Qt.AlignCenter)
                self.tableWidget.setItem(rowPosition, 8, item)
                # item = QtWidgets.QTableWidgetItem(str(int(j["寄存器数"]) * 2))
                # item.setTextAlignment(QtCore.Qt.AlignCenter)
                # self.tableWidget.setItem(rowPosition, 9, item)
                item = QtWidgets.QTableWidgetItem(j["单位"])
                item.setTextAlignment(QtCore.Qt.AlignCenter)
                self.tableWidget.setItem(rowPosition, 9, item)
                item = QtWidgets.QTableWidgetItem(j["说明"])
                item.setTextAlignment(QtCore.Qt.AlignLeft)
                self.tableWidget.setItem(rowPosition, 10, item)
                # print(i[1]["数据块"]["名称"])

        self.tableWidget.setItemDelegateForColumn(0, EmptyDelegate(self))
        self.tableWidget.setItemDelegateForColumn(2, EmptyDelegate(self))
        self.tableWidget.setItemDelegateForColumn(3, EmptyDelegate(self))
        self.tableWidget.setItemDelegateForColumn(4, EmptyDelegate(self))
        self.tableWidget.setItemDelegateForColumn(5, EmptyDelegate(self))
        self.tableWidget.setItemDelegateForColumn(6, EmptyDelegate(self))
        self.tableWidget.setItemDelegateForColumn(7, EmptyDelegate(self))
        self.tableWidget.setItemDelegateForColumn(8, EmptyDelegate(self))
        self.tableWidget.setItemDelegateForColumn(9, EmptyDelegate(self))
        self.tableWidget.setItemDelegateForColumn(10, EmptyDelegate(self))
        self.tableWidget.setItemDelegateForColumn(11, EmptyDelegate(self))

        # self.now  = str(datetime.datetime.now()).split(" ")[0] + '_' + str(datetime.datetime.now()).split(" ")[1].split(".")[
        #     0].replace(":", "_")
        self.auto_now  = str(datetime.datetime.now()).split(" ")[0] + '_' + str(datetime.datetime.now()).split(" ")[1].split(".")[
            0].replace(":", "_")
        self.exp_headers = ["时间"]
        for i in self.json_data["寄存器组"]:
            for j in i["数据块"]:
                self.exp_headers.append(j["名称"])

    def create_signal_slot(self):
        """
            创建信号槽
        :return:
        """
        self.save_btn.clicked.connect(self.save_cmd)
        self.clear_btn.clicked.connect(self.clear_cmd)
        self.refresh = QTimer(self)  # 初始化一个定时器
        self.refresh.timeout.connect(self.ref_port)  # 计时结束调用operate()方法
        self.refresh.start(500)  # 设置计时间隔 500ms 并启动

        # self.tableWidget.
        self.save_data = data.DataHandle(time.strftime('%Y%m%d') + '.csv', self.saveTitle)
        self.com_btn.clicked.connect(self.opt_serial)
        self.clear_screen_btn.clicked.connect(self.clear_screen)
        # self.comhelp_window.clicked.connect(self.open_serial_win)
        self.getdata_btn.clicked.connect(self.modbus_get_all_data)
        self.auto_read_btn.clicked.connect(self.click_auto_read)
        self.auread = QTimer(self)  # 初始化一个定时器
        self.auread.timeout.connect(self.auto_read)  # 计时结束调用operate()方法
        self.auread.start(5000)  # 设置计时间隔 500ms 并启动

    def save_cmd(self):
        glob.com.write(bytes.fromhex("011000DB0001020001757B"))
        pass

    def clear_cmd(self):
        glob.com.write(bytes.fromhex("011000DC000102000174CC"))
        pass

    def click_auto_read(self):
        if self.auto_read_btn.text() == "停止读取":
            self.auto_read_btn.setText("自动读取")
        elif self.auto_read_btn.text() == "自动读取":
            self.auto_read_btn.setText("停止读取")
            self.auto_now = str(datetime.datetime.now()).split(" ")[0] + '_' + \
                            str(datetime.datetime.now()).split(" ")[1].split(".")[
                           0].replace(":", "_")

            # headers = ["时间", "设备地址", "硬件版本号", "软件版本号", "整机编号", "制造商ID", "设备类型", "出厂日期", "模式", "截面积", "流速", "瞬时流量", "正向声时",
            #            "逆向声时", "温度", "压力", "增益1", "增益2", "正向声时2", "逆向声时2", "声速", "Rup1", "Rdown1", "Rup2", "Rdown2",
            #            "Err1", "Err2", "Sys", "测量次数", "DW1", "DW2", "声速2", ]
            headers = ["时间"]
            i = dict(self.json_data["寄存器组"][1])
            for j in i["数据块"]:
                headers.append(j["名称"])

            with open(f"auto_save_{self.auto_now}.csv", 'w', encoding="utf-8", newline="") as f:
                f_csv = csv.writer(f)
                f_csv.writerow(headers)

    def auto_read(self):
        if self.auto_read_btn.text() == "停止读取":
            pass
            self.modbus_read_dy_data()

    def clear_screen(self):
        cnt = 0
        self.tableWidget.itemChanged.connect(self.modbus_data_change)
        self.tableWidget.itemChanged.disconnect()
        for i in self.json_data["寄存器组"]:
            cnt += int(i["合法值个数"])
        for i in range(cnt):
            self.tableWidget.setItem(i, 1, QtWidgets.QTableWidgetItem(" "))
        self.tableWidget.itemChanged.connect(self.modbus_data_change)

    def offset2(self, data):
        while len(data) < 8:
            data = '0' + data
        return data

    def modbus_data_change(self, item):
        global chg_flag
        try:
            if chg_flag == True:
                offset = lambda x: (str("000") + x) if (len(x) == 1) else (
                    (str("00") + x) if (len(x) == 2) else ((str("0") + x) if (len(x) == 3) else x))
                row = item.row()
                col = item.column()
                # self.table_addr[row]

                if self.tableWidget.item(row, 5).text() == "UINT16":
                    if self.tableWidget.item(row, 4).text() == "BCD":
                        res = offset(str(self.tableWidget.item(row, col).text()))
                    else:
                        res = offset(hex(int(self.tableWidget.item(row, col).text()))[2:])
                elif self.tableWidget.item(row, 5).text() == "UINT32":
                    if self.tableWidget.item(row, 4).text() == "BCD":
                        temp = self.offset2(str(self.tableWidget.item(row, col).text()))
                        res = temp
                    else:
                        temp = self.offset2(hex(int(self.tableWidget.item(row, col).text()))[2:])
                        res = temp
                    # print(bytes([int(self.tableWidget.item(row, col).text())]))
                elif self.tableWidget.item(row, 5).text() == "REAL4":
                    temp = float_to_hex(float(self.tableWidget.item(row, col).text()))
                    res = temp
                string = '0110' + offset(self.tableWidget.item(row, 8).text()[2:]) \
                         + '000' + self.tableWidget.item(row, 6).text() \
                         + '0' + str(int(self.tableWidget.item(row, 6).text()) * 2) \
                         + res
                string += calc_crc16(string)

                dump = bytes(glob.com.readAll())
                glob.com.write(bytes.fromhex(string))
                print("发送数据： " + string)
                glob.com.flush()

                # 读取数据
                glob.g_rev_data = b''
                str_data = ''
                # for cnt in range(150):
                #     if glob.com.waitForReadyRead(1):
                #         QApplication.processEvents()
                #         glob.g_rev_data += bytes(glob.com.readAll())
                #         glob.g_rev_flag = True
                for cnt in range(50):
                    time.sleep(0.01)
                    QApplication.processEvents()
                    glob.g_rev_data += bytes(glob.com.readAll())
                    glob.g_rev_flag = True

                str_data = glob.g_rev_data.hex()
                if glob.g_rev_data != b'':
                    self.modbus_exp_ele(str_data, string, (row, col))
                else:
                    print("NO data")
                    chg_flag = False
                    self.tableWidget.setItem(row, col, QtWidgets.QTableWidgetItem("未返回数据"))
                    print("Wrong 1")
                    QMessageBox.critical(self, '严重错误', '没有数据')
            else:
                chg_flag = True
        except Exception as e:
            QMessageBox.critical(self, '严重错误', '数据异常')

    # 单元格回复内容解析
    def modbus_exp_ele(self, data, w_data, index):
        global chg_flag

        if glob.g_rev_data.hex()[2:4] == '90':
            chg_flag = False
            self.tableWidget.setItem(index[0], index[1], QtWidgets.QTableWidgetItem("写入失败"))
            print("Wrong")
            QMessageBox.critical(self, '严重错误', '下位机处理失败')

        elif calc_crc16(data[:-4]).upper() == data[-4:].upper() \
                and int.from_bytes(bytes.fromhex(w_data)[4:6], "big") == int.from_bytes(glob.g_rev_data[4:6], "big"):
            print("Right")
            # self.modbus_data_exp(data[], self.tableWidget.item(index[0], 4).text())
        else:
            chg_flag = False
            self.tableWidget.setItem(index[0], index[1], QtWidgets.QTableWidgetItem("err"))
            print("Wrong")
            QMessageBox.critical(self, '严重错误', '数据写入失败')

        print("接收数据： " + data)
        print('*' * 20)

    def info(self):
        messagebox = TimerMessageBox(5, self)
        messagebox.exec_()

    def modbus_get_all_data(self):
        global g_break_flag
        global chg_flag
        chg_flag = True
        self.read_all_cnt = 0
        self.all_data = [str(datetime.datetime.now()).split(" ")[0] + '_' +
                    str(datetime.datetime.now()).split(" ")[1].split(".")[0]]
        self.clear_screen()

        self.tableWidget.itemChanged.connect(self.modbus_data_change)

        # a = Hint()

        offset = lambda x: (str("000") + x) if (len(x) == 1) else (
            (str("00") + x) if (len(x) == 2) else ((str("0") + x) if (len(x) == 3) else x))
        self.tableWidget.itemChanged.disconnect()
        tmp_cnt = 0

        if self.auto_read_btn.text() == "自动读取":
            self.now = str(datetime.datetime.now()).split(" ")[0] + '_' + \
                            str(datetime.datetime.now()).split(" ")[1].split(".")[
                           0].replace(":", "_")
            # with open(f"保存参数_{self.now}.csv", 'w', encoding="utf-8",
            #           newline="") as f:
            #     pass

        for i in self.json_data["寄存器组"]:
            # g_data = ''
            start_addr = str(i["起始地址"][2:])
            end_addr = str(i["结束地址"][2:])
            start = str("01")
            fun_code = str("03")
            start_addr = offset(start_addr)
            cnt = offset(hex(int(i["寄存器个数"]))[2:])
            res = start + fun_code + start_addr + cnt
            crc16 = calc_crc16(str(res))
            res += crc16

            dump = glob.com.readAll()  # 写前清空缓冲区
            glob.com.write(bytes.fromhex(res))
            # glob.g_send_flag = True
            print("发送数据： " + res)
            glob.com.flush()
            glob.g_rev_data = b''
            str_data = ''

            for cnt in range(100):
                time.sleep(0.01)
                QApplication.processEvents()
                glob.g_rev_data += bytes(glob.com.readAll())
                glob.g_rev_flag = True

            # for cnt in range(50):
            #     if glob.com.waitForReadyRead(30):
            #         # print("111111")
            #         glob.g_rev_data += bytes(glob.com.readAll())
            #         glob.g_rev_flag = True

            # if glob.com.waitForReadyRead(30000):
            #     # print("111111")
            #     glob.g_rev_data += bytes(glob.com.readAll())
            str_data = glob.g_rev_data.hex()
            if glob.g_rev_data != b'':
                self.modbus_exp_2mg(str_data, i, res)
                self.all_data += self.row[1:]
            else:
                for j in range(int(i["合法值个数"])):
                    self.tableWidget.setItem(tmp_cnt + j, 1, QtWidgets.QTableWidgetItem('未读取到数据'))
                print("NO data")
                pass
            tmp_cnt += int(i["合法值个数"])

        with open(f"保存参数_{self.now}.csv", 'a', encoding="utf-8",
                  newline="") as f:
            for i in zip(self.exp_headers, self.all_data):
                f_csv = csv.writer(f)
                f_csv.writerow(i)
        self.row = []
        self.all_data = []
        # a.destroy()
        # QMessageBox.information(self, "提示", "读取完成")
        self.tableWidget.itemChanged.connect(self.modbus_data_change)
        self.data_item_cnt += 1
        self.statusbar.showMessage(f"读取完成第{self.data_item_cnt}条数据")

    # 读取动态数据，仅仅是声时板数据
    def modbus_read_dy_data(self):
        global g_break_flag
        global chg_flag
        chg_flag = True

        # self.clear_screen()

        self.tableWidget.itemChanged.connect(self.modbus_data_change)

        # a = Hint()

        offset = lambda x: (str("000") + x) if (len(x) == 1) else (
            (str("00") + x) if (len(x) == 2) else ((str("0") + x) if (len(x) == 3) else x))
        self.tableWidget.itemChanged.disconnect()
        tmp_cnt = 0

        for _ in self.json_data["自动读取组"].split(','):
            i = dict(self.json_data["寄存器组"][int(_)-1])
            # g_data = ''
            start_addr = str(i["起始地址"][2:])
            end_addr = str(i["结束地址"][2:])
            start = str("01")
            fun_code = str("03")
            start_addr = offset(start_addr)
            cnt = offset(hex(int(i["寄存器个数"]))[2:])
            res = start + fun_code + start_addr + cnt
            crc16 = calc_crc16(str(res))
            res += crc16

            dump = glob.com.readAll()  # 写前清空缓冲区
            glob.com.write(bytes.fromhex(res))
            # glob.g_send_flag = True
            print("发送数据： " + res)
            glob.com.flush()
            glob.g_rev_data = b''
            str_data = ''

            for cnt in range(50):
                time.sleep(0.01)
                QApplication.processEvents()
                glob.g_rev_data += bytes(glob.com.readAll())
                glob.g_rev_flag = True
            str_data = glob.g_rev_data.hex()
            if glob.g_rev_data != b'':
                self.modbus_exp_2mg(str_data, i, res)
            else:
                # for j in range(int(i["合法值个数"])):
                #     self.tableWidget.setItem(19 + j, 1, QtWidgets.QTableWidgetItem('未读取到数据'))
                # print("NO data")
                pass
            tmp_cnt += int(i["合法值个数"])
            self.tableWidget.itemChanged.connect(self.modbus_data_change)
            self.data_item_cnt += 1
            self.statusbar.showMessage(f"读取完成第{self.data_item_cnt}条数据")
            for cnt in range(100):
                time.sleep(0.01)
                QApplication.processEvents()
            pass

    def modbus_exp_2mg(self, data, org_data, r_data):
        self.row = [str(datetime.datetime.now()).split(" ")[0] + '_' +
                    str(datetime.datetime.now()).split(" ")[1].split(".")[0]]

        if calc_crc16(data[:-4]).upper() == data[-4:].upper() \
                and int.from_bytes(bytes.fromhex(r_data)[4:6], "big") * 2 == int.from_bytes(glob.g_rev_data[2:3], "big") \
                and int.from_bytes(bytes.fromhex(r_data)[4:6], "big") * 2 == len(glob.g_rev_data[3:-2]):
            print("Right")
            pos = 3
            for i in range(int(org_data["合法值个数"])):
                # if org_data["解析"] == "BCD":
                if self.tableWidget.item(self.table_index[org_data["寄存器组名称"] + '_' + org_data["数据块"][i]["名称"]]
                        , 4).text() == "BCD":
                    self.tableWidget.setItem(self.table_index[org_data["寄存器组名称"] + '_' + org_data["数据块"][i]["名称"]]
                                             , 1, QtWidgets.QTableWidgetItem(
                            self.modbus_data_exp(data[2 * pos:2 * (pos + int(org_data["数据块"][i]["寄存器数"]) * 2)],
                                                 org_data["数据块"][i]["类型"], 1)))
                    self.row += [self.modbus_data_exp(data[2 * pos:2 * (pos + int(org_data["数据块"][i]["寄存器数"]) * 2)],
                                                 org_data["数据块"][i]["类型"], 1)]
                else:
                    self.tableWidget.setItem(self.table_index[org_data["寄存器组名称"] + '_' + org_data["数据块"][i]["名称"]]
                                             , 1, QtWidgets.QTableWidgetItem(
                            self.modbus_data_exp(data[2 * pos:2 * (pos + int(org_data["数据块"][i]["寄存器数"]) * 2)],
                                                 org_data["数据块"][i]["类型"])))
                    self.row += [self.modbus_data_exp(data[2 * pos:2 * (pos + int(org_data["数据块"][i]["寄存器数"]) * 2)],
                                                                             org_data["数据块"][i]["类型"])]
                pos += int(org_data["数据块"][i]["寄存器数"]) * 2
        else:
            self.row += ["Wrong"]
            print("Wrong")
            pos = 3
            for i in range(int(org_data["合法值个数"])):
                self.tableWidget.setItem(self.table_index[org_data["寄存器组名称"] + '_' + org_data["数据块"][i]["名称"]]
                                         , 1, QtWidgets.QTableWidgetItem("读取失败"))
                pos += int(org_data["数据块"][i]["寄存器数"]) * 2

        print("接收数据： " + data)
        print('*' * 20)
        self.row_flag += 1

        # 存储数据
        # 全部数据存储


        # 模块数据存储

        if self.auto_read_btn.text() == "停止读取":
            # self.row_flag %= int(len(self.json_data["寄存器组"]))
            with open(f"auto_save_{self.auto_now}.csv", 'a', encoding="utf-8", newline="") as f:
                f_csv = csv.writer(f)
                f_csv.writerow(self.row)
            self.row = []


    def modbus_data_exp(self, data, type, bcd=0):
        res = ''

        if bcd == 1:
            if type == "UINT16":
                # res = (data[2:] + data[0:2]).lstrip("0")
                res = (data).lstrip("0")
                # res = str(int.from_bytes(bytes.fromhex(data), 'big'))
            elif type == "UINT32":
                # res = (data[4:] + data[0:4]).lstrip("0")
                res = (data).lstrip("0")
                # res = str(int.from_bytes(bytes.fromhex(data)[2:] + bytes.fromhex(data)[:2], 'big'))
        else:
            if type == "UINT16":
                # res = str(int.from_bytes(bytes.fromhex(data), 'big'))
                res = str(int.from_bytes(bytes.fromhex(data), 'big'))
            elif type == "UINT32":
                # res = str(int.from_bytes(bytes.fromhex(data)[2:] + bytes.fromhex(data)[:2], 'big'))
                res = str(int.from_bytes(bytes.fromhex(data), 'big'))
            elif type == "REAL4":
                # res = str(round(hex_to_float(data[4:] + data[:4]), 5))
                res = str(round(hex_to_float(data), 5))
        # glob.com.readyRead.connect(self.test)
        return res

    def open_para_win(self):
        self.p = para(self)
        self.p.exec()  # 模式对话框

    def open_serial_win(self):
        self.s = serial()

    def open_mod_win(self):
        res = b'\x02' + bytes.fromhex(hex(ord('R'))[2:]) + bytes.fromhex(
            ''.join([hex(ord(i))[2:] for i in "RESTARTRESETREBOOT"]))
        res += xor_check(res)
        glob.com.write(res)
        self.ex = ReBootWait()
        # ex.show()
        # pass

    def ref_port(self):
        """
        定时调用刷新串口数据
        :return:
        """
        if self.aut_oldlist != [i.portName() for i in QSerialPortInfo.availablePorts()]:
            self.port_comboBox.clear()
            # com = QSerialPort()
            self.aut_oldlist = [i.portName() for i in QSerialPortInfo.availablePorts()]
            for info in QSerialPortInfo.availablePorts():
                # com.setPort(info)
                # if com.open(QSerialPort.ReadWrite):
                self.port_comboBox.addItem(info.portName())
                self.port_comboBox.currentIndex()
                # com.close()

        # print(self.size().width())

        # 调整窗口大小
        # self.tableWidget.setFixedSize(QtCore.QSize(self.size().width()-20, self.size().height()-100))
        # self.tableWidget.horizontalHeader().setDefaultSectionSize((self.size().width()-50)/13)
        # self.tableWidget.verticalHeader().setDefaultSectionSize((self.size().height()-130)/20)

    def opt_serial(self):
        if self.com_btn.text() == '打开串口':
            comName = self.port_comboBox.currentText()
            comBaud = int(self.baudrate_comboBox.currentText())
            glob.com.setPortName(comName)
            try:
                glob.com.setParity(QSerialPort.NoParity)
                # glob.com.setParity(QSerialPort.NoParity)
                glob.com.setBaudRate(int(self.baudrate_comboBox.currentText()))
                if glob.com.open(QSerialPort.ReadWrite) == False:
                    QMessageBox.critical(self, '严重错误', '串口打开失败')
                    return
            except:
                QMessageBox.critical(self, '严重错误', '串口打开失败')
                return
            self.com_btn.setText("关闭串口")
        elif self.com_btn.text() == '关闭串口':
            glob.com.close()
            self.com_btn.setText("打开串口")

    def clear(self):
        """
            清空屏幕，累积量清零
        :return:
        """
        # TODO 计算的累积量清空
        self.flowRatePos = 0
        self.flowRateNeg = 0
        # TODO 删除文件
        self.save_data.del_data_file(glob.getTime().split()[1] + '.csv')

        # TODO 清空屏幕
        self.tableWidget.clearContents()
        self.cnt = 0

    def change_mode(self):
        glob.g_rev_flag = False
        if self.modesel_comboBox.currentText() == NORMAL_MODE:
            glob.g_send_data = b'N'  # 刚刚收到数据后，才可以切换模式
            # glob.com.writeData(b'N')
        elif self.modesel_comboBox.currentText() == TEMP_MODE:
            glob.g_send_data = b'T'  # 刚刚收到数据后，才可以切换模式
            # glob.com.writeData(b'T')
        elif self.modesel_comboBox.currentText() == GAIN_MODE:
            glob.g_send_data = b'G'  # 刚刚收到数据后，才可以切换模式
        elif self.modesel_comboBox.currentText() == PRESS_MODE:
            glob.g_send_data = b'P'  # 刚刚收到数据后，才可以切换模式
            # glob.com.writeData(b'P')

    def scroll_data(self):
        """
        滚动数据，最新的数据实时显示在最后一行，旧的数据往上滚动
        :return:
        """
        for i in range(self.ROW_LEN - 1):
            for j in range(self.COL_LEN):
                self.tableWidget.setItem(i, j,
                                         QtWidgets.QTableWidgetItem(str((self.tableWidget.item(i + 1, j).text()))))
                # self.tableWidget.setItem(i, j,QtWidgets.QTableWidgetItem(str('-')))
        print("success")


if __name__ == "__main__":
    print("*" * 8)
    # a = MyMainWindow()
    # a.open_mod_win()
    res = b'\x02' + bytes.fromhex(hex(ord('R'))[2:]) + bytes.fromhex(
        ''.join([hex(ord(i))[2:] for i in "RESTARTRESETREBOOT"]))
    res += xor_check(res)
    print(res)
