cmake_minimum_required(VERSION 3.20)
project(TheFirstTask)

set(CMAKE_CXX_STANDARD 17)

add_executable(TheFirstTask main.cpp transport.cpp transport.h airplane.cpp airplane.h train.cpp train.h ship.cpp ship.h container.cpp container.h)
