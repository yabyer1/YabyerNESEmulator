#include <cstdint>
#include "../CPU.h" 
void BPL(){ //if negative flag clear then add displacement..... $10
        uint16_t old_pc = pc;
      int8_t offset = memory[pc++];
    if(!(p & 0x80)){
        pc += offset;
        cycles +=1;
         if ((pc & 0xFF00) != (old_pc & 0xFF00)) cycles += 1;  // Page crossing (when high bits dont match (upper 8 bits))
    }

    cycles +=2;
}