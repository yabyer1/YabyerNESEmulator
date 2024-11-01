#include <cstdint>
#include "../CPU.h" 
void DEC(uint8_t &m){ // M = M- 1
    m--;
   
    if(m == 0){// set zero flag
             p  |= 0x02;
    }
    else{
         p &= ~(0x02);
    }
    //set  negative flag if bit 7 of result is set
    if(m & 0x80){
            p |= 0x80;
    }
    else{
           p &= ~(0x80);
    }
}

void DEC_ZeroPage() {  // Opcode $C6
    uint8_t address = memory[pc++];
      DEC(memory[address]);
   
    cycles += 5;
}

void DEC_ZeroPageX() {  // Opcode $D6
    uint8_t address = (memory[pc++] + x) & 0xFF;
      DEC(memory[address]);

    cycles += 6;
}

void DEC_Absolute() {  // Opcode $CE
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
 
    DEC(memory[address]);
    cycles += 6;
}

void DEC_AbsoluteX() {  // Opcode $DE
    uint16_t base = memory[pc++] | (memory[pc++] << 8);
    uint16_t address = base + x;
    DEC(memory[address]);
    cycles += 7;

}

