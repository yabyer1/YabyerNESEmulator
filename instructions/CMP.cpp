#include <cstdint>
#include "../CPU.h" 
void CMP(uint8_t m){ // compare accumulator with memory heald value and set flags based off that
    uint8_t result = a - m;
    if(a >= m){ // set carry flag
          p  |= 0x01; 
    }
    else{
        p &= ~(0x01);
    }
    if(a == m){// set zero flag
             p  |= 0x02;
    }
    else{
         p &= ~(0x02);
    }
    //set  negative flag if bit 7 of result is set
    if(result & 0x80){
            p |= 0x80;
    }
    else{
           p &= ~(0x80);
    }
}
void CMP_Immediate() {  // Opcode $C9
    uint8_t operand = memory[pc++];
    CMP(operand);
    cycles += 2;
}

void CMP_ZeroPage() {  // Opcode $C5
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    CMP(operand);
    cycles += 3;
}

void CMP_ZeroPageX() {  // Opcode $D5
    uint8_t address = (memory[pc++] + x) & 0xFF;
    uint8_t operand = memory[address];
    CMP(operand);
    cycles += 4;
}

void CMP_Absolute() {  // Opcode $CD
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
    CMP(operand);
    cycles += 4;
}

void CMP_AbsoluteX() {  // Opcode $DD
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
    uint8_t operand = memory[address];
    CMP(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void CMP_AbsoluteY() {  // Opcode $D9
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    CMP(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void CMP_IndirectX() {  // Opcode $C1
    uint8_t zpa = (memory[pc++] + x) & 0xFF;
    uint16_t address = memory[zpa] | (memory[zpa + 1] << 8);
    uint8_t operand = memory[address];
    CMP(operand);
    cycles += 6;
}

void CMP_IndirectY() {  // Opcode $D1
    uint8_t zpa = memory[pc++];
    uint16_t base = memory[zpa] | (memory[zpa + 1] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    CMP(operand);
    cycles += 5;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}
