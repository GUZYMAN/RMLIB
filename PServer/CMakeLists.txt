cmake_minimum_required(VERSION 3.8)
project(PServer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp rmRef_h.cpp rmRef_h.h library.h library.cpp)
add_executable(PServer ${SOURCE_FILES})