cmake_minimum_required(VERSION 3.17)

project(SkydelPlugin VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

if(NOT WIN32)
    set(CMAKE_CXX_COMPILER /usr/bin/g++-11 CACHE FILEPATH "GNU C++ compiler")
    set(Qt5_VERSION 5.15.17 CACHE STRING "Version of Qt5 you want to find")
    set(Qt5_ROOT /opt/Qt CACHE FILEPATH "Directory where you installed Qt5")
    set(Qt5_DIR "${Qt5_ROOT}/${Qt5_VERSION}/gcc_64/lib/cmake" CACHE FILEPATH "")
    list(APPEND CMAKE_PREFIX_PATH ${Qt5_DIR})
    set(PLUGIN_INSTALL_DIR "$ENV{HOME}/Documents/Skydel-SDX/Plug-ins" CACHE PATH "Define the destination folder where the plug-in examples are installed")
else()
    list(APPEND CMAKE_PREFIX_PATH "C:/Qt/5.15.17/msvc2019_64/lib/cmake")
    set(PLUGIN_INSTALL_DIR "$ENV{HOMEPATH}/Documents/Skydel-SDX/Plug-ins" CACHE PATH "Define the destination folder where the plug-in examples are installed")
endif()

### Dependencies
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

### Project
add_library(SkydelPlugin INTERFACE)

target_include_directories(SkydelPlugin INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

target_link_libraries(SkydelPlugin INTERFACE Qt5::Core Qt5::Widgets)

add_library(Skydel::SkydelPlugin ALIAS SkydelPlugin)

add_subdirectory(source)

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
