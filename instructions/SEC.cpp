#include <cstdint>
#include "../CPU.h" 

void SEC(){ //set carry to 1 $38
   
 p |= 0x01;
 cycles +=2;
}




