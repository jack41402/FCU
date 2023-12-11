cmake_minimum_required(VERSION 3.24)
project(Assignment1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -UTF8")
set(CMAKE_C_STANDARD 11)

file(GLOB SUBDIRECTORIES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

foreach(SUBDIR ${SUBDIRECTORIES})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
        file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/*.c)

        if(SOURCES)
            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
            add_executable(${SUBDIR} ${SOURCES})
        endif()
    endif()
endforeach()
