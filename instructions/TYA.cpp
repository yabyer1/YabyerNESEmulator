#include <cstdint>
#include "../CPU.h" 
void TYA(){ // 98  a = y
        a = y;
        if(a == 0){
            p |= 0x02;
        }
        else{
            p &= ~(0x02);
        }
        if(a & 0x80){
            p |=(0x80);
        }
        else{
            p &= ~(0x80);
        }
        cycles +=2;
}