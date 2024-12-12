file(GLOB_RECURSE SKYDEL_RAPI_SRC sdx_api/*.cpp)

add_library(skydel_rapi STATIC ${SKYDEL_RAPI_SRC})

target_include_directories(skydel_rapi PUBLIC sdx_api sdx_api/gen
                                              sdx_api/rapidjson)

if(WIN32)
  target_compile_definitions(skydel_rapi PUBLIC GUID_WINDOWS=1)
  target_link_libraries(skydel_rapi PUBLIC Ole32 ws2_32)
  target_compile_options(skydel_rapi PRIVATE /wd4244 /wd4838 /wd4701)
else()
  target_compile_options(skydel_rapi PUBLIC -fPIC)
  target_compile_definitions(skydel_rapi PUBLIC GUID_LIBUUID=1)
  target_link_libraries(skydel_rapi PUBLIC uuid)
  target_compile_options(skydel_rapi PRIVATE -Wno-old-style-cast
                                             -Wno-zero-as-null-pointer-constant)
endif()
