cmake_minimum_required(VERSION 3.6)
project(lab02)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        FBlab.cpp
        mlisp.h)

add_executable(lab02 ${SOURCE_FILES})