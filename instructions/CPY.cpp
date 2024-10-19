#include <cstdint>
#include "../CPU.h" 
void CPY(uint8_t m){
    uint8_t result = y - m;
        if(x >= m){
            p |= (0x01);
        }
        else{
            p &= ~(0x01); 
        }
        if(x == m){
            p |= (0x02);
        }
        else{
            p &= ~(0x02);
        }
        if(result & 0x80){
            p |= 0x80;
        }
        else{
            p &= ~(0x80);
        }
}
void CPY_Immediate() {  // Opcode $C0
    uint8_t operand = memory[pc++];
    CPY(operand);
    cycles += 2;
}

void CPY_ZeroPage() {  // Opcode $C4
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    CPY(operand);
    cycles += 3;
}
void CPY_Absolute() {  // Opcode $CC
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
    CPY(operand);
    cycles += 4;
}