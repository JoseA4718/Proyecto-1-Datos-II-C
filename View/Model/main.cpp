#include "src/ClientManager.h"
#include "src/Util/Coms/Response.h"
int main() {
    Compiler *comp = new Compiler();
    string str = "Reference<Integer> ref = Int.getAddr();";
     cout << comp->compile(str);

}


