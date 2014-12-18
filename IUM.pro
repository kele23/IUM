-#-------------------------------------------------
-#
-# Project created by QtCreator 2014-12-13T09:41:45
-#
-#-------------------------------------------------
-
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IUM
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    startdialog.cpp \
    form.cpp \
    riepilogo.cpp \
    test1/test1.cpp \
    test1/panel1test1.cpp

HEADERS  += mainwindow.h \
    test.h \
    startdialog.h \
    form.h \
    riepilogo.h \
    test1/test1.h \
    test1/panel1test1.h

FORMS    += mainwindow.ui \
    startdialog.ui \
    riepilogo.ui \
    form.ui \
    test1/panel1test1.ui

RESOURCES += \
    risorse.qrc
