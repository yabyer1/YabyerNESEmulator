#include <cstdint>
#include "../CPU.h" 

void ROL(uint8_t &m){ // Rotate a or m one place to the left, basically we want to move the old carry bit into the new least signficant bit, and then we got to get the high bit as the new carry
     bool old = (p & 0x01); // original carry flag
     bool n = (m & 0x80); // new carry ( 7th bit)  rotates left and this will become a carry flag
    m = (m <<1) | old; // old carry becomes last bit now (bit 0)
    if(n){ // set new carry flag
        p  |= 0x01;
    }
    else{
        p &= ~(0x01);
    }
    if(m == 0){ //zero flag
        p |= 0x02;
    }
    else{
        p &= ~(0x02);
    }
    if(m & 0x80){ // negative flag
        p |= 0x80;
    }
    else{
        p &= ~0x80;
    }

}
void ROL_Accumulator() {  // Opcode $2A
    ROL(a);
    cycles += 2;
}

void ROL_ZeroPage() {  // Opcode $26
    uint8_t address = memory[pc++];

    ROL(memory[address]);
    cycles += 5;
}

void ROL_ZeroPageX() {  // Opcode $36
    uint8_t address = (memory[pc++] + x) & 0xFF;
 
    ROL(memory[address]);
    cycles += 6;
}

void ROL_Absolute() {  // Opcode $2E
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
  
    ROL(memory[address]);
    cycles += 6;
}

void ROL_AbsoluteX() {  // Opcode $3E
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
  
    ROL(memory[address]);
    cycles += 7;

}



