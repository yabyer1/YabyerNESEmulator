#include <cstdint>
#include "../CPU.h"  // Include the CPU header
void NOP(){// NO CHANGE  JUST MOVE PC $EA
pc++;
cycles+=2;

}