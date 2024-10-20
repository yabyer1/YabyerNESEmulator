#include <cstdint>
#include "../CPU.h" 
void TAX(uint8_t &m){ // x = a ; $AA
    x = a;
     cycles +=2;

}