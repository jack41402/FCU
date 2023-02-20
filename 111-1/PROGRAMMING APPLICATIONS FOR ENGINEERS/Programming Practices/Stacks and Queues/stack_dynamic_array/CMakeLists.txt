cmake_minimum_required(VERSION 3.24)
project(stack_dynamic_array C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(stack_dynamic_array
        stack_dynamic_array.c
        stack_dynamic_array.h
        stack_dynamic_array_main.c)
