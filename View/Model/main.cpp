#include <iostream>
#include "src/Compiler/Compiler.h"
int main() {
    Compiler *comp = new Compiler();
    cout << comp->compile("Integer var;");
}
