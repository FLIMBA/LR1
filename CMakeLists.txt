set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)
project(main
LANGUAGES CXX
VERSION 0.0.1
)
add_executable(main 
    src/main.cpp
    src/stroki.cpp
    src/console.cpp
    inc/stroki.h
    inc/console.h
)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
#message("РОМУ 67  --> ${CMAKE_CURRENT_SOURCE_DIR}")