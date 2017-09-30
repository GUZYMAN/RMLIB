cmake_minimum_required(VERSION 3.8)
project(ServidorSockets)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Test.cpp)
add_executable(ServidorSockets ${SOURCE_FILES})