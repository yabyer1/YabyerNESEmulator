#include <cstdint>
#include "../CPU.h" 
void INY(){ // y =  y + 1 $C8
  y = y + 1;
  if(y == 0){
    p |= (0x02);
  }
  else{
    p &= (~0x02);
  }
  if(y & 0x80){
    p |= (0x80);
  }
  else{
    p &= ~(0x80);
  }
  cycles +=2;
}
