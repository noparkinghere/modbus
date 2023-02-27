# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'UI_hint.ui'
#
# Created by: PyQt5 UI code generator 5.12
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Form_Hint(object):
    def setupUi(self, Form_Hint):
        Form_Hint.setObjectName("Form_Hint")
        Form_Hint.resize(400, 186)
        self.label = QtWidgets.QLabel(Form_Hint)
        self.label.setGeometry(QtCore.QRect(110, 50, 201, 71))
        self.label.setObjectName("label")

        self.retranslateUi(Form_Hint)
        QtCore.QMetaObject.connectSlotsByName(Form_Hint)

    def retranslateUi(self, Form_Hint):
        _translate = QtCore.QCoreApplication.translate
        Form_Hint.setWindowTitle(_translate("Form_Hint", "正在读取数据中..."))
        self.label.setText(_translate("Form_Hint", "正在读取数据，请等待"))


