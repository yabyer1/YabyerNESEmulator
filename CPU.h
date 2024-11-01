#ifndef CPU_H
#define CPU_H

#include <cstdint>

// CPU Registers
extern uint8_t a;        // Accumulator
extern uint8_t x;        // X Index Register
extern uint8_t y;        // Y Index Register
extern uint8_t sreg;     // Status Register (NV-BDIZC)
extern uint8_t sp;       // Stack Pointer
extern uint16_t pc;      // Program Counter
extern uint8_t memory[65536];  // 64KB memory
extern int cycles;
extern uint8_t p;        // Status Flags
struct Instruction{
    void(*work)(); // will call the function that accounts for addressing mode which then will find the address and then call the fucntion operation
};

extern Instruction lookup[256];
// LDA - Load Accumulator
void LDA_Immediate();
void LDA_ZeroPage();
void LDA_ZeroPageX();
void LDA_Absolute();
void LDA_AbsoluteX();
void LDA_AbsoluteY();
void LDA_IndirectX();
void LDA_IndirectY();

// LDX - Load X Register
void LDX_Immediate();
void LDX_ZeroPage();
void LDX_ZeroPageY();
void LDX_Absolute();
void LDX_AbsoluteY();

// LDY - Load Y Register
void LDY_Immediate();
void LDY_ZeroPage();
void LDY_ZeroPageX();
void LDY_Absolute();
void LDY_AbsoluteX();

// STA - Store Accumulator
void STA_ZeroPage();
void STA_ZeroPageX();
void STA_Absolute();
void STA_AbsoluteX();
void STA_AbsoluteY();
void STA_IndirectX();
void STA_IndirectY();

// STX - Store X Register
void STX_ZeroPage();
void STX_ZeroPageY();
void STX_Absolute();

// STY - Store Y Register
void STY_ZeroPage();
void STY_ZeroPageX();
void STY_Absolute();

// ADC - Add with Carry
void ADC_Immediate();
void ADC_ZeroPage();
void ADC_ZeroPageX();
void ADC_Absolute();
void ADC_AbsoluteX();
void ADC_AbsoluteY();
void ADC_IndirectX();
void ADC_IndirectY();

// SBC - Subtract with Borrow
void SBC_Immediate();
void SBC_ZeroPage();
void SBC_ZeroPageX();
void SBC_Absolute();
void SBC_AbsoluteX();
void SBC_AbsoluteY();
void SBC_IndirectX();
void SBC_IndirectY();

// AND - Logical AND
void AND_Immediate();
void AND_ZeroPage();
void AND_ZeroPageX();
void AND_Absolute();
void AND_AbsoluteX();
void AND_AbsoluteY();
void AND_IndirectX();
void AND_IndirectY();

// ORA - Logical OR
void ORA_Immediate();
void ORA_ZeroPage();
void ORA_ZeroPageX();
void ORA_Absolute();
void ORA_AbsoluteX();
void ORA_AbsoluteY();
void ORA_IndirectX();
void ORA_IndirectY();

// EOR - Exclusive OR
void EOR_Immediate();
void EOR_ZeroPage();
void EOR_ZeroPageX();
void EOR_Absolute();
void EOR_AbsoluteX();
void EOR_AbsoluteY();
void EOR_IndirectX();
void EOR_IndirectY();

// CMP - Compare Accumulator
void CMP_Immediate();
void CMP_ZeroPage();
void CMP_ZeroPageX();
void CMP_Absolute();
void CMP_AbsoluteX();
void CMP_AbsoluteY();
void CMP_IndirectX();
void CMP_IndirectY();

// CPX - Compare X Register
void CPX_Immediate();
void CPX_ZeroPage();
void CPX_Absolute();

// CPY - Compare Y Register
void CPY_Immediate();
void CPY_ZeroPage();
void CPY_Absolute();

// BIT - Bit Test
void BIT_ZeroPage();
void BIT_Absolute();

// INC - Increment Memory
void INC_ZeroPage();
void INC_ZeroPageX();
void INC_Absolute();
void INC_AbsoluteX();

// DEC - Decrement Memory
void DEC_ZeroPage();
void DEC_ZeroPageX();
void DEC_Absolute();
void DEC_AbsoluteX();

// INX - Increment X Register
void INX();

// INY - Increment Y Register
void INY();

// DEX - Decrement X Register
void DEX();

// DEY - Decrement Y Register
void DEY();

// ASL - Arithmetic Shift Left
void ASL_Accumulator();
void ASL_ZeroPage();
void ASL_ZeroPageX();
void ASL_Absolute();
void ASL_AbsoluteX();

// LSR - Logical Shift Right
void LSR_Accumulator();
void LSR_ZeroPage();
void LSR_ZeroPageX();
void LSR_Absolute();
void LSR_AbsoluteX();

// ROL - Rotate Left
void ROL_Accumulator();
void ROL_ZeroPage();
void ROL_ZeroPageX();
void ROL_Absolute();
void ROL_AbsoluteX();

// ROR - Rotate Right
void ROR_Accumulator();
void ROR_ZeroPage();
void ROR_ZeroPageX();
void ROR_Absolute();
void ROR_AbsoluteX();

// Branching Instructions
void BCC();  // Branch if Carry Clear
void BCS();  // Branch if Carry Set
void BEQ();  // Branch if Equal
void BMI();  // Branch if Minus
void BNE();  // Branch if Not Equal
void BPL();  // Branch if Positive
void BVC();  // Branch if Overflow Clear
void BVS();  // Branch if Overflow Set

// Jumps and Calls
void JMP_Absolute();
void JMP_Indirect();
void JSR_Absolute();  // Jump to Subroutine
void RTS();           // Return from Subroutine

// Interrupts and Breaks
void BRK();  // Force Break
void RTI();  // Return from Interrupt

// Status Flag Instructions
void CLC();  // Clear Carry Flag
void SEC();  // Set Carry Flag
void CLI();  // Clear Interrupt Disable
void SEI();  // Set Interrupt Disable
void CLD();  // Clear Decimal Mode
void SED();  // Set Decimal Mode
void CLV();  // Clear Overflow Flag

// Transfers
void TAX();  // Transfer Accumulator to X
void TAY();  // Transfer Accumulator to Y
void TXA();  // Transfer X to Accumulator
void TYA();  // Transfer Y to Accumulator
void TSX();  // Transfer Stack Pointer to X
void TXS();  // Transfer X to Stack Pointer

// Stack Operations
void PHA();  // Push Accumulator
void PHP();  // Push Processor Status
void PLA();  // Pull Accumulator
void PLP();  // Pull Processor Status

// NOP - No Operation
void NOP();
#include "CPU.h"

// Define the lookup table with 256 entries, each corresponding to an opcode

#endif  // CPU_H
