#include <iostream>
#include "MMU.h"
#include <iomanip>

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "C++";
    MMU mmu;
    mmu.load_rom("../roms/tetris.gb");
    uint8_t opcode = mmu.read_byte(0x0100);
    std::cout << "opcode: " << std::hex << static_cast<int>(opcode) << std::endl;
    return 0;
}

