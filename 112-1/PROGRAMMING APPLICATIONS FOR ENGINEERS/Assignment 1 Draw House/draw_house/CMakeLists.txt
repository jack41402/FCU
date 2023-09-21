cmake_minimum_required(VERSION 3.24)
project(draw_house C)

set(CMAKE_C_STANDARD 11)

add_executable(draw_house main.c
        jason.c)

add_executable(corrine corrine.c)
add_executable(jason jason.c)