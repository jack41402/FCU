cmake_minimum_required(VERSION 3.24)
project(Assignment1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -UTF8")
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# Find all subdirectories excluding "build" and "skip"
file(GLOB SUBDIRECTORIES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
list(FILTER SUBDIRECTORIES EXCLUDE REGEX "/(build|skip)$")

function(find_sources DIRECTORY_NAME)
    file(GLOB C_FILES ${CMAKE_CURRENT_SOURCE_DIR}/${DIRECTORY_NAME}/*.c)
    file(GLOB H_FILES ${CMAKE_CURRENT_SOURCE_DIR}/${DIRECTORY_NAME}/*.h)
    set(SOURCES ${C_FILES} ${H_FILES} PARENT_SCOPE)  # Set SOURCES with PARENT_SCOPE
endfunction()

foreach(SUBDIR ${SUBDIRECTORIES})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
        find_sources(${SUBDIR})
        if(SOURCES)  # Only add_executable if sources are found
            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
            add_executable(${SUBDIR} ${SOURCES})  # Use SOURCES variable here
        endif()
    endif()
endforeach(SUBDIR)
