#include <cstdint>
#include "../CPU.h" 
void STA(uint8_t &m){ // store accumulator into memory m = a
    m = a;
     

}

void STA_ZeroPage() {  // Opcode $85
    uint8_t address = memory[pc++];
    uint8_t *operand = &memory[address];
    STA(*operand);
    cycles += 3;
}

void STA_ZeroPageX() {  // Opcode $95
    uint8_t address = (memory[pc++] + x) & 0xFF;
    uint8_t *operand = &memory[address];
    STA(*operand);
    cycles += 4;
}

void STA_Absolute() {  // Opcode $8D
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t *operand = &memory[address];
    STA(*operand);
    cycles += 4;
}

void STA_AbsoluteX() {  // Opcode $9D
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
    uint8_t *operand = &memory[address];
    STA(*operand);
    cycles += 5;
    
}

void STA_AbsoluteY() {  // Opcode $99
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + y;
    uint8_t *operand = &memory[address];
    STA(*operand);
    cycles += 5;
 
}

void STA_IndirectX() {  // Opcode $81
    uint8_t zpa = (memory[pc++] + x) & 0xFF;
    uint16_t address = memory[zpa] | (memory[(zpa + 1) & 0xFF] << 8);
    uint8_t *operand = &memory[address];
    STA(*operand);
    cycles += 6;
}

void STA_IndirectY() {  // Opcode $91
    uint8_t zpa = memory[pc++];
    uint16_t base = memory[zpa] | (memory[(zpa + 1) & 0xFF] << 8);
    uint16_t address = base + y;
    uint8_t *operand = &memory[address];
    STA(*operand);
    cycles +=6;
}
