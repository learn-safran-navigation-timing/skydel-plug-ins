file(GLOB_RECURSE INERTIAL_MATH_SRC source/*.cpp)

add_library(inertial_math STATIC ${INERTIAL_MATH_SRC})

target_include_directories(inertial_math PUBLIC include)

target_link_libraries(inertial_math PUBLIC
    blaze::blaze
    )

set_property(TARGET inertial_math PROPERTY CXX_STANDARD 17)

if(UNIX)
target_compile_options(inertial_math PUBLIC -fPIC)
endif()
