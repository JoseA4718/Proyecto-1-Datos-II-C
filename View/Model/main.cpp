#include "src/Socket/Client.h"
#include "src/Compiler/Compiler.h"

int main() {
    Compiler *c = new Compiler();
    string message = c->compile("Integer x = 2;");
    Json *json = new Json();
    cout << message;

}


