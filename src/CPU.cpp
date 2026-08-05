//
// Created by Zys on 25/07/2026.
//

#include "CPU.h"

#include <iostream>

CPU::CPU(MMU& mmu) : mmu(mmu) {
    PC = 0x0100;
    SP = 0xFFFE;
    AF.reg=0x01B0;
    BC.reg=0x0013;
    DE.reg=0x00D8;
    HL.reg=0x014D;
}
void CPU::step() {
    uint8_t opcode = mmu.read_byte(PC);
    PC++;
    std::cout <<PC<<std::endl;
    switch (opcode) {
        case 0x00: {
            break;
        }
        default: {
            std::cout<<"nieznana instrukcja"<<std::endl;
            std::cout << "Opcode, to: " << std::hex << static_cast<int>(opcode) << std::endl;
            exit(1);
        }
        case 0xC3: {
            uint8_t lo = mmu.read_byte(PC);
            PC++;
            uint8_t hi = mmu.read_byte(PC);
            PC++;
            uint8_t address = (hi << 8) | lo;
            PC = address;
            break;
        }
        case 0xF0: {
            uint8_t a8 = mmu.read_byte(PC);
            PC++;
            uint16_t address = 0xFF00 + a8;
            uint8_t value = mmu.read_byte(address);
            AF.hi = value;
            break;
        }
        case 0xFE: {
            uint8_t n8 = mmu.read_byte(PC);
            PC++;
            uint8_t a = AF.hi;
            AF.lo = 0;
            if (a==n8) {
                AF.lo |=(1<<7);
            }
            AF.lo |= (1<<6);
            if ((a & 0x0F) < (n8 & 0x0F)) {
                AF.lo |= (1<<5);
            }
            if (a < n8) {
                AF.lo |= (1<<4);
            }
            break;
        }
        case 0xC8: {
            if (AF.lo & (1<<7)) {
                uint8_t lo = mmu.read_byte(SP);
                SP++;
                uint8_t hi = mmu.read_byte(SP);
                SP++;
                uint16_t returnAddress = (hi << 8) | lo;
                PC = returnAddress;
            }
            break;
        }
        case 0xE0: {
            uint8_t a8 = mmu.read_byte(PC);
            PC++;
            uint16_t address = 0xFF00 + a8;
            mmu.write_byte(address, AF.hi);
            break;
        }

        }
    //fetch
    //decode
    //executre
}
