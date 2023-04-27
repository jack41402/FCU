cmake_minimum_required(VERSION 3.24)
project(Mexam C)

set(CMAKE_C_STANDARD 11)

add_executable(Mexam
        mexam_d1166506_1.c
        mexam_d1166506_2.c
        mexam_d1166506_3.c)

add_executable(mexam_d1166506_3 mexam_d1166506_3.c)