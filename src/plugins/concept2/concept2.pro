TEMPLATE = lib
TARGET = concept2plugin
DESTDIR = ../../lib/rower
QT += core

CONFIG += plugin \
        debug_and_release \
        build_all \
        warn_on \
        link_pkgconfig

HEADERS += concept2plugin.h \
        ../../../include/rowerpluginiface.h \

SOURCES += concept2plugin.cpp

INCLUDEPATH += . \
    ../ \
    ../../../include

PKGCONFIG += concept2
LIBS += -lconcept2

QMAKE_CLEAN += libconcept2.so
headers.files = $$HEADERS
target.path = $${INSTALL_PREFIX}/lib/rower
INSTALLS = target
