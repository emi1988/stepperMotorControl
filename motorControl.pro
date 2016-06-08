#-------------------------------------------------
#
# Project created by QtCreator 2016-06-08T18:40:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = motorControl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


LIBS += -L/usr/local/lib -lwiringPi

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include
