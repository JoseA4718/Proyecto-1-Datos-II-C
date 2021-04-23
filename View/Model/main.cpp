#include "src/Socket/Client.h"
#include "src/Compiler/Compiler.h"

int main() {
/*    Compiler *c = new Compiler();
    string message = c->compile("Integer x = 2;" );
    Json *json = new Json();
    cout << message;*/
    string msg = R"({"message":"{\"key\":\"help\",\"addr\":\"0x5615eeb6b044\",\"value\":\"1\",\"offset\":1,\"referenceCount\":0,\"offset\":1}","log":"Integer help was created.","statusCode":200})";
    Response *resp = Json::readJsonResponse(msg);
    resp->show();
    // cout << ServerManager::getInstance()->processRequest(msg3) << endl;
}


