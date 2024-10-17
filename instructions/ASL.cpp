#include <cstdint>
#include "../CPU.h"  
uint8_t ASL(uint8_t value){
 if(value & 0x80) p |= 0x01; // set carry if 7th bit of original input is true
 else p &= ~0x01;
value = value << 1;
       if(value == 0){
        p |= 0x02; // set Zero Flag if vlaue = 0
    }
    else {
        p &= ~0x02;
    }

    if(value & 0x80){
        p |= 0x80; // set Negative Flag if bit 7 of value is set
    }
    else{
        p &= ~0x80;
    }
   return value;
}
void ASL_Accumulator(){ //$0A
       
   a =  ASL(a);
    cycles += 2;
}
void ASL_ZeroPage(){ //$06
         uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    memory[address] = ASL(operand);
    cycles += 5;
}
void ASL_ZeroPageX() {  // Opcode $16
    uint8_t address = (memory[pc++] + x) & 0xFF;
    uint8_t operand = memory[address];
   memory[address] = ASL(operand);
    cycles += 6;
}
void ASL_Absolute() {  // Opcode $0E
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
   memory[address] =  ASL(operand);
    cycles += 6;
}
void ASL_AbsoluteX() {  // Opcode $1E
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
    uint8_t operand = memory[address];
   memory[address] = ASL(operand);
    cycles += 7;
}