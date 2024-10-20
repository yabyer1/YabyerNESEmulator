#include <cstdint>
#include "../CPU.h" 
void TXA(){ // $8A a = x
   a  = x;
     if(x == 0){
            p |= 0x02;
        }
        else{
            p &= ~(0x02);
        }
        if(x & 0x80){
            p |=(0x80);
        }
        else{
            p &= ~(0x80);
        }
        cycles = cycles = 2;
}