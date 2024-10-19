#include <cstdint>
#include "../CPU.h"  // Include the CPU header
void LDX(uint8_t m){// x = m
    x = m;
    if(x == 0){ //zero flag
        p |= (0x02);
    }
    else{
        p &= ~(0x02);
    }
    //negative flag
      if(x & 0x80){ 
        p |= (0x80);
    }
    else{
        p &= ~(0x80);
    }

}
void LDX_Immediate() {  // Opcode $A2
    uint8_t operand = memory[pc++];
    LDX(operand);
    cycles += 2;
}

void LDX_ZeroPage() {  // Opcode $A6
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    LDX(operand);
    cycles += 3;
}

void LDX_ZeroPageY() {  // Opcode $B6
    uint8_t address = (memory[pc++] + y) & 0xFF;

    LDX(memory[address]);
    cycles += 4;
}


void LDX_Absolute() {  // Opcode $AE
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
    LDX(operand);
    cycles += 4;
}



void LDX_AbsoluteY() {  // Opcode $BE
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    LDX(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

