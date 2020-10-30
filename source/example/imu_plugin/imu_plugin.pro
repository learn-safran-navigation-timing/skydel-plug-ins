! include (../common.pri) {
    error( "Couldn't find the common.pri file!" )
}
! include (../../library/inertial_math/inertial_math.pri) {
    error( "Couldn't find the inertial_math.pri file!" )
}

QT += gui widgets network

SOURCES += \
    imu_configuration.cpp \
    imu_dynamic.cpp \
    imu_logger.cpp \
    imu_plugin.cpp \
    imu_view.cpp

HEADERS += \
    imu_configuration.h \
    imu_data_format.h \
    imu_dynamic.h \
    imu_logger.h \
    imu_plugin.h \
    imu_view.h

FORMS += \
    imu_view.ui

DISTFILES += \
    imu_plugin.json

LIBS = $$INERTIAL_MATH
