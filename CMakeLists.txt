cmake_minimum_required(VERSION 3.10)
project(NES_Emulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(emulator
    CPU.cpp
    instructions/TAY.cpp
    instructions/LDA.cpp
    instructions/LDX.cpp
    instructions/LDY.cpp
    instructions/ADC.cpp
    instructions/AND.cpp
    instructions/ASL.cpp
    instructions/BCC.cpp
    instructions/BMI.cpp
    instructions/BCS.cpp
    instructions/BEQ.cpp
    instructions/BIT.cpp
    instructions/BNE.cpp
    instructions/BPL.cpp
    instructions/BRK.cpp
    instructions/BVC.cpp
    instructions/BVS.cpp
    instructions/CLC.cpp
    instructions/CLD.cpp
    instructions/CLI.cpp
    instructions/CLV.cpp
    instructions/CMP.cpp
    instructions/CPX.cpp
    instructions/CPY.cpp
    instructions/DEC.cpp
    instructions/DEX.cpp
    instructions/DEY.cpp
    instructions/EOR.cpp
    instructions/INC.cpp
    instructions/INX.cpp
    instructions/INY.cpp
    instructions/JMP.cpp
    instructions/JSR.cpp
    instructions/LSR.cpp
    instructions/NOP.cpp
    instructions/ORA.cpp
    instructions/PHA.cpp
    instructions/PHP.cpp
    instructions/PLA.cpp
    instructions/PLP.cpp
    instructions/ROL.cpp
    instructions/ROR.cpp
    instructions/RTI.cpp
    instructions/RTS.cpp
    instructions/SBC.cpp
    instructions/SEC.cpp  # Keep only one instance of SEC.cpp
    instructions/SED.cpp
    instructions/STA.cpp
    instructions/STX.cpp
    instructions/STY.cpp
    instructions/TXA.cpp
    instructions/TXS.cpp
    instructions/TYA.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/instructions)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
