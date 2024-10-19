#include <cstdint>
#include "../CPU.h"  // Include the CPU header
void LDY(uint8_t m){// y = m
    y = m;
    if(y == 0){ //zero flag
        p |= (0x02);
    }
    else{
        p &= ~(0x02);
    }
    //negative flag
      if(y & 0x80){ 
        p |= (0x80);
    }
    else{
        p &= ~(0x80);
    }

}
void LDY_Immediate() {  // Opcode $A0
    uint8_t operand = memory[pc++];
    LDY(operand);
    cycles += 2;
}

void LDY_ZeroPage() {  // Opcode $A4
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    LDY(operand);
    cycles += 3;
}

void LDY_ZeroPageX() {  // Opcode $B4
    uint8_t address = (memory[pc++] + x) & 0xFF;

    LDY(memory[address]);
    cycles += 4;
}


void LDY_Absolute() {  // Opcode $AC
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
    LDY(operand);
    cycles += 4;
}



void LDY_AbsoluteX() {  // Opcode $BC
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
    uint8_t operand = memory[address];
    LDY(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

