file(GLOB_RECURSE SKYDEL_RAPI_SRC sdx_api/*.cpp)

add_library(skydel_rapi STATIC ${SKYDEL_RAPI_SRC})

target_include_directories(skydel_rapi PUBLIC sdx_api sdx_api/gen sdx_api/rapidjson)

if(UNIX)
target_compile_options(skydel_rapi PUBLIC -fPIC)
endif()

target_compile_definitions(skydel_rapi PUBLIC $<$<BOOL:${UNIX}>:GUID_LIBUUID> $<$<BOOL:${WIN32}>:GUID_WINDOWS>)
