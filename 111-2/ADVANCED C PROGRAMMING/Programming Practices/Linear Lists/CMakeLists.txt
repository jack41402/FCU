cmake_minimum_required(VERSION 3.24)
project(Linear_Lists C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Linear_Lists
        linear_list_dynamic_set.c
        linear_list_dynamic_set.h
        linear_list_dynamic_set_main.c)
