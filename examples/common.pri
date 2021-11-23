! include (../skydel_plugin_sdk.pri) {
    error( "Couldn't find the skydel_plugin_sdk.pri file!" )
}

TEMPLATE = lib
CONFIG += plugin

linux-oe-g++: {
    QMAKE_CXXFLAGS *= -std=c++17
}

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

ROOT=$$PWD/../
DESTDIR = $$ROOT/bin
OBJECTS_DIR = $$ROOT/tmp/$$TARGET
MOC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR
