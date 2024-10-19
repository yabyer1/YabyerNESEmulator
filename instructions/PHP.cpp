#include <cstdint>
#include "../CPU.h" 
void PHP(){ // push P onto Stack $08
        memory[sp--] = p; 
        cycles +=3;
     
}

