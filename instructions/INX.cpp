#include <cstdint>
#include "../CPU.h" 
void INX(){ // x = x + 1 $E8
  x = x + 1;
  if(x == 0){
    p |= (0x02);
  }
  else{
    p &= (~0x02);
  }
  if(x & 0x80){
    p |= (0x80);
  }
  else{
    p &= ~(0x80);
  }
  cycles +=2;
}
