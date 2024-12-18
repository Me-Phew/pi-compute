cmake_minimum_required(VERSION 3.14)

project(PiCompute)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src/integral_calculator)

set(SOURCES src/integral_calculator/integral_calculator.cpp src/main.cpp)

add_executable(PiCompute ${SOURCES})

# Compile with all warnings, treat warnings as errors
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
