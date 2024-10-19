#include <cstdint>
#include "../CPU.h" 
void JSR(uint16_t m){ // push return address minus one to stack, and set pc to m
    uint16_t return_address = pc - 1;
    memory[sp--] = (return_address >> 8) & 0xFF; //high bit
     sp &= 0xFF;  //handle wrap around
    memory[sp--] = (return_address) & 0xFF;
        sp &= 0xFF;

    pc = m;
}
void JSR_Absolute(){ //$20
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    JSR(address);
    cycles += 6;
}
