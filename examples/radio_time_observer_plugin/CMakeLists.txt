set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Network REQUIRED)

file(GLOB RADIO_TIME_OBSERVER_PLUGIN_SRC *.cpp *.ui)

add_library(radio_time_observer_plugin SHARED
    ${RADIO_TIME_OBSERVER_PLUGIN_SRC}
	runtime_objects.h
    )

target_link_libraries(radio_time_observer_plugin PUBLIC
    Skydel::SkydelPlugin
	Qt5::Network
    )

target_include_directories(radio_time_observer_plugin PUBLIC
    ${RADIO_TIME_OBSERVER_PLUGIN_SRC}
    )

set_target_properties(radio_time_observer_plugin PROPERTIES CXX_STANDARD 17)

install(TARGETS radio_time_observer_plugin DESTINATION ${PLUGIN_INSTALL_DIR})