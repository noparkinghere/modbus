from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo
from PyQt5.Qt import QThread, pyqtSignal

class Com(QSerialPort, QThread):
    # 声明一个信号
    update_ui_signal = pyqtSignal(bytes, int)

    def __init__(self, list_sound):
        super(Com, self).__init__()

    def run(self):
        # 读取数据
        glob.g_rev_data = b''
        str_data = ''
        for cnt in range(500):
            if self.waitForReadyRead(2):
                self.g_rev_data += bytes(glob.com.readAll())
                self.g_rev_flag = True
        self.update_ui_signal.emit(self.g_rev_data, self.g_rev_flag)

