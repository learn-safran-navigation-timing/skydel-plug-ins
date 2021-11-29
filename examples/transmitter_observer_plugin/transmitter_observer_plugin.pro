include (../common.pri)

QT += gui widgets network

SOURCES += \
    logger.cpp \
    runtime_position_observer.cpp \
    runtime_transmitter_observer.cpp \
    transmitter_observer_plugin.cpp \
    transmitter_observer_view.cpp

HEADERS += \
    logger.h \
    runtime_position_observer.h \
    runtime_transmitter_observer.h \
    transmitter_observer_plugin.h \
    transmitter_observer_view.h

FORMS += \
    transmitter_observer_view.ui

DISTFILES += \
    transmitter_observer_plugin.json
