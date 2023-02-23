cmake_minimum_required(VERSION 3.24)
project(Bitmap_Image_Processing C)

set(CMAKE_C_STANDARD 11)

add_executable(Bitmap_Image_Processing
        image_banded_filter.c
        image_color_to_gray.c
        image_horizontal_mirror_reflection.c
        image_reduction_merge.c)
