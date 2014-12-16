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
    riepilogo.cpp

HEADERS  += mainwindow.h \
    test.h \
    startdialog.h \
    form.h \
    riepilogo.h

FORMS    += mainwindow.ui \
    startdialog.ui \
    form.ui \
    riepilogo.ui

RESOURCES += \
    risorse.qrc
