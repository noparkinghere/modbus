# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'UI_serial.ui'
#
# Created by: PyQt5 UI code generator 5.13.2
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Form_serial(object):
    def setupUi(self, Form_serial):
        Form_serial.setObjectName("Form_serial")
        Form_serial.resize(532, 595)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(Form_serial)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setSizeConstraint(QtWidgets.QLayout.SetMinimumSize)
        self.gridLayout.setObjectName("gridLayout")
        self.label_2 = QtWidgets.QLabel(Form_serial)
        self.label_2.setObjectName("label_2")
        self.gridLayout.addWidget(self.label_2, 1, 3, 1, 1)
        self.senddata_line = QtWidgets.QLineEdit(Form_serial)
        self.senddata_line.setObjectName("senddata_line")
        self.gridLayout.addWidget(self.senddata_line, 0, 1, 1, 9)
        self.label_3 = QtWidgets.QLabel(Form_serial)
        self.label_3.setObjectName("label_3")
        self.gridLayout.addWidget(self.label_3, 1, 5, 1, 1)
        self.clear_btn = QtWidgets.QPushButton(Form_serial)
        self.clear_btn.setObjectName("clear_btn")
        self.gridLayout.addWidget(self.clear_btn, 1, 8, 1, 1)
        self.repet_btn = QtWidgets.QPushButton(Form_serial)
        self.repet_btn.setObjectName("repet_btn")
        self.gridLayout.addWidget(self.repet_btn, 1, 6, 1, 1)
        self.send_btn = QtWidgets.QPushButton(Form_serial)
        self.send_btn.setObjectName("send_btn")
        self.gridLayout.addWidget(self.send_btn, 1, 0, 1, 1)
        self.hex_box = QtWidgets.QCheckBox(Form_serial)
        self.hex_box.setChecked(True)
        self.hex_box.setObjectName("hex_box")
        self.gridLayout.addWidget(self.hex_box, 1, 2, 1, 1)
        self.senddata_label = QtWidgets.QLabel(Form_serial)
        self.senddata_label.setObjectName("senddata_label")
        self.gridLayout.addWidget(self.senddata_label, 0, 0, 1, 1)
        self.second_line = QtWidgets.QLineEdit(Form_serial)
        self.second_line.setObjectName("second_line")
        self.gridLayout.addWidget(self.second_line, 1, 4, 1, 1)
        self.stop_btn = QtWidgets.QPushButton(Form_serial)
        self.stop_btn.setObjectName("stop_btn")
        self.gridLayout.addWidget(self.stop_btn, 1, 7, 1, 1)
        self.verticalLayout_2.addLayout(self.gridLayout)
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setSizeConstraint(QtWidgets.QLayout.SetMinimumSize)
        self.verticalLayout.setSpacing(12)
        self.verticalLayout.setObjectName("verticalLayout")
        self.rev_Text = QtWidgets.QTextEdit(Form_serial)
        self.rev_Text.setObjectName("rev_Text")
        self.verticalLayout.addWidget(self.rev_Text)
        self.label_4 = QtWidgets.QLabel(Form_serial)
        self.label_4.setObjectName("label_4")
        self.verticalLayout.addWidget(self.label_4)
        self.expdata_line = QtWidgets.QLineEdit(Form_serial)
        self.expdata_line.setObjectName("expdata_line")
        self.verticalLayout.addWidget(self.expdata_line)
        self.verticalLayout_2.addLayout(self.verticalLayout)

        self.retranslateUi(Form_serial)
        QtCore.QMetaObject.connectSlotsByName(Form_serial)

    def retranslateUi(self, Form_serial):
        _translate = QtCore.QCoreApplication.translate
        Form_serial.setWindowTitle(_translate("Form_serial", "串口助手"))
        self.label_2.setText(_translate("Form_serial", "每隔"))
        self.label_3.setText(_translate("Form_serial", "秒"))
        self.clear_btn.setText(_translate("Form_serial", "清空数据"))
        self.repet_btn.setText(_translate("Form_serial", "重复发送"))
        self.send_btn.setText(_translate("Form_serial", "单次发送"))
        self.hex_box.setText(_translate("Form_serial", "16进制显示"))
        self.senddata_label.setText(_translate("Form_serial", "发送数据"))
        self.stop_btn.setText(_translate("Form_serial", "停止发送"))
        self.rev_Text.setHtml(_translate("Form_serial", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'SimSun\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>"))
        self.label_4.setText(_translate("Form_serial", "实时显示转换数据如下："))
