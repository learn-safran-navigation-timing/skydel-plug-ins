set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB SKYDEL_DEFAULT_INSTRUMENTATION_PLUGIN_SRC *.cpp *.ui)

add_library(skydel_default_instrumentation_plugin SHARED
    ${SKYDEL_DEFAULT_INSTRUMENTATION_PLUGIN_SRC}
    )

target_link_libraries(skydel_default_instrumentation_plugin PUBLIC
    Skydel::SkydelPlugin
    )

target_include_directories(skydel_default_instrumentation_plugin PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

set_target_properties(skydel_default_instrumentation_plugin PROPERTIES CXX_STANDARD 17)

install(TARGETS skydel_default_instrumentation_plugin DESTINATION ${PLUGIN_INSTALL_DIR})
