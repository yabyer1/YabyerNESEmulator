#include <cstdint>
#include "../CPU.h"  // Include the CPU header
void LSR(uint8_t &m, int mode){// A = A/2, or M = M/2
    p &= ~0x01;
   if(mode == 0) { // accumulator mode
      if(a & 0x01){ //set carry to old bit 0
        p |= (0x01);
      }
        a = a >>1;
        if(a == 0){
            p |= (0x02);
        }
        else{
            p &= ~(0x02);
        }
        if(a & 0x80){
             p |= (0x80);
        }
        else{
              p &= ~(0x80);
        }

   }
   else{ //memory mode
        if(m & 0x01){
        p |= (0x01);
      }
        m = m >> 1;
        if(m == 0){
            p |= (0x02);
        }
        else{
            p &= ~(0x02);
        }
        if(m & 0x80){
             p |= (0x80);
        }
        else{
              p &= ~(0x80);
        }
   }

}
void LSR_Accumulator() {  // Opcode $4A
   LSR(a, 0);
    cycles += 2;
}

void LSR_ZeroPage() {  // Opcode $46
    uint8_t address = memory[pc++];
   
    LSR(memory[address], 1);
    cycles += 5;
}

void LSR_ZeroPageX() {  // Opcode $56
    uint8_t address = (memory[pc++] + x) & 0xFF;

    LSR(memory[address], 1);
    cycles += 6;
}


void LSR_Absolute() {  // Opcode $4E
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
 
    LSR(memory[address], 1);
    cycles += 6;
}



void LSR_AbsoluteX() {  // Opcode $5E
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
  
    LSR(memory[address], 1);
    cycles += 7;
}

