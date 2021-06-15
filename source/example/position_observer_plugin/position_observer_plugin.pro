include (../common.pri)

QT += gui widgets network

SOURCES += \
    position_logger.cpp \
    position_observer_plugin.cpp \
    position_observer_view.cpp

HEADERS += \
    position_logger.h \
    position_observer_plugin.h \
    position_observer_view.h

FORMS += \
    position_observer_view.ui

DISTFILES += \
    position_observer_plugin.json
