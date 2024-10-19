#include <cstdint>
#include "../CPU.h" 
void JMP(uint16_t m){ // pc = m 
    pc = m;
}
void JMP_Absolute(){ //$4c
    uint16_t address = memory[pc++] | (memory[pc++] << 8);
    JMP(address);
    cycles += 3;
}
void JMP_Indirect(){ //6c
    uint16_t operand = memory[pc++] | (memory[pc++] << 8);
    uint16_t address;
    if((address & 0x00FF) == 0x00FF){
        address = memory[operand] |= (memory[operand & 0xFF00] <<8); //if on last page, jump to 0 page (wrap around)
    }
    else{
        address = memory[operand ] |= (memory[operand + 1] << 8); 
    }
    JMP(address);
    cycles += 5;
}