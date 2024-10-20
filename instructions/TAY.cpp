#include <cstdint>
#include "../CPU.h" 
void TAY(uint8_t &m){ // y = a $A8
    y = a;
     cycles +=2;

}