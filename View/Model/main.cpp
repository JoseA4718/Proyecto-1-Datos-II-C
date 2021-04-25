#include "src/ClientManager.h"
#include "src/Util/Coms/Response.h"
int main() {
/*    Compiler *c = new Compiler();
    string message = c->compile("Integer x = 2;" );
    Json *json = new Json();
    cout << message;*/
    ClientManager *resp = ClientManager::getInstance();

    resp->getInstance()->getCompiler()->processLine("Integer x=3;").show();
    resp->getInstance()->getCompiler()->processLine("Integer x= 3;").show();
    resp->getInstance()->getCompiler()->processLine("Integer x =3;").show();
    resp->getInstance()->getCompiler()->processLine("Integer x = 3;").show();
    resp->getInstance()->getCompiler()->processLine("Integer x =  3;").show();
    resp->getInstance()->getCompiler()->processLine("Integer     x   =   3;").show();

    // cout << ServerManager::getInstance()->processRequest(msg3) << endl;
}


