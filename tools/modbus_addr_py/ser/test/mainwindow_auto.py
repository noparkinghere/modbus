# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow_auto.ui'
#
# Created by: PyQt5 UI code generator 5.9.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(102, 144)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName("verticalLayout")
        self.btnStart = QtWidgets.QPushButton(self.centralwidget)
        self.btnStart.setObjectName("btnStart")
        self.verticalLayout.addWidget(self.btnStart)
        self.btnStop = QtWidgets.QPushButton(self.centralwidget)
        self.btnStop.setObjectName("btnStop")
        self.verticalLayout.addWidget(self.btnStop)
        self.lblAction = QtWidgets.QLabel(self.centralwidget)
        self.lblAction.setObjectName("lblAction")
        self.verticalLayout.addWidget(self.lblAction)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 102, 23))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.btnStart.setText(_translate("MainWindow", "btnStart"))
        self.btnStop.setText(_translate("MainWindow", "btnStop"))
        self.lblAction.setText(_translate("MainWindow", "lblAction"))

