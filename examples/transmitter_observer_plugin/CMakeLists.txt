set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Network REQUIRED)

file(GLOB TRANSMITTTER_OBSERVER_PLUGIN_SRC *.cpp *.ui)

add_library(transmitter_observer_plugin SHARED
    ${TRANSMITTTER_OBSERVER_PLUGIN_SRC}
    )

target_link_libraries(transmitter_observer_plugin PUBLIC
    Skydel::SkydelPlugin
	Qt5::Network
    )

target_include_directories(transmitter_observer_plugin PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

set_target_properties(transmitter_observer_plugin PROPERTIES CXX_STANDARD 17)

install(TARGETS transmitter_observer_plugin DESTINATION ${PLUGIN_INSTALL_DIR})