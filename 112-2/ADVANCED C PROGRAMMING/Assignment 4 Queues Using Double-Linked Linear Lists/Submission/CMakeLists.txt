cmake_minimum_required(VERSION 3.10)

project(MultiExecutableProject)
set(CMAKE_CXX_STANDARD 11)

option(ENABLE_COMPILATION_TESTS "Enable compilation tests for source files" OFF)

function(add_executables_in_directory DIR_PATH)
    set(src_files
        "${DIR_PATH}/IQueueMain.cpp"
        "${DIR_PATH}/IQueue.cpp"
        "${DIR_PATH}/Node.cpp"
    )

    set(headers
        "${DIR_PATH}/IQueue.h"
        "${DIR_PATH}/Node.h"
    )

    set(COMPILE_SUCCESS TRUE)

    if(COMPILE_SUCCESS)
        get_filename_component(bin_name ${DIR_PATH} NAME)
        add_executable(${bin_name} ${src_files})
        target_include_directories(${bin_name} PRIVATE ${DIR_PATH})
    else()
        file(APPEND "${CMAKE_BINARY_DIR}/compile_errors.log" "Skipping directory ${DIR_PATH} due to compilation errors:\n${COMPILE_OUTPUT}\n")
        message(WARNING "Skipping directory ${DIR_PATH} due to compilation errors.")
    endif()
endfunction()

file(GLOB children RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)
foreach(child ${children})
    if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${child}")
        add_executables_in_directory("${CMAKE_SOURCE_DIR}/${child}")
    endif()
endforeach()
