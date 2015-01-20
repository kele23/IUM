-#-------------------------------------------------
-#
-# Project created by QtCreator 2014-12-13T09:41:45
-#
-#-------------------------------------------------
-
QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IUM
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    startdialog.cpp \
    riepilogo.cpp \
    test1/test1.cpp \
    test2/test2.cpp \
    test2/paneltest2.cpp \
    test1/panel1test1.cpp

HEADERS  += mainwindow.h \
    test.h \
    startdialog.h \
    riepilogo.h \
    test1/test1.h \
    test2/test2.h \
    test2/paneltest2.h \
    test2/exam.h \
    test1/panel1test1.h \
    result.h

FORMS    += mainwindow.ui \
    startdialog.ui \
    riepilogo.ui \
    test2/paneltest2.ui \
    test1/panel1test1.ui

RESOURCES += \
    risorse.qrc

QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter
