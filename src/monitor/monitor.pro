TEMPLATE = app
TARGET = rower
DESTDIR = ../../bin
QT += gui

HEADERS += monitor.h
SOURCES += main.cpp \
            monitor.cpp

INCLUDEPATH += . \
    ../ \
    ../plugins \
    ../../include \
    ../../lib

CONFIG += debug_and_release \
    build_all 
