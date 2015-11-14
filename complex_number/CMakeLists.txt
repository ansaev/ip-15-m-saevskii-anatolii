cmake_minimum_required(VERSION 3.3)
project(ComplexNumberProg)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ComplexNumber.cpp ComplexNumberTests.cpp )
add_executable(ComplexNumber ${SOURCE_FILES} ComplexNumber.cpp ComplexNumberTests.cpp )
#set(SOURCE_FILES main.cpp  ComplexNumber.cpp)
#add_executable(ComplexNumber ${SOURCE_FILES} ComplexNumber.cpp )