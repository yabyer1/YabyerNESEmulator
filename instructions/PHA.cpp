#include <cstdint>
#include "../CPU.h" 
void PHA(){ // push Accumulator onto Stack $48
        memory[sp--] = a; 
     cycles +=3;
}

