#include "Compiler/Compiler.h"

int main() {
    Compiler *com = new Compiler();
    cout << com->compile("Int v = 3;");
}