#include <cstdint>
#include "../CPU.h" 
void STX(uint8_t &m){ // store x into memory m = x
    m = x;
     

}

void STX_ZeroPage() {  // Opcode $86
    uint8_t address = memory[pc++];
    uint8_t *operand = &memory[address];
    STX(*operand);
    cycles += 3;
}

void STX_ZeroPageY() {  // Opcode $96
    uint8_t address = (memory[pc++] + y) & 0xFF;
    uint8_t *operand = &memory[address];
    STX(*operand);
    cycles += 4;
}

void STX_Absolute() {  // Opcode $8E
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t *operand = &memory[address];
    STX(*operand);
    cycles += 4;
}
