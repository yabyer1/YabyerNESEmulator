#include <cstdint>
#include "../CPU.h"  

//ADC
void ADC(uint8_t operand){
     uint16_t temp = operand + a + (p & 0x01); // Add with carry
    a = temp & 0xFF; // store lower 8
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
    if(temp >  0xFF){ //check for a carry
        p |= 0x01; //set carry flag
    }else{
        p &= ~0x01;
    }
    //check signed overflow
    //check if the sign of result is wrong
    if(((a ^ operand) & 0x80) == 0 && ( (a ^ (temp & 0xFF)) & 0x80) != 0){
        p |= 0x40; //set overflow flag
    }
    else{
        p &= ~0x40;
    }
}
void ADC_Immediate() {  // Opcode $69
    uint8_t operand = memory[pc++];
    ADC(operand);
    cycles += 2;
}

void ADC_ZeroPage() {  // Opcode $65
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    ADC(operand);
    cycles += 3;
}

void ADC_ZeroPageX() {  // Opcode $75
    uint8_t address = (memory[pc++] + x) & 0xFF;
    uint8_t operand = memory[address];
    ADC(operand);
    cycles += 4;
}

void ADC_Absolute() {  // Opcode $6D
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
    ADC(operand);
    cycles += 4;
}

void ADC_AbsoluteX() {  // Opcode $7D
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
    uint8_t operand = memory[address];
    ADC(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void ADC_AbsoluteY() {  // Opcode $79
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    ADC(operand);
    cycles += 4;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}

void ADC_IndirectX() {  // Opcode $61
    uint8_t zpa = (memory[pc++] + x) & 0xFF;
    uint16_t address = memory[zpa] | (memory[zpa + 1] << 8);
    uint8_t operand = memory[address];
    ADC(operand);
    cycles += 6;
}

void ADC_IndirectY() {  // Opcode $71
    uint8_t zpa = memory[pc++];
    uint16_t base = memory[zpa] | (memory[zpa + 1] << 8);
    uint16_t address = base + y;
    uint8_t operand = memory[address];
    ADC(operand);
    cycles += 5;
    if ((base & 0xFF00) != (address & 0xFF00)) cycles += 1;  // Page crossing
}
