#include <cstdint>
#include "../CPU.h" 
void SBC(uint8_t m){ // subtract memory location contents from a with not of the carry bit , it overflow, enable multi byte subtraction
uint8_t old_a = a;
      uint16_t result =   a - m - (1 - (p & 0x01));
      if(result <= 0xFF){ // checkc arry
        p |= 0x01;
      }
      else{
        p &= ~(0x01);
      }
       a = static_cast<uint8_t>(result & 0xFF);
       if(a == 0){
        p |= 0x02;
       }
       else{
            p &= ~(0x02);
       }
      
       if(a & 0x80){
        p |= 0x80;
       }
       else{
        p &= ~0x80;
       }
         // Set or clear the Overflow flag
    if (((old_a ^ m) & 0x80) && ((old_a ^ a) & 0x80)) { // check xor to see if old_a differs from m and a, this means that we have incrrect signage
        p |= 0x40;  // Set Overflow if the sign bit is incorrectly changed
    } else {
        p &= ~0x40;
    }

}
void SBC_Immediate() {  // Opcode $E9
    uint8_t operand = memory[pc++];
    SBC(operand);
    cycles += 2;
}

void SBC_ZeroPage() {  // Opcode $E5
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    SBC(operand);
    cycles += 3;
}

void SBC_ZeroPageX() {  // Opcode $F5
    uint8_t address = (memory[pc++] + x) & 0xFF;
    uint8_t operand = memory[address];
    SBC(operand);
    cycles += 4;
}

void SBC_Absolute() {  // Opcode $FD
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
    SBC(operand);
    cycles += 4;
}

void SBC_AbsoluteX() {  // Opcode $FD
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
    uint8_t operand = memory[address];
    SBC(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void SBC_AbsoluteY() {  // Opcode $F9
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    SBC(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void SBC_IndirectX() {  // Opcode $E1
    uint8_t zpa = (memory[pc++] + x) & 0xFF;
    uint16_t address = memory[zpa] | (memory[(zpa + 1) & 0xFF] << 8);
    uint8_t operand = memory[address];
    SBC(operand);
    cycles += 6;
}

void SBC_IndirectY() {  // Opcode $F1
    uint8_t zpa = memory[pc++];
    uint16_t base = memory[zpa] | (memory[(zpa + 1) & 0xFF] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    SBC(operand);
    cycles += 5;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}
