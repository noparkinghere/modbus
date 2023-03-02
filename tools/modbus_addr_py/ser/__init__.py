"""
        Created on 2019/12/11 18:42
        ————————————————————————————————————————————————————————————————————
        @File Name            :    __init__.py
        @Author                 :    Frank
        @Description        :
        
        ————————————————————————————————————————————————————————————————————
        @Change Activity:
    
"""

import sys
import traceback

from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QApplication, QMessageBox
import ser.mainWindow


def run():
    try:
        app = QApplication(sys.argv)
        w = ser.mainWindow.MyMainWindow()
        w.setWindowIcon(QIcon("D:\\OneDrive\work\\totalizer\\bus\\tools\\modbus_addr_py\\img.ico"))
        w.setWindowTitle("转换器测试工具")
        w.show()
        sys.exit(app.exec_())
    except Exception as e:
        traceback.print_exc()
        QMessageBox.critical(None, "Startup Error",
                                                 "Please notify support of this error:\n\n" +
                                                 traceback.format_exc())



def test():
    from project.utils import const
    a = const()
    print(a)

# class DialogManager:
#
#     _dialogs = {
#         "AddCards": [addcards.AddCards, None],
#         "Browser": [browser.Browser, None],
#         "EditCurrent": [editcurrent.EditCurrent, None],
#         "DeckStats": [stats.DeckStats, None],
#         "About": [about.show, None],
#         "Preferences": [preferences.Preferences, None],
#     }
#
#     def open(self, name, *args):
#         (creator, instance) = self._dialogs[name]
#         if instance:
#             if instance.windowState() & Qt.WindowMinimized:
#                 instance.setWindowState(instance.windowState() & ~Qt.WindowMinimized)
#             instance.activateWindow()
#             instance.raise_()
#             if hasattr(instance, "reopen"):
#                 instance.reopen(*args)
#             return instance
#         else:
#             instance = creator(*args)
#             self._dialogs[name][1] = instance
#             return instance
#
#     def markClosed(self, name):
#         self._dialogs[name] = [self._dialogs[name][0], None]
#
#     def allClosed(self):
#         return not any(x[1] for x in self._dialogs.values())
#
#     def closeAll(self, onsuccess):
#         # can we close immediately?
#         if self.allClosed():
#             onsuccess()
#             return
#
#         # ask all windows to close and await a reply
#         for (name, (creator, instance)) in self._dialogs.items():
#             if not instance:
#                 continue
#
#             def callback():
#                 if self.allClosed():
#                     onsuccess()
#                 else:
#                     # still waiting for others to close
#                     pass
#
#             if getattr(instance, "silentlyClose", False):
#                 instance.close()
#                 callback()
#             else:
#                 instance.closeWithCallback(callback)
#
#         return True
#
#
# dialogs = DialogManager()