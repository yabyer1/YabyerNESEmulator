#include <cstdint>
#include <array>
#include "CPU.h"
class Bus{
    public:
    Bus();
    ~Bus();
    public:
        std::array<uint8_t, 64* 1024> ram; // simulated ram for input instructions
    public:
        void write(uint16_t addr, uint8_t data);
        void read(uint16_t addr, bool readonly);
};