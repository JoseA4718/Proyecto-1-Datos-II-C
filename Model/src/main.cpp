#include "Compiler/Compiler.h"

int main() {

    auto *com = new Compiler();

    cout << com->compile("Integer v;");

}