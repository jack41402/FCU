cmake_minimum_required(VERSION 3.23)
project(Rational_Number C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Rational_Number
        rational_number.c
        rational_number.h
        rational_number_main.c)
