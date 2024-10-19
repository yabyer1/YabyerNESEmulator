#include <cstdint>
#include "../CPU.h"  
void BRK(){ // force interrupt, push PC and processor status on stack, then the IRQ vector @ $FFE/F loads into PC ((predefined in ROM)). Set break flag in status to 1 $00

  
     //store high byte of pc, low byte of pc (16 bit address) then store the processor status flags
       memory[sp--] = (pc>>8) & 0xFF;
       memory[sp--] = pc & 0xFF;
         p |= 0x10; //set break flag
       memory[sp--] = p;
    pc = memory[0xFFFE] | (memory[0xFFFF] << 8); // IRQ vector is loaded into pc, which is where the interrupt will start to be handled
    cycles +=7;
     
}