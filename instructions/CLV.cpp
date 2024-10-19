#include <cstdint>
#include "../CPU.h" 
void CLV(){ //set overflow to 0 $58
       p &= ~0x40;
       cycles +=2;
}