cmake_minimum_required(VERSION 3.27)
project(C___CA)

set(CMAKE_CXX_STANDARD 17)

add_executable(C___CA main.cpp
        Bug.h
        Bug.cpp
        Crawler.cpp
        Crawler.h
        Hopper.h
        Hopper.cpp
        Board.h
        Board.cpp)
