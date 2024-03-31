cmake_minimum_required(VERSION 3.27)
project(assignment1_solutions C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(assignment1_solutions
        complex.c
        complex.h
        quadratic_equation_verifier.c)
