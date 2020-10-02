! include (../sdk/skydel_plugin_sdk.pri) {
    error( "Couldn't find the skydel_plugin_sdk.pri file!" )
}

TEMPLATE = lib
CONFIG += plugin

linux-oe-g++: {
    QMAKE_CXXFLAGS *= -std=c++17
}

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

DESTDIR = $$PWD/../../bin
OBJECTS_DIR = $$PWD/../../tmp/$$TARGET
MOC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR
