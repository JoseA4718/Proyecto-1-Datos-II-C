//
// Created by eduardo218 on 4/23/21.
//

#ifndef MODEL_CLIENTMANAGER_H
#define MODEL_CLIENTMANAGER_H


#include "Compiler/Compiler.h"

class ClientManager {
private:
    /**Compiler class for processing the lines of the editor.*/
    Compiler *compiler;
    /**Singleton instance*/
    static ClientManager *instance;

    /**Private constructor*/
    ClientManager();


public:
    static ClientManager *getInstance();

    Response *process(string line) {
        cout << "Processing line: " << line << endl;
        string message = this->compiler->compile(line);
        // todo: send request to server.
        string response = R"({"message":"{\"key\":\"help\",\"addr\":\"0x5615eeb6b044\",\"value\":\"1\",\"offset\":1,\"referenceCount\":0,\"offset\":1}","log":"Integer help was created.","statusCode":200})";
        cout << "Result from server: " << response << endl;
        Response *result = Json::readJsonResponse(response);
        return result;
    }
};

#endif //MODEL_CLIENTMANAGER_H
