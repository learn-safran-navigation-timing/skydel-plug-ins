include (../common.pri)

QT += gui widgets

SOURCES += \
    hil_logger.cpp \
    hil_observer_plugin.cpp \
    hil_observer_view.cpp

HEADERS += \
    hil_logger.h \
    hil_observer_plugin.h \
    hil_observer_view.h

FORMS += \
    hil_observer_view.ui

DISTFILES += \
    hil_observer_plugin.json
