include (../common.pri)

QT += gui widgets

SOURCES += \
    simple_plugin.cpp \
    simple_plugin_view.cpp

HEADERS += \
    simple_plugin.h \
    simple_plugin_view.h

FORMS += \
    simple_plugin_view.ui

DISTFILES += \
    simple_plugin.json
