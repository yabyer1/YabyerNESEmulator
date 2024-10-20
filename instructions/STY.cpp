#include <cstdint>
#include "../CPU.h" 
void STY(uint8_t &m){ // store y into memory m = y
    m = y;
     

}

void STY_ZeroPage() {  // Opcode $84
    uint8_t address = memory[pc++];
    uint8_t *operand = &memory[address];
    STY(*operand);
    cycles += 3;
}

void STY_ZeroPageX() {  // Opcode $94
    uint8_t address = (memory[pc++] + x) & 0xFF;
    uint8_t *operand = &memory[address];
    STY(*operand);
    cycles += 4;
}

void STY_Absolute() {  // Opcode $8C
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t *operand = &memory[address];
    STY(*operand);
    cycles += 4;
}
