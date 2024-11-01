#include <cstdint>
#include "../CPU.h" 
void TAY(){ // y = a $A8
    y = a;
     cycles +=2;

}