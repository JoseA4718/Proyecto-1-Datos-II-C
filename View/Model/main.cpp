#include "src/ClientManager.h"
#include "src/Util/Coms/Response.h"
int main() {
    Compiler *comp = new Compiler();
    string str = "Reference<Integer> ref = Int.getAddr();";
    comp->processLine(str).show();
    cout << (str[0] == '{') << endl;
    cout << (str[str.length()-1] == '}') << endl;


}


