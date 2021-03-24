! include (../common.pri) {
    error( "Couldn't find the common.pri file!" )
}
! include (../../library/skydel_rapi/skydel_rapi.pri) {
    error( "Couldn't find the skydel_rapi.pri file!" )
}

QT += gui widgets

SOURCES += \
    rapi_plugin.cpp \
    rapi_plugin_view.cpp

HEADERS += \
    rapi_plugin.h \
    rapi_plugin_view.h

DISTFILES += \
    rapi_plugin.json

FORMS += \
    rapi_plugin_view.ui

LIBS += $$SKYDEL_RAPI
