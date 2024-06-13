QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ultrasonic
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp

HEADERS += mainwindow.h
# Include wiringPi library
LIBS += -lwiringPi
