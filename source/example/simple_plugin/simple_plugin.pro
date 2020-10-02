! include (../common.pri) {
    error( "Couldn't find the common.pri file!" )
}

QT += gui widgets

SOURCES += \
    simple_plugin.cpp \
    simple_plugin_view.cpp

HEADERS += \
    simple_plugin.h \
    simple_plugin_view.h

DISTFILES += \
    simple_plugin.json

FORMS += \
    simple_plugin_view.ui
