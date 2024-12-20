#pragma once
#include <cstdint>
#include <array>

#include "CPU.h"

class Bus
{
public:
	Bus();
	~Bus();

public: // Devices on bus

	// Fake RAM for this part of the series
	std::array<uint8_t, 64 * 1024> ram;


public: // Bus Read & Write
	void write(uint16_t addr, uint8_t data);
	uint8_t read(uint16_t addr, bool bReadOnly = false);
};
