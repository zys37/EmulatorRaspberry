//
// Created by Zys on 24/07/2026.
//
#include "MMU.h"
#include <iostream>
#include <fstream>

MMU::MMU() {
    memory.fill(0);
}

uint8_t MMU::read_byte(uint16_t address) {
    return memory[address];
}

void MMU::load_rom(const std::string &filepath) {
    std::ifstream file(filepath,std::ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(memory.data()),memory.size());
    }
    else {
        std::cerr << "Failed to open file " << filepath << std::endl;
    }
}
