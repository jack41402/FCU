cmake_minimum_required(VERSION 3.24)
project(Rational_Number_Operator_Overloading)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Rational_Number_Operator_Overloading
        rational_overloading.cpp
        rational_overloading.h
        rational_overloading_main.cpp)
