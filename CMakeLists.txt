cmake_minimum_required(VERSION 3.3)
project(ip15mAnatoliiSaevskii)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES_COMPLEX complex_number/main.cpp complex_number/ComplexNumber.cpp complex_number/ComplexNumberTests.cpp )
set(SOURCE_FILES_RATIONAL rational_number/main.cpp )
set(SOURCE_FILES_NVECTOR nvector/main.cpp nvector/nvector.h)
set(SOURCE_FILES_ZN_VECTOR znvector/main.cpp znvector/znvector.h)
set(SOURCE_FILES_VECTOR3 vector3/main.cpp)
set(SOURCE_FILES_STACKARRAY stackarray/stackarray.cpp)
set(SOURCE_FILES_STACKLST stacklst/main.cpp stacklst/stack_list.h)

add_executable(RationalNumber ${SOURCE_FILES_RATIONAL})
add_executable(ComplexNumber ${SOURCE_FILES_COMPLEX} )
add_executable(NVector ${SOURCE_FILES_NVECTOR} )
add_executable(ZnVector ${SOURCE_FILES_ZN_VECTOR} )
add_executable(Vector3 ${SOURCE_FILES_VECTOR3} )

add_executable(StackArray ${SOURCE_FILES_STACKARRAY} )
add_executable(StackList ${SOURCE_FILES_STACKLST} )

