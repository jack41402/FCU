cmake_minimum_required(VERSION 3.23)
project(Logic_Operations C)

set(CMAKE_C_STANDARD 11)

add_executable(Logic_Operations
        binary_adder.c
        bitwise_logic_operations.c
        parity_check.c)
