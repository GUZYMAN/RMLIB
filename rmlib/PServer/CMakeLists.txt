cmake_minimum_required(VERSION 3.8)
project(PServer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp library.cpp library.h)
add_executable(PServer ${SOURCE_FILES})