cmake_minimum_required(VERSION 3.24)
project(Quiz1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

file(GLOB SUBDIRECTORIES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

foreach(SUBDIR ${SUBDIRECTORIES})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
        file(GLOB C_FILES ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/*.c)
        foreach (C_FILE ${C_FILES})
            get_filename_component(C_FILE_NAME ${C_FILE} NAME_WE)
            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})

            # Attempt to compile the source file
            try_compile(COMPILE_RESULT
                        ${CMAKE_BINARY_DIR}/compile_test
                        SOURCES ${C_FILE}
                        OUTPUT_VARIABLE COMPILE_OUTPUT)

            # Check if the compilation was successful
            if(COMPILE_RESULT)
                add_executable(${C_FILE_NAME} ${C_FILE})
            else()
                get_filename_component(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR} DIRECTORY)
                string(REPLACE "${BASE_DIR}/" "" C_FILE_RELATIVE ${C_FILE})
                message(STATUS "Compilation failed for file: ${C_FILE_RELATIVE}")
                # message(STATUS "Compiler output: ${COMPILE_OUTPUT}")
            endif()
        endforeach (C_FILE)
    endif()
endforeach(SUBDIR)
