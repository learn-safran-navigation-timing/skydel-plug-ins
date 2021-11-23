message(STATUS "Building examples")

file(GLOB FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} LIST_DIRECTORIES FALSE  *)
file(GLOB EXAMPLES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)
list(REMOVE_ITEM EXAMPLES ${FILES})
list(REMOVE_ITEM EXAMPLES library)

message(STATUS "Building library")
add_subdirectory(library)

foreach(EXAMPLE ${EXAMPLES})
    message(STATUS "Building ${EXAMPLE}")
    add_subdirectory(${EXAMPLE})
endforeach()
