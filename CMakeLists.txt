project(dove)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE true)

add_compile_options(
    "-Wall" "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)
# cmake . -DCMAKE_BUILD_TYPE=Debug

include_directories(${PROJECT_SOURCE_DIR}/extern)

# 
# ------- dove --------
set(dovelib dove)
file(GLOB dovelib_src 
    CONFIGURE_DEPENDS 
    ${PROJECT_SOURCE_DIR}/src/*.cc 
    ${PROJECT_SOURCE_DIR}/src/sample/*.cc
    )

add_library(${dovelib} SHARED ${dovelib_src})
set_target_properties(
    ${dovelib} 
    PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib
)

# target_link_libraries(${dovelib} PUBLIC ibverbs pthread memcached hairtebeest)
target_link_libraries(${dovelib} PUBLIC pthread)


# 
# ------- Binaries --------
# Multi-threded test binary
set(dove_testbin dove-testbin)
add_executable(
    ${dove_testbin}
    ${PROJECT_SOURCE_DIR}/src/tests/dove-test.cc
)
set_target_properties(
    ${dove_testbin} 
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin
)
target_link_libraries(${dove_testbin} PUBLIC ${dovelib} pthread)
