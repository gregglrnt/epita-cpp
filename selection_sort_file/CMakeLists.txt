cmake_minimum_required(VERSION 3.0)
project(selections_sort)

set(CMAKE_CXX_STANDARD 20)

add_executable(main my_sort.hpp main.cc sort_file.hpp)

# Compilation optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")