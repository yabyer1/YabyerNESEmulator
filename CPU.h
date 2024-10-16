#ifndef CPU_H
#define CPU_H

#include <cstdint>

// CPU Registers
extern uint8_t a;       // Accumulator
extern uint8_t x;       // X Index Register
extern uint8_t y;       // Y Index Register
extern uint8_t sreg;    // Status Register (NV-BDIZC)
extern uint8_t sp;      // Stack Pointer
extern uint16_t pc;     // Program Counter
extern uint8_t memory[65536];  // 64KB memory
extern int cycles;
extern uint8_t p;
// Function Declarations
void LDA_Immediate();    // Declare LDA functions
void LDA_ZeroPage();
void LDA_ZeroPageX();
void LDA_Absolute();
void LDA_AbsoluteX();
void LDA_AbsoluteY();
void LDA_IndirectX();
void LDA_IndirectY();

#endif  // CPU_H
