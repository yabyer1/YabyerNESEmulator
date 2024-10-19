#include <cstdint>
#include "../CPU.h" 
void ORA(uint8_t m){ // a =  a |m
        a |= m;
        if(a == 0){
            p |= 0x02;
        }
        else{
            p &= ~(0x02);
        }
        if(a & 0x80){
            p |=(0x80);
        }
        else{
            p &= ~(0x80);
        }
}
void ORA_Immediate() {  // Opcode $09
    uint8_t operand = memory[pc++];
    ORA(operand);
    cycles += 2;
}

void ORA_ZeroPage() {  // Opcode $05
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    ORA(operand);
    cycles += 3;
}

void ORA_ZeroPageX() {  // Opcode $15
    uint8_t address = (memory[pc++] + x) & 0xFF;
    uint8_t operand = memory[address];
    ORA(operand);
    cycles += 4;
}

void ORA_Absolute() {  // Opcode $0D
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
    ORA(operand);
    cycles += 4;
}

void ORA_AbsoluteX() {  // Opcode $1D
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
    uint8_t operand = memory[address];
    ORA(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void ORA_AbsoluteY() {  // Opcode $19
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    ORA(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void ORA_IndirectX() {  // Opcode $01
    uint8_t zpa = (memory[pc++] + x) & 0xFF;
    uint16_t address = memory[zpa] | (memory[(zpa + 1) & 0xFF] << 8);
    uint8_t operand = memory[address];
    ORA(operand);
    cycles += 6;
}

void ORA_IndirectY() {  // Opcode $11
    uint8_t zpa = memory[pc++];
    uint16_t base = memory[zpa] | (memory[(zpa + 1) & 0xFF] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    ORA(operand);
    cycles += 5;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}
