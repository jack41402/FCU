cmake_minimum_required(VERSION 3.23)
project(basic_io C)

set(CMAKE_C_STANDARD 11)

add_executable(basic_io
        escape_sequence.c
        integer_alignment.c
        integer_io.c
        string_to_character.c
        text_line.c
        upper_case_in_order.c)
add_executable(integer_alignment integer_alignment.c)