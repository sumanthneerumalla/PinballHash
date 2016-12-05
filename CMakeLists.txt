cmake_minimum_required(VERSION 3.6)
project(PinballHash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES driver.cpp Pinball.h
        Pinball.cpp)
add_executable(PinballHash ${SOURCE_FILES})