#include "src/ClientManager.h"
#include "src/Util/Coms/Response.h"
int main() {
/*    Compiler *c = new Compiler();
    string message = c->compile("Integer x = 2;" );
    Json *json = new Json();
    cout << message;*/
    ClientManager* resp = ClientManager::getInstance();
    //Response *resp = ClientManager::getInstance()->process("Integer x = 2;");

    // cout << ServerManager::getInstance()->processRequest(msg3) << endl;
}


