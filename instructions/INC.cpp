
#include <cstdint>
#include "../CPU.h" 
void INC(uint8_t &m){ // m = m+ 1
    m = m+ 1;
    if(m == 0){
        p |= (0x02);
    }
    else{
        p &= ~(0x02);
    }
    if(m & 0x80){
        p |= (0x80);
    }
    else{
        p &= ~(0x80);
    }
}
void INC_ZeroPage() {  // Opcode $E6
    uint8_t address = memory[pc++];
   
    INC(memory[address]); // directly increment in memory
    cycles += 5;
}

void INC_ZeroPageX() {  // Opcode $F6
    uint8_t address = (memory[pc++] + x) & 0xFF;

    INC(memory[address]);
    cycles += 6;
}

void INC_Absolute() {  // Opcode $EE
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
 
    INC(memory[address]);
    cycles += 6;
}

void INC_AbsoluteX() {  // Opcode $FE
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
 
    INC(memory[address]);
    cycles += 7;
}