#include <cstdint>
#include "../CPU.h" 
void PLP(){ // pull from stack onto P $68
    sp++;
      p =   memory[sp];
   
     cycles += 4;
}

