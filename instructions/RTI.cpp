#include <cstdint>
#include "../CPU.h" 

void RTI(uint8_t &m){ //pulls p from stack then the program counter
   sp++;
   p = memory[sp];
  // Pull the low and high bytes of the program counter from the stack
    uint8_t pcl = memory[++sp];
    uint8_t pch = memory[++sp];

    // Reconstruct the program counter from the pulled bytes
    pc = pcl | (pch << 8);
   cycles +=6;
}




