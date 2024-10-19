#include <cstdint>
#include "../CPU.h" 
void BNE(){ //if zero flag clear then add displacement..... $D0
        uint16_t old_pc = pc;
      int8_t operand = memory[pc++];
    if(!(p & 0x02)){
        pc += operand;
        cycles +=1;
         if ((pc & 0xFF00) != (old_pc & 0xFF00)) cycles += 1;  // Page crossing (when high bits dont match (upper 8 bits))
    }

    cycles +=2;
}