
cmake_minimum_required(VERSION 3.5...3.20)
project( ASSIGNMENT1)
find_package(PkgConfig REQUIRED)
file(GLOB_RECURSE ASSIGNMENT1_src
"src/*.cpp"
"src/*/*.cpp"
"src/*.h"
)
add_executable(ASSIGNMENT1 ${ASSIGNMENT1_src})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
target_link_libraries(ASSIGNMENT1)
#set(EXECUTABLE_OUTPUT_PATH "../bin")
set(CMAKE_BINARY_DIR "../bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
