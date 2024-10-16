//registers
#include <cstdint>
#include <iostream>
uint8_t a = 0; // accumulator
uint8_t x = 0; //index x
uint8_t y = 0; //index y
uint16_t pc = 0; // program counter
uint8_t sp = 0; //stack pointer
uint8_t p = 0; // used by Aly byte wide
uint8_t memory[65536] = {0};  // 64KB of memory (addresses 0x0000 - 0xFFFF)
int cycles = 0; // will be used for the cock

int main() {
    std::cout << "Starting NES Emulator..." << std::endl;

   
    return 0;
}