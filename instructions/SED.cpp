#include <cstdint>
#include "../CPU.h" 

void SED(){ //set decimal to 1 $38
   
 p |= 0x08;
 cycles +=2;
}




