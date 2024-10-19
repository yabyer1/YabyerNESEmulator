#include <cstdint>
#include "../CPU.h" 
void CLC(){ //set carry to 0 $18
       p &= ~0x01;
       cycles +=2;
}