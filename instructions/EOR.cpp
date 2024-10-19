#include <cstdint>
#include "../CPU.h" 
void EOR(uint8_t m){ // a =  a ^m
        a ^= m;
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
void EOR_Immediate() {  // Opcode $49
    uint8_t operand = memory[pc++];
    EOR(operand);
    cycles += 2;
}

void EOR_ZeroPage() {  // Opcode $45
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    EOR(operand);
    cycles += 3;
}

void EOR_ZeroPageX() {  // Opcode $55
    uint8_t address = (memory[pc++] + x) & 0xFF;
    uint8_t operand = memory[address];
    EOR(operand);
    cycles += 4;
}

void EOR_Absolute() {  // Opcode $4D
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
    EOR(operand);
    cycles += 4;
}

void EOR_AbsoluteX() {  // Opcode $5D
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
    uint8_t operand = memory[address];
    EOR(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void EOR_AbsoluteY() {  // Opcode $59
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    EOR(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void EOR_IndirectX() {  // Opcode $41
    uint8_t zpa = (memory[pc++] + x) & 0xFF;
    uint16_t address = memory[zpa] | (memory[zpa + 1] << 8);
    uint8_t operand = memory[address];
    EOR(operand);
    cycles += 6;
}

void EOR_IndirectY() {  // Opcode $51
    uint8_t zpa = memory[pc++];
    uint16_t base = memory[zpa] | (memory[zpa + 1] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    EOR(operand);
    cycles += 5;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}
