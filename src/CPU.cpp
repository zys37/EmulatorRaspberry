//
// Created by Zys on 25/07/2026.
//

#include "CPU.h"
CPU::CPU(MMU& mmu) : mmu(mmu) {
    PC = 0x0100;
    SP = 0xFFFE;
    AF.reg=0x01B0;
    BC.reg=0x0013;
    DE.reg=0x00D8;
    HL.reg=0x014D;
}
void CPU::step() {
    //fetch
}
