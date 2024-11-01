#include <cstdint>
#include "../CPU.h" 
void CPX(uint8_t m){
    uint8_t result = x - m;
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
void CPX_Immediate() {  // Opcode $E9
    uint8_t operand = memory[pc++];
    CPX(operand);
    cycles += 2;
}

void CPX_ZeroPage() {  // Opcode $E4
    uint8_t address = memory[pc++];
    uint8_t operand = memory[address];
    CPX(operand);
    cycles += 3;
}
void CPX_Absolute() {  // Opcode $EC
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    uint8_t operand = memory[address];
    CPX(operand);
    cycles += 4;
}