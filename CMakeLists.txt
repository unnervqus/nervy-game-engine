cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME "Git-Init-Test")
set(TARGET_NAME "Example")
project(${PROJECT_NAME} LANGUAGES C CXX VERSION 0.0.1)

set(CXX_STANDARD_REQUIRED TRUE)
set(CXX_STANDARD 20)

set(TARGET_SOURCES test.c)

add_executable(${TARGET_NAME} WIN32 ${CMAKE_CURRENT_SOURCE_DIR}/src/${TARGET_SOURCES})

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${TARGET_NAME} PRIVATE -municode)
    target_link_options(${TARGET_NAME} PRIVATE -municode)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${TARGET_NAME} PRIVATE /subsystem:windows)
    target_link_options(${TARGET_NAME} PRIVATE /subsystem:windows)
endif()
