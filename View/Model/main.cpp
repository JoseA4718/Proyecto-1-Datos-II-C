#include <iostream>
#include "src/Compiler/Compiler.h"
#include "src/Socket/Client.h"

int main() {
    auto *comp = new Compiler();
    cout << comp->compile("Integer var = 214;");

}
