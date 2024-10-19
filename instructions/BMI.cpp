#include <cstdint>
#include "../CPU.h" 
void BMI(){ // if negative flag is set add relative displacement to the PC to cause a branch to new location $30
     uint16_t old_pc = pc;
      int8_t operand = memory[pc++];
    if(p & 0x80){
        pc += operand;
        cycles +=1;
         if ((pc & 0xFF00) != (old_pc & 0xFF00)) cycles += 1;  // Page crossing (when high bits dont match (upper 8 bits))
    }

    cycles +=2;
}