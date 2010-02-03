TEMPLATE = lib
TARGET = concept2plugin
DESTDIR = ../../../lib/
QT += core

CONFIG += plugin \
        debug_and_release \
        build_all \
        warn_on 

HEADERS += concept2plugin.h 

SOURCES += concept2plugin.cpp

INCLUDEPATH += . \
    ../ \
    ../../../include

LIBS += -L/usr/lib -lusb

headers.files = $$HEADERS
target.path = $${INSTALL_PREFIX}/lib/rower
INSTALLS = target
