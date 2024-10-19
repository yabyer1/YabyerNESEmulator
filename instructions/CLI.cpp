#include <cstdint>
#include "../CPU.h" 
void CLI(){ //set interrupt to 0 $58
       p &= ~0x04;
       cycles +=2;
}