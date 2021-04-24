//
// Created by eduardo218 on 4/23/21.
//

#ifndef MODEL_CLIENTMANAGER_H
#define MODEL_CLIENTMANAGER_H


#include <mutex>
#include "Socket/Client.h"
#include "Compiler/Compiler.h"

class ClientManager {
private:
    /**Compiler class for processing the lines of the editor.*/
    Compiler *compiler;

private:

    /**Singleton instance*/
    static ClientManager *pinstance_;
    static std::mutex mutex_;
protected:
    ClientManager() {
        compiler = new Compiler();
    }

    ~ClientManager() {}

public:
    ClientManager(ClientManager &other) = delete;

    void operator=(const ClientManager &) = delete;

    static ClientManager *getInstance();

    Response *process(string line) {
        cout << "Processing line: " << line << endl;
        string message = this->compiler->compile(line);

        // todo: get the response from the server AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        Client::getInstance()->Send(message.c_str());
        string response;
        while (response.empty()){
            response = Client::getInstance()->getMessage();
        }
        cout << "FROM SERVER: " << response << endl;
        Client::getInstance()->setMessage("");

        Response *result = Json::readJsonResponse(response);
        return result;
    }
};

ClientManager *ClientManager::pinstance_{nullptr};
std::mutex ClientManager::mutex_;

ClientManager *ClientManager::getInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new ClientManager();
    }
    return pinstance_;
}

#endif //MODEL_CLIENTMANAGER_H
