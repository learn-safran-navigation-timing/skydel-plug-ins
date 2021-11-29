include (../common.pri)

QT += gui widgets network

SOURCES += \
    delayed_broadcaster.cpp \
    radio_time_logger.cpp \
    radio_time_observer_plugin.cpp \
    radio_time_observer_view.cpp

HEADERS += \
    delayed_broadcaster.h \
    radio_time_logger.h \
    radio_time_observer_plugin.h \
    radio_time_observer_view.h \
    runtime_objects.h

FORMS += \
    radio_time_observer_view.ui

DISTFILES += \
    radio_time_observer_plugin.json
