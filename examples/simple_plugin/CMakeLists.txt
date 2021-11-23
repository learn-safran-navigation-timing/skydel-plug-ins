set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB SIMPLE_PLUGIN_SRC *.cpp *.ui)

add_library(simple_plugin SHARED
    ${SIMPLE_PLUGIN_SRC}
    )

target_link_libraries(simple_plugin PUBLIC
    Skydel::SkydelPlugin
    )

target_include_directories(simple_plugin PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

set_target_properties(simple_plugin PROPERTIES CXX_STANDARD 17)

install(TARGETS simple_plugin DESTINATION ${PLUGIN_INSTALL_DIR})
