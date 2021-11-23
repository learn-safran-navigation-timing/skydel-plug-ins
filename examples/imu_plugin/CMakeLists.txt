set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Network REQUIRED)

add_library(imu_plugin SHARED
    imu_configuration.cpp
    imu_dynamic.cpp
    imu_logger.cpp
    imu_plugin.cpp
    imu_view.cpp
    imu_view.ui
    )

target_link_libraries(imu_plugin PUBLIC
    Skydel::SkydelPlugin
    Qt5::Network
    inertial_math
    )

target_include_directories(imu_plugin PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

set_target_properties(imu_plugin PROPERTIES CXX_STANDARD 17)

install(TARGETS imu_plugin DESTINATION ${PLUGIN_INSTALL_DIR})
