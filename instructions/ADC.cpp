#include <cstdint>
#include "../CPU.h"  // Correct path to the cpu.h header file

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