#include <iostream>
#include "MMU.h"
#include <iomanip>

#include "CPU.h"

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "C++";
    MMU mmu;
    CPU cpu(mmu);
    mmu.load_rom("../roms/tetris.gb");
    uint8_t opcode = mmu.read_byte(0x0100);
    std::cout << "opcode: " <<std::hex<< std::uppercase  << static_cast<int>(opcode) << std::endl;
    while (true) {
        cpu.step();
    }
    return 0;
}

