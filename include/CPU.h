//
// Created by Zys on 25/07/2026.
//

#ifndef CPU_H
#define CPU_H
#include <cstdint>
#include <MMU.h>
union Register {
    uint16_t reg;
    struct {
        uint8_t lo, hi;
    };
};


class CPU {
public:
    CPU(MMU& mmu)
    void step();
private:
    MMU& mmu;
    Register AF;
    Register BC;
    Register DE;
    Register HL;
    uint16_t PC; //programcounter
    uint16_t SP; //stackpointer
};



#endif //CPU_H
