cmake_minimum_required(VERSION 3.17)

project(SkydelPlugin VERSION 0.0.1 LANGUAGES CXX)

set(BUILD_SKYDEL_PLUGIN_EXAMPLES ON CACHE BOOL "If TRUE the plug-in examples are built")
if(NOT WIN32)
    set(PLUGIN_INSTALL_DIR "$ENV{HOME}/Documents/Skydel-SDX/Plug-ins" CACHE PATH "Define the destination folder where the plug-in examples are installed")
else()
    set(PLUGIN_INSTALL_DIR "$ENV{HOMEPATH}/Documents/Skydel-SDX/Plug-ins" CACHE PATH "Define the destination folder where the plug-in examples are installed")
endif()

### Dependencies
find_package(blaze 3.7 REQUIRED)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

### Project
add_library(SkydelPlugin INTERFACE)

target_include_directories(SkydelPlugin INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

target_link_libraries(SkydelPlugin INTERFACE blaze::blaze Qt5::Core Qt5::Widgets)

add_library(Skydel::SkydelPlugin ALIAS SkydelPlugin)

if(BUILD_SKYDEL_PLUGIN_EXAMPLES)
    add_subdirectory(examples)
endif(BUILD_SKYDEL_PLUGIN_EXAMPLES)

### Installation / Export
include(CMakePackageConfigHelpers)

configure_package_config_file(cmake/SkydelPluginConfig.cmake.in
    ${CMAKE_BINARY_DIR}/cmake/SkydelPluginConfig.cmake
    INSTALL_DESTINATION lib/cmake/SkydelPlugin
    )

install(
    TARGETS SkydelPlugin # And others if there is
    EXPORT SkydelPluginTargets
    PUBLIC_HEADER DESTINATION include
    )

install(EXPORT SkydelPluginTargets NAMESPACE "Skydel::" DESTINATION lib/cmake/SkydelPlugin)

install(FILES ${CMAKE_BINARY_DIR}/cmake/SkydelPluginConfig.cmake DESTINATION lib/cmake/SkydelPlugin)

install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN *.h)
