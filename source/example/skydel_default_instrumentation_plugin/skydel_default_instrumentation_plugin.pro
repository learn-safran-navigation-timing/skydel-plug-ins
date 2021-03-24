! include (../common.pri) {
    error( "Couldn't find the common.pri file!" )
}

QT += gui widgets

SOURCES += \
    skydel_default_instrumentation_plugin.cpp

HEADERS += \
    skydel_default_instrumentation_plugin.h

FORMS +=

DISTFILES += \
    skydel_default_instrumentation_plugin.json
