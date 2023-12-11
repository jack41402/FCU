cmake_minimum_required(VERSION 3.23)
project(Integrals C)

set(CMAKE_C_STANDARD 11)

add_executable(Integrals
        riemann_sum.c
        riemann_sum_two_curves.c)

add_executable(riemann_sum riemann_sum.c)