cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Memory.cpp
        MainUi.cpp
        Register.cpp
        CPU.cpp
        Machine.cpp
        ALU.cpp
        ControlUnit.cpp
)
