set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB RAPI_PLUGIN_SRC *.cpp *.ui)

add_library(rapi_plugin SHARED
    ${RAPI_PLUGIN_SRC}
    )

target_link_libraries(rapi_plugin PUBLIC
    Skydel::SkydelPlugin
    skydel_rapi
    )

set_target_properties(rapi_plugin PROPERTIES CXX_STANDARD 17)

install(TARGETS rapi_plugin DESTINATION ${PLUGIN_INSTALL_DIR})
