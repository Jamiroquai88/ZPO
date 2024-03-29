#-------------------------------------------------
#
# Project created by QtCreator 2017-04-22T15:50:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = text_detection
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv /usr/local/include/tesseract
CONFIG += c++11

LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -ltesseract -llept

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
    fusion.cpp \
    gradient.cpp \
    interactiveimage.cpp \
    ocr.cpp \
    closeerdgeelements.cpp

HEADERS  += mainwindow.h \
    closeerdgeelements.h \
    fusion.h \
    gradient.h \
    interactiveimage.h \
    ocr.h

FORMS    += mainwindow.ui
