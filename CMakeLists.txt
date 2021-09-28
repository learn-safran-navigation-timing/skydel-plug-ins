cmake_minimum_required(VERSION 3.17)

project(SkydelPlugin VERSION 0.0.1 LANGUAGES CXX)

set(BUILD_SKYDELPLUGIN_EXAMPLES ON CACHE BOOL "IF TRUE we build the example plugins")
set(INSTALL_SKYDELPLUGIN_EXAMPLES ON CACHE BOOL "IF TRUE we install the example plugins in $HOME/Documents/Skydel-SDX/Plug-ins")

### Dependencies
find_package(blaze 3.7 REQUIRED)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

### Project
add_library(SkydelPlugin INTERFACE)

target_include_directories(SkydelPlugin INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

target_link_libraries(SkydelPlugin INTERFACE blaze::blaze Qt5::Core Qt5::Widgets)

add_library(Skydel::SkydelPlugin ALIAS SkydelPlugin)

if(BUILD_SKYDELPLUGIN_EXAMPLES)
    if(NOT WIN32)
       set(PLUGIN_INSTALL_DIR "$ENV{HOME}/Documents/Skydel-SDX/Plug-ins")
    else()
       set(PLUGIN_INSTALL_DIR "$ENV{HOMEPATH}/Documents/Skydel-SDX/Plug-ins")
    endif()
        add_subdirectory(examples)
endif(BUILD_SKYDELPLUGIN_EXAMPLES)

### Installation / Export
include(CMakePackageConfigHelpers)

configure_package_config_file(cmake/SkydelPluginConfig.cmake.in
    ${CMAKE_BINARY_DIR}/cmake/SkydelPluginConfig.cmake
    INSTALL_DESTINATION lib/cmake/SkydelPlugin
    )

install(
    TARGETS SkydelPlugin #plus others if there is
    EXPORT SkydelPluginTargets
    PUBLIC_HEADER DESTINATION include
    )

install( EXPORT SkydelPluginTargets NAMESPACE "Skydel::" DESTINATION lib/cmake/SkydelPlugin )

install(FILES ${CMAKE_BINARY_DIR}/cmake/SkydelPluginConfig.cmake DESTINATION lib/cmake/SkydelPlugin)

install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN *.h)

