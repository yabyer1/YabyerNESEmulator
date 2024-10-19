#include <cstdint>
#include "../CPU.h" 
void PLA(){ // pull from stack onto accumulator $68
      a =   memory[sp++];
     if(a == 0){
        p |= (0x02);
     }
     else{
        p &= ~(0x02);
     }
     if(a & 0x80){
               p |= (0x80);
     }
     else{
             p &= ~(0x80);
     }
     cycles += 3;
}

