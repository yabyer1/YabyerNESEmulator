//registers
#include <cstdint>
#include <iostream>
#include "CPU.h"
uint8_t a = 0; // accumulator
uint8_t x = 0; //index x
uint8_t y = 0; //index y
uint16_t pc = 0; // program counter
uint8_t sp = 0; //stack pointer
uint8_t p = 0; // used by Aly byte wide
uint8_t memory[65536] = {0};  // 64KB of memory (addresses 0x0000 - 0xFFFF)
int cycles = 0; // will be used for the cock


Instruction lookup[256] = {
    /* 0x00 - 0x0F */
    &BRK, &ORA_IndirectX, &NOP, &NOP, &NOP, &ORA_ZeroPage, &ASL_ZeroPage, &NOP,
    &PHP, &ORA_Immediate, &ASL_Accumulator, &NOP, &NOP, &ORA_Absolute, &ASL_Absolute, &NOP,

    /* 0x10 - 0x1F */
    &BPL, &ORA_IndirectY, &NOP, &NOP, &NOP, &ORA_ZeroPageX, &ASL_ZeroPageX, &NOP,
    &CLC, &ORA_AbsoluteY, &NOP, &NOP, &NOP, &ORA_AbsoluteX, &ASL_AbsoluteX, &NOP,

    /* 0x20 - 0x2F */
    &JSR_Absolute, &AND_IndirectX, &NOP, &NOP, &BIT_ZeroPage, &AND_ZeroPage, &ROL_ZeroPage, &NOP,
    &PLP, &AND_Immediate, &ROL_Accumulator, &NOP, &BIT_Absolute, &AND_Absolute, &ROL_Absolute, &NOP,

    /* 0x30 - 0x3F */
    &BMI, &AND_IndirectY, &NOP, &NOP, &NOP, &AND_ZeroPageX, &ROL_ZeroPageX, &NOP,
    &SEC, &AND_AbsoluteY, &NOP, &NOP, &NOP, &AND_AbsoluteX, &ROL_AbsoluteX, &NOP,

    /* 0x40 - 0x4F */
    &RTI, &EOR_IndirectX, &NOP, &NOP, &NOP, &EOR_ZeroPage, &LSR_ZeroPage, &NOP,
    &PHA, &EOR_Immediate, &LSR_Accumulator, &NOP, &JMP_Absolute, &EOR_Absolute, &LSR_Absolute, &NOP,

    /* 0x50 - 0x5F */
    &BVC, &EOR_IndirectY, &NOP, &NOP, &NOP, &EOR_ZeroPageX, &LSR_ZeroPageX, &NOP,
    &CLI, &EOR_AbsoluteY, &NOP, &NOP, &NOP, &EOR_AbsoluteX, &LSR_AbsoluteX, &NOP,

    /* 0x60 - 0x6F */
    &RTS, &ADC_IndirectX, &NOP, &NOP, &NOP, &ADC_ZeroPage, &ROR_ZeroPage, &NOP,
    &PLA, &ADC_Immediate, &ROR_Accumulator, &NOP, &JMP_Indirect, &ADC_Absolute, &ROR_Absolute, &NOP,

    /* 0x70 - 0x7F */
    &BVS, &ADC_IndirectY, &NOP, &NOP, &NOP, &ADC_ZeroPageX, &ROR_ZeroPageX, &NOP,
    &SEI, &ADC_AbsoluteY, &NOP, &NOP, &NOP, &ADC_AbsoluteX, &ROR_AbsoluteX, &NOP,

    /* 0x80 - 0x8F */
    &NOP, &STA_IndirectX, &NOP, &NOP, &STY_ZeroPage, &STA_ZeroPage, &STX_ZeroPage, &NOP,
    &DEY, &NOP, &TXA, &NOP, &STY_Absolute, &STA_Absolute, &STX_Absolute, &NOP,

    /* 0x90 - 0x9F */
    &BCC, &STA_IndirectY, &NOP, &NOP, &STY_ZeroPageX, &STA_ZeroPageX, &STX_ZeroPageY, &NOP,
    &TYA, &STA_AbsoluteY, &TXS, &NOP, &NOP, &STA_AbsoluteX, &NOP, &NOP,

    /* 0xA0 - 0xAF */
    &LDY_Immediate, &LDA_IndirectX, &LDX_Immediate, &NOP, &LDY_ZeroPage, &LDA_ZeroPage, &LDX_ZeroPage, &NOP,
    &TAY, &LDA_Immediate, &TAX, &NOP, &LDY_Absolute, &LDA_Absolute, &LDX_Absolute, &NOP,

    /* 0xB0 - 0xBF */
    &BCS, &LDA_IndirectY, &NOP, &NOP, &LDY_ZeroPageX, &LDA_ZeroPageX, &LDX_ZeroPageY, &NOP,
    &CLV, &LDA_AbsoluteY, &TSX, &NOP, &LDY_AbsoluteX, &LDA_AbsoluteX, &LDX_AbsoluteY, &NOP,

    /* 0xC0 - 0xCF */
    &CPY_Immediate, &CMP_IndirectX, &NOP, &NOP, &CPY_ZeroPage, &CMP_ZeroPage, &DEC_ZeroPage, &NOP,
    &INY, &CMP_Immediate, &DEX, &NOP, &CPY_Absolute, &CMP_Absolute, &DEC_Absolute, &NOP,

    /* 0xD0 - 0xDF */
    &BNE, &CMP_IndirectY, &NOP, &NOP, &NOP, &CMP_ZeroPageX, &DEC_ZeroPageX, &NOP,
    &CLD, &CMP_AbsoluteY, &NOP, &NOP, &NOP, &CMP_AbsoluteX, &DEC_AbsoluteX, &NOP,

    /* 0xE0 - 0xEF */
    &CPX_Immediate, &SBC_IndirectX, &NOP, &NOP, &CPX_ZeroPage, &SBC_ZeroPage, &INC_ZeroPage, &NOP,
    &INX, &SBC_Immediate, &NOP, &NOP, &CPX_Absolute, &SBC_Absolute, &INC_Absolute, &NOP,

    /* 0xF0 - 0xFF */
    &BEQ, &SBC_IndirectY, &NOP, &NOP, &NOP, &SBC_ZeroPageX, &INC_ZeroPageX, &NOP,
    &SED, &SBC_AbsoluteY, &NOP, &NOP, &NOP, &SBC_AbsoluteX, &INC_AbsoluteX, &NOP
};
void SEI() {
    p |= 0x04;
    cycles += 2;
}

void TAX() {
    x = a;
    cycles += 2;
}

void TSX() {
    x = sp;
    if (x == 0) {
        p |= 0x02;
    } else {
        p &= ~(0x02);
    }
    if (x & 0x80) {
        p |= (0x80);
    } else {
        p &= ~(0x80);
    }
    cycles = 2;
}
int main() {
    std::cout << "Starting NES Emulator..." << std::endl;

   
    return 0;
}