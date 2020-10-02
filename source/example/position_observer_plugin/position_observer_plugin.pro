! include (../common.pri) {
    error( "Couldn't find the common.pri file!" )
}

QT += gui widgets network

SOURCES += \
    position_observer_plugin.cpp \
    position_observer_view.cpp

HEADERS += \
    position_observer_plugin.h \
    position_observer_view.h

FORMS += \
    position_observer_view.ui

DISTFILES += \
    position_observer_plugin.json
