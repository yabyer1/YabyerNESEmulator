#include <cstdint>
#include "../CPU.h" 
void TXS(){ // $8A copy x to sp
        sp = x;
        cycles +=2;
}