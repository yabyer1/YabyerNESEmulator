#include <cstdint>
#include "../CPU.h"  
void BCS(){ //opcode $B0
    int8_t offset = memory[pc++]; 
    uint16_t old_pc = pc;
 if((p & 0x01)) { // if we have a carry flag set, add the relative displacement to the program counter
        pc += offset;
        cycles +=1;
          if ((pc & 0xFF00) != (old_pc & 0xFF00)) cycles += 1;  // Page crossing
 }


   cycles +=2;
}
