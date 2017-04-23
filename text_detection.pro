#-------------------------------------------------
#
# Project created by QtCreator 2017-04-22T15:50:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = text_detection
TEMPLATE = app

INCLUDEPATH += "D:\Libraries\opencv\build\include"
CONFIG += c++11

LIBS += -LD:\Libraries\opencv\build\x64\vc14\lib -lopencv_world320d

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    closeerdgeelements.cpp \
    fusion.cpp \
    gradient.cpp \
    interactiveimage.cpp

HEADERS  += mainwindow.h \
    closeerdgeelements.h \
    fusion.h \
    gradient.h \
    interactiveimage.h

FORMS    += mainwindow.ui