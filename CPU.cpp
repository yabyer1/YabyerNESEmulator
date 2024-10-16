//registers
#include <cstdint>
int8_t a; // accumulator
int8_t x; //index x
int8_t y; //index y
int16_t pc; // program counter
int8_t sp; //stack pointer
int8_t p; // used by Aly byte wide
uint8_t memory[65536];  // 64KB of memory (addresses 0x0000 - 0xFFFF)
int cycles; // will be used for the cock
/*
instructions





*/
//LDA
void LDAFlags(){
    if(a == 0){
        p |= 0x02; // set Zero Flag if a == 0
    }
    else {
        p &= ~0x02;
    }
    if(a & 0x80){
        p |= 0x80; // set Negative Flag if bit 7 of 'a' is set
    }
    else{
        p &= ~0x80;
    }
}

void LDA_Immediate(){ //Opcode $A9 Bytes 2 Cycle 2
    uint8_t val = memory[pc++]; //fetch immediate val
    a = val; //store in accumulator
    LDAFlags();
    cycles +=2;


}
void LDA_ZeroPage(){ // Opcode $A5, Bytes 2, Cycles 3
    uint8_t address = memory[pc++];  // Fetch the zero-page address
    a = memory[address];  // Load the value from the zero-page address
    LDAFlags();  
    cycles += 3;
}
void LDA_ZeroPageX(){ // Opcode $B5, 2 bytes, 4 cycles
    uint8_t address = (memory[pc++] + x)  & 0xFF; // add x to next address and wrap around if needed in the "zero page memory" 
    a = memory[address];
    LDAFlags();
    cycles += 4;
}
void LDA_Absolute(){ //Opcode $AD, bytes 3 cycles 4
    uint16_t final_address = memory[pc++] | (memory[pc++] << 8); // address is stored as the next 16 bits
   
    a = memory[final_address];
    LDAFlags();
    cycles += 4;
}
void LDA_X_Absolute(){ //Opcode $BD, bytes 3 cycles 4+
    uint16_t address = memory[pc++] | (memory[pc++] << 8); // address is stored as the next 16 bits
    uint16_t final_address (address + x); //add x with address to get final address
    a = memory[final_address];
    LDAFlags();
    cycles += 4;
    //if boundary is crossed we need to add 1 more to cycle
     if ((address & 0xFF00) != (final_address & 0xFF00)) {
        cycles += 1;  // Extra cycle for page boundary crossing
    }
}
void LDA_Y_Absolute(){ //Opcode $B9, bytes 3 cycles 4+
    uint16_t address = memory[pc++] | (memory[pc++] << 8); // address is stored as the next 16 bits
    uint16_t final_address (address + y); //add x with address to get final address
    a = memory[final_address];
    LDAFlags();
    cycles += 4;
    //if boundary is crossed we need to add 1 more to cycle
     if ((address & 0xFF00) != (final_address & 0xFF00)) {
        cycles += 1;  // Extra cycle for page boundary crossing
    }
}
void LDA_IndirectX(){//OpCode $A1, Bytes 2 Cycles 6
        uint8_t zpa = (memory[pc++] + x) &0xFF; // basically absolute addressing but with two iterations we must go to ana ddress of an address
        uint16_t address = memory[zpa] |  (memory[zpa + 1] <<8);
        a = memory[address];
        LDAFlags();
        cycles += 6;
}
void LDA_IndirectY(){//OpCode $B1, Bytes 2 Cycles 5+
        uint8_t zpa = (memory[pc++]) ; //start off with the zero page address
        uint16_t base_address = memory[zpa] |  (memory[zpa + 1] <<8); //the total 16 bit addres is low of current byte and high of the next byte 
        uint16_t address = y + base_address; //add to y per regulations
        a = memory[address];
        LDAFlags();
        cycles += 5;
        if((base_address & 0xFF00) != (address & 0xFF00)){ //boundary crossing check
            cycles +=1;
        }
}
//ADC
void ADCFlags( uint16_t temp, uint8_t operand){
    uint8_t result = a;
    if(result == 0){
        p |= 0x02; // set Zero Flag if a == 0
    }
    else {
        p &= ~0x02;
    }

    if(result & 0x80){
        p |= 0x80; // set Negative Flag if bit 7 of 'a' is set
    }
    else{
        p &= ~0x80;
    }
    if(temp >  0xFF){ //check for a carry
        p |= 0x01; //set carry flag
    }else{
        p &= ~0x01;
    }
    //check signed overflow
    //check if the sign of result is wrong
    if(((a ^ operand) & 0x80) == 0 && ( (a ^ result) & 0x80 != 0)){
        p |= 0x40; //set overflow flag
    }
    else{
        p &= ~0x40;
    }
}
void ADC_Immediate(){ //OpCode %69, 2 Bytes, 2 Cycles
        uint8_t operand = memory[pc++];
        uint16_t temp = a + operand + (p & 0x01); //A,Z, C, N = A + M + C
        a = temp & 0xFF; //store 8 bits in a
        ADCFlags(temp, operand);
        cycles +=2;
}