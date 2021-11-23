include (../../../external/blaze/blaze.pri)

TEMPLATE = lib
CONFIG += c++17
CONFIG += staticlib

linux-oe-g++: {
    QMAKE_CXXFLAGS *= -std=c++17
}

DEFINES += QT_DEPRECATED_WARNINGS

LIBS += $$BLAZE_LIBS

HEADERS += \
    include/angle_unwrap.h \
    include/constant.h \
    include/coriolis_force.h \
    include/dynamic.h \
    include/gravity.h \
    include/rotation_matrix.h \
    include/sensor.h \
    include/transformation.h \
    include/triplet.h \
    include/utility.h

SOURCES += \
    source/angle_unwrap.cpp \
    source/coriolis_force.cpp \
    source/dynamic.cpp \
    source/gravity.cpp \
    source/rotation_matrix.cpp \
    source/sensor.cpp \
    source/transformation.cpp

INCLUDEPATH *= $$PWD/include

DESTDIR = $$PWD/../../../bin
OBJECTS_DIR = $$PWD/../../../tmp/$$TARGET
MOC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR
