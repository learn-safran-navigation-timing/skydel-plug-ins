TEMPLATE = subdirs

SUBDIRS += \
    library \
    imu_plugin \
    position_observer_plugin \
    simple_plugin \
    skydel_default_instrumentation_plugin \
    rapi_plugin

imu_plugin.depends = library
rapi_plugin.depends = library
