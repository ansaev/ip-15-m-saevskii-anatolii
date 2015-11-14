cmake_minimum_required(VERSION 3.3)
project(stacklst)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp stack_list.h)
add_executable(stacklst ${SOURCE_FILES} stack_list.h)