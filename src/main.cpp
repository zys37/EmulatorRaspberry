#include <iostream>
#include "MMU.h"
#include <iomanip>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
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

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.