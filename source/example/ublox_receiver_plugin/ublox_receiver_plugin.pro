include (../common.pri)

QT       += gui widgets

SOURCES += \
    ublox_receiver_plugin.cpp \
    ublox_receiver_view.cpp

HEADERS += \
    ublox_receiver_plugin.h \
    ublox_receiver_view.h

FORMS += \
    ublox_receiver_view.ui

DISTFILES += \
    ublox_receiver_plugin.json
