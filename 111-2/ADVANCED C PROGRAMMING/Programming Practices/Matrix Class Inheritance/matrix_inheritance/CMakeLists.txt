cmake_minimum_required(VERSION 3.24)
project(matrix_inheritance)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(matrix_inheritance
        matrix_inheritance.cpp
        matrix_inheritance.h
        matrix_inheritance_main.cpp
        smatrix_inheritance.cpp
        smatrix_inheritance.h
        vector_inheritance.cpp
        vector_inheritance.h)
