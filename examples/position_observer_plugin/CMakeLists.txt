set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Network REQUIRED)

add_library(position_observer_plugin SHARED
    position_logger.cpp
    position_observer_plugin.cpp
    position_observer_view.cpp
    position_observer_view.ui
    )

target_link_libraries(position_observer_plugin PUBLIC
    Skydel::SkydelPlugin
    Qt5::Network
    )

target_include_directories(position_observer_plugin PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

set_target_properties(position_observer_plugin PROPERTIES CXX_STANDARD 17)

install(TARGETS position_observer_plugin DESTINATION ${PLUGIN_INSTALL_DIR})
