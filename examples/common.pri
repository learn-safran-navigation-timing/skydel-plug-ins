include (../skydel_plugin_sdk.pri)

TEMPLATE = lib
CONFIG += plugin

linux-oe-g++: {
    QMAKE_CXXFLAGS *= -std=c++17
}

CONFIG += c++17

ROOT=$$PWD/../
DESTDIR = $$ROOT/bin
OBJECTS_DIR = $$ROOT/tmp/$$TARGET
MOC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR
