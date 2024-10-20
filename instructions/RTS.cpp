#include <cstdint>
#include "../CPU.h" 

void RTS(){ //pulls program counter $E9
   
  // Pull the low and high bytes of the program counter from the stack
    uint8_t pcl = memory[++sp];
    uint8_t pch = memory[++sp];

    // Reconstruct the program counter from the pulled bytes
    pc = pcl | (pch << 8);
    //increment by 1
    pc +=1;
   cycles +=6;
}




