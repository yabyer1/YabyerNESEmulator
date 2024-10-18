cmake_minimum_required(VERSION 3.10)
project(NES_Emulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(emulator
    CPU.cpp
    instructions/LDA.cpp
    instructions/ADC.cpp
    instructions/AND.cpp
    instructions/ASL.cpp
    instructions/BCC.cpp
    instructions/BCS.cpp
    instructions/BEQ.cpp
    instructions/BIT.cpp
)
