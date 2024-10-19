#include <cstdint>
#include "../CPU.h" 

void ROR(uint8_t &m){ // rotate a or m one place to the right, When rotating right we got to move the least significant bit into the new carry flag, and make carry flag the new high bit
     bool lsb = (m & 0x01);
    bool old_carry = p & 0x01; 
    m = (m >>1);
    if(old_carry){
        m |= 0x80;
    }
    if(lsb){ // set new carry flag
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
void ROR_Accumulator() {  // Opcode $6A
    ROR(a);
    cycles += 2;
}

void ROR_ZeroPage() {  // Opcode $66
    uint8_t address = memory[pc++];

    ROR(memory[address]);
    cycles += 5;
}

void ROR_ZeroPageX() {  // Opcode $76
    uint8_t address = (memory[pc++] + x) & 0xFF;
 
    ROR(memory[address]);
    cycles += 6;
}

void ROR_Absolute() {  // Opcode $6E
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
  
    ROR(memory[address]);
    cycles += 6;
}

void ROR_AbsoluteX() {  // Opcode $7E
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
  
    ROR(memory[address]);
    cycles += 7;

}



