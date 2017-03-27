cmake_minimum_required(VERSION 3.5)
project(3DStudy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vector3.cpp Vector3.h)
add_executable(3DStudy ${SOURCE_FILES})