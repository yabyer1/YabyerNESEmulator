cmake_minimum_required(VERSION 3.10)
project(NES_Emulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(emulator
    cpu.cpp
    instructions/LDA.cpp
    instructions/ADC.cpp
)
