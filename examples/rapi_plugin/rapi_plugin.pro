include (../common.pri)
include (../library/skydel_rapi/skydel_rapi.pri)

QT += gui widgets

SOURCES += \
    rapi_plugin.cpp \
    rapi_plugin_view.cpp

HEADERS += \
    rapi_plugin.h \
    rapi_plugin_view.h

FORMS += \
    rapi_plugin_view.ui

DISTFILES += \
    rapi_plugin.json

LIBS += $$SKYDEL_RAPI
