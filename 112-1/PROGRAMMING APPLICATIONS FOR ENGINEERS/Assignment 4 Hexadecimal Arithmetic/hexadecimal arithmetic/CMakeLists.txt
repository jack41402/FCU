cmake_minimum_required(VERSION 3.26)
project(hexadecimal_arithmetic C)

set(CMAKE_C_STANDARD 11)

add_executable(hexadecimal_arithmetic addition.c
        multiplication.c)

add_executable(multiplication multiplication.c)