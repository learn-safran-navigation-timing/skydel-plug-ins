TEMPLATE = lib
CONFIG += c++11
CONFIG += staticlib

win32: {
    QMAKE_CXXFLAGS += -bigobj
    DEFINES += GUID_WINDOWS=1
}
linux-oe-g++: {
    QMAKE_CXXFLAGS *= -std=c++11
}
unix: {
    DEFINES += GUID_LIBUUID=1
}

INCLUDEPATH += $$PWD/sdx_api

GEN_RAPI_PRO_FILE = $$PWD/sdx_api/gen_rapi_commands.pro
exists($$GEN_RAPI_PRO_FILE) {
    EXTRA_SOURCES = $$fromfile($$GEN_RAPI_PRO_FILE, SOURCES)
    EXTRA_HEADERS = $$fromfile($$GEN_RAPI_PRO_FILE, HEADERS)
}
SOURCES += $$EXTRA_SOURCES
HEADERS += $$EXTRA_HEADERS

DESTDIR = $$PWD/../../../bin
OBJECTS_DIR = $$PWD/../../../tmp/$$TARGET
MOC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR
