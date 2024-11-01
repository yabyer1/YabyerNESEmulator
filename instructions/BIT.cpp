#include <cstdint>
#include "../CPU.h"  
void BIT(uint8_t operand){ // This instructions is used to test if one or more bits are set in a target memory location. The mask pattern in A is ANDed with the value in memory to set or clear the zero flag, but the result is not kept. Bits 7 and 6 of the value from memory are copied into the N and V flags.
    uint8_t mask = (a & operand);
    
    if(mask == 0){
     p  |= 0x02; //set  zero flag
    }
    else{
            p &= ~0x02;
    }
   // set the negative flag to 7th bit of operand
   if(operand & 0x80){
    p |= 0x80;
   }
   else{
        p &= ~0x80;
   }
   // set  overflow flag to the 6th bit of memory
   if(operand & 0x40){
        p |= 0x40;
   }
   else{
    p &= ~0x40;
   }
}
void BIT_ZeroPage(){ //opcode $24
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    BIT(operand);
    cycles +=3;
}
void BIT_Absolute(){ //opcode $2C
     uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
     BIT(operand);
    cycles += 4;
}