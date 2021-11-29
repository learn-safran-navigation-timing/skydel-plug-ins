TEMPLATE = subdirs

SUBDIRS += \
    hil_observer_plugin \
    imu_plugin \
    library \
    position_observer_plugin \
    radio_time_observer_plugin \
    rapi_plugin \
    simple_plugin \
    skydel_default_instrumentation_plugin \
    transmitter_observer_plugin

imu_plugin.depends = library
rapi_plugin.depends = library
