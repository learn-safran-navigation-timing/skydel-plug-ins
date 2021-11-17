cmake_minimum_required(VERSION 3.17)

project(SkydelPlugin VERSION 0.0.1 LANGUAGES CXX)

set(BUILD_SKYDELPLUGIN_EXAMPLES ON CACHE BOOL "IF TRUE we build the example plugins")
set(INSTALL_SKYDELPLUGIN_EXAMPLES ON CACHE BOOL "IF TRUE we install the example plugins in $HOME/Documents/Skydel-SDX/Plug-ins")
if(NOT WIN32)
    set(PLUGIN_INSTALL_DIR "$ENV{HOME}/Documents/Skydel-SDX/Plug-ins" CACHE PATH "Define the destination folder at the insallation")
else()
    set(PLUGIN_INSTALL_DIR "$ENV{HOMEPATH}/Documents/Skydel-SDX/Plug-ins" CACHE PATH "Define the destination folder at the insallation")
endif()

### Dependencies
find_package(blaze 3.7 REQUIRED)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

### Project
add_library(SkydelPlugIn INTERFACE)

target_include_directories(SkydelPlugIn INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

target_link_libraries(SkydelPlugIn INTERFACE blaze::blaze Qt5::Core Qt5::Widgets)

add_library(Skydel::SkydelPlugIn ALIAS SkydelPlugIn)

if(BUILD_SKYDELPLUGIN_EXAMPLES)
        add_subdirectory(examples)
endif(BUILD_SKYDELPLUGIN_EXAMPLES)

### Installation / Export
include(CMakePackageConfigHelpers)

configure_package_config_file(cmake/SkydelPlugInConfig.cmake.in
    ${CMAKE_BINARY_DIR}/cmake/SkydelPlugInConfig.cmake
    INSTALL_DESTINATION lib/cmake/SkydelPlugIn
    )

install(
    TARGETS SkydelPlugIn #plus others if there is
    EXPORT SkydelPlugInTargets
    PUBLIC_HEADER DESTINATION include
    )

install( EXPORT SkydelPlugInTargets NAMESPACE "Skydel::" DESTINATION lib/cmake/SkydelPlugIn )

install(FILES ${CMAKE_BINARY_DIR}/cmake/SkydelPlugInConfig.cmake DESTINATION lib/cmake/SkydelPlugIn)

install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN *.h)

