#include <cstdint>
#include "../CPU.h"  
void BIT(uint8_t operand){ // This instructions is used to test if one or more bits are set in a target memory location. The mask pattern in A is ANDed with the value in memory to set or clear the zero flag, but the result is not kept. Bits 7 and 6 of the value from memory are copied into the N and V flags.
    uint8_t mask = (a & operand);
    
    if(mask & 0){
     p  |= 0x02; //set  zero if and
    }
    else{
            p &= ~0x02;
    }
    bit q = 
     (p | ( << 6) ) // set 6th bit
}
void BITZeroPage(){ //opcode $24
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    BIT(operand);
    cycles +=3;
}
void BITAbsolute(){ //opcode $24
     uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
     BIT(operand);
    cycles += 4;
}