//
// Created by Zys on 24/07/2026.
//

#ifndef MMU_H
#define MMU_H
#include <array>
#include <cstdint>
#include <string>


class MMU {
public:
    MMU();
    void load_rom(const std::string& filepath);
    uint8_t read_byte(uint16_t address);
private:
    std::array<uint8_t, 65536> memory;
};



#endif //MMU_H
