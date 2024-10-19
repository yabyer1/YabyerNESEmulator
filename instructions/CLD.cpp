#include <cstdint>
#include "../CPU.h" 
void CLD(){ //set decimal to 0 $D8
       p &= ~0x08;
       cycles +=2;
}