"""
        Created on 2019/12/11 19:53
        ————————————————————————————————————————————————————————————————————
        @File Name            :    data.py
        @Author                 :    Frank
        @Description        :
        
        ————————————————————————————————————————————————————————————————————
        @Change Activity:
    
"""
import os
import struct


def offset(data, size):
    while len(data) < size:
        data = '0' + data
    return data

def float_to_hex(f):
    return offset(hex(struct.unpack('<I', struct.pack('<f', f))[0])[2:], 8)

# float_to_hex(17.5)    # Output: '0x418c0000'

def hex_to_float(f):
    return struct.unpack('!f', bytes.fromhex(f))[0]

# hex_to_float("01010101")

def calc_crc16(string):
    offset = lambda x: (str("000") + x) if (len(x) == 1) else (
        (str("00") + x) if (len(x) == 2) else ((str("0") + x) if (len(x) == 3) else x))
    data = bytearray.fromhex(string)
    crc = 0xFFFF
    for pos in data:
        crc ^= pos
        for i in range(8):
            if ((crc & 1) != 0):
                crc >>= 1
                crc ^= 0xA001
            else:
                crc >>= 1

    return offset(hex(((crc & 0xff) << 8) + (crc >> 8))[2:])

class DataHandle:
    title =''
    
    def save_to_csv(self, file_name, value):
        """
        将数据保存到 csv 文件中，方便 excel 打开
        
        :param file_name:
        :param value:
        :return:
        """
        self.init_data_file(file_name)
        # with open(file_name, 'a+', newline="") as f:
        #     f.write(','.join(value) + '\r\n')

    def read_title_from_file(self, file_name):
        with open(file_name, "r+") as f:
            f.seek(0)
            res = f.readline()
        return res

    # 初始化 csv 文件
    # 可以作为清空数据的函数
    def init_data_file(self, file_name="output.csv"):
        # 如果文件第一行不对或不存在则重置文件。
        if os.path.exists(file_name)==False or self.read_title_from_file(file_name).strip()!=self.title.strip():
            try:
                os.remove(file_name)
            except FileNotFoundError:
                print("无该文件，自动创建")
            # with open(file_name, 'a+', newline="") as f:
            #     f.write(self.title)
    
    def del_data_file(self, file_name):
      os.remove(file_name)

    def __init__(self, file_name, title):
        self.title = ','.join(title)+'\r\n'
        self.init_data_file(file_name)

def is_checked(data):
    """
    对数据采用异或校验
    :param data:
    :return: 校验通过返回 True，错误返回 False
    """
    bcc = 0
    for i in range(len(data)-1):
        bcc ^= data[i]
    if bcc == data[-1]:
        return True
    else:
        return False
        # glob.com.write('P'.encode('UTF-8'))


def xor_check(data):
    """
    对数据采用异或校验
    :param data:
    :return: 校验通过返回 True，错误返回 False
    """
    offset = lambda x: (str("0") + x) if (len(x) == 1) else x

    bcc = 0
    for i in range(len(data)):
        bcc ^= data[i]
    return bytes.fromhex(offset(hex(bcc)[2:]))