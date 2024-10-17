#include <cstdint>
#include "../CPU.h"  
void AND(uint8_t operand){ // A, Z, N = A &M
 a = a & operand;
  if(a == 0){
        p |= 0x02; // set Zero Flag if a == 0
    }
    else {
        p &= ~0x02;
    }
      if(a & 0x80){
        p |= 0x80; // set Negative Flag if bit 7 of 'a' is set
    }
    else{
        p &= ~0x80;
    }
}
void AND_Immediate(){ // $29
    uint8_t operand = memory[pc++];
    AND(operand);
    cycles +=2;
}
void AND_ZeroPage() {  // Opcode $25
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    AND(operand);
    cycles += 3;
}

void AND_ZeroPageX() {  // Opcode $35
    uint8_t address = (memory[pc++] + x) & 0xFF;
    uint8_t operand = memory[address];
    AND(operand);
    cycles += 4;
}

void AND_Absolute() {  // Opcode $2D
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
    AND(operand);
    cycles += 4;
}

void AND_AbsoluteX() {  // Opcode $3D
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
    uint8_t operand = memory[address];
    AND(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void AND_AbsoluteY() {  // Opcode $39
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    AND(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void AND_IndirectX() {  // Opcode $21
    uint8_t zpa = (memory[pc++] + x) & 0xFF;
    uint16_t address = memory[zpa] | (memory[zpa + 1] << 8);
    uint8_t operand = memory[address];
    AND(operand);
    cycles += 6;
}

void AND_IndirectY() {  // Opcode $31
    uint8_t zpa = memory[pc++];
    uint16_t base = memory[zpa] | (memory[zpa + 1] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    AND(operand);
    cycles += 5;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}
