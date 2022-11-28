cmake_minimum_required(VERSION 3.23)
project(Matrix_Operation C)

set(CMAKE_C_STANDARD 11)

add_executable(Matrix_Operation
        lu_decomposition.c
        matrix_multiplication.c
        matrix_multiplication_banded.c
        matrix_multiplication_triangular.c
        matrix_transposition.c
        matrix_transposition_blocked.c
        matrix_transposition_in_place.c)

add_executable(lu_decomposition lu_decomposition.c)
add_executable(matrix_multiplication_triangular matrix_multiplication_triangular.c)