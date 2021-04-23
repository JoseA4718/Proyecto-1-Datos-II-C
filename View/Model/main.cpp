#include "src/Socket/Client.h"
#include "src/Compiler/Compiler.h"
#include "src/ClientManager.h"

int main() {
/*    Compiler *c = new Compiler();
    string message = c->compile("Integer x = 2;" );
    Json *json = new Json();
    cout << message;*/
    Response *resp = ClientManager::getInstance()->process("Integer x = 2;");
    resp->show();
    // cout << ServerManager::getInstance()->processRequest(msg3) << endl;
}


