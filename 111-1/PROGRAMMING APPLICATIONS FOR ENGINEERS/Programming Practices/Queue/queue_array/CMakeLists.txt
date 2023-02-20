cmake_minimum_required(VERSION 3.24)
project(queue_array C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(queue_array
        queue_array.c
        queue_array.h
        queue_array_main.c)
