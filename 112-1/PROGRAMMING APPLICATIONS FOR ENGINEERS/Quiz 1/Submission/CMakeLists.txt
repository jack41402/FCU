cmake_minimum_required(VERSION 3.24)
project(Assignment1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -UTF8")
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

file(GLOB SUBDIRECTORIES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

foreach(SUBDIR ${SUBDIRECTORIES})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
        file(GLOB C_FILES ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/*.c)
        foreach (C_FILE ${C_FILES})
            get_filename_component(C_FILE_NAME ${C_FILE} NAME_WE)
            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
            add_executable(${C_FILE_NAME} ${C_FILE})
        endforeach (C_FILE)
    endif()
endforeach(SUBDIR)
