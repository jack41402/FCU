cmake_minimum_required(VERSION 3.27)
project(Assignment6_Linear_Equation_System_Solver)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment6_Linear_Equation_System_Solver
        linear_equation_system_solver.cpp
        matrix.cpp
        matrix.h
        smatrix.cpp
        smatrix.h
        vector.cpp
        vector.h)
