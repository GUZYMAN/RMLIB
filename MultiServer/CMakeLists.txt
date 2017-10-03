cmake_minimum_required(VERSION 3.8)
project(MultiServer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp client.cpp client.h mythread.h mythread.cpp server.h server.cpp
        NodeMem.cpp nodo.cpp nodo.h list.cpp list.h NodeMem.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(MultiServer ${SOURCE_FILES})
