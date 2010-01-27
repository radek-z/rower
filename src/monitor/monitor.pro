TEMPLATE = app
TARGET = rower-monitor
QT += gui

HEADERS += interface.h \
    mainwindow.h 
SOURCES += main.cpp \
    mainwindow.cpp

INCLUDEPATH += . \
    ../
    ../plugins \
    ../../include

CONFIG += debug_and_release \
    build_all 
