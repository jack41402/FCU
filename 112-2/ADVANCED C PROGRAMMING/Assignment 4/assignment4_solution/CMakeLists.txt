cmake_minimum_required(VERSION 3.27)
project(assignment4_solution)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment4_solution
        IQueue.cpp
        IQueue.h
        IQueueMain.cpp
        Node.cpp
        Node.h)
