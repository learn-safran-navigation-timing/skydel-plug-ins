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
win32:CONFIG(release, debug|release): EXAMPLE_OUT_DIR = $$ROOT/../bin/release/
else:win32:CONFIG(debug, debug|release): EXAMPLE_OUT_DIR = $$ROOT/../bin/debug/
else:unix: EXAMPLE_OUT_DIR = $$PWD/../../bin/

DESTDIR = $$EXAMPLE_OUT_DIR
OBJECTS_DIR = $$EXAMPLE_OUT_DIR/tmp/$$TARGET
MOC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR
