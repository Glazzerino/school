cmake_minimum_required(VERSION 3.17)
project(busc_ord)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(busc_ord
        src/main.cpp
        src/Timer.h)
