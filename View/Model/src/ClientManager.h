//
// Created by eduardo218 on 4/23/21.
//

#ifndef MODEL_CLIENTMANAGER_H
#define MODEL_CLIENTMANAGER_H


#include <mutex>
#include "Socket/Client.h"
#include "Compiler/Compiler.h"
#include "ServerConnection.h"

/**
 * This class provides an API for the backend of the C! editor.
 */
class ClientManager {
private:
    /**Compiler class for processing the lines of the editor.*/
    Compiler *compiler;

private:

    /**Singleton instance*/
    static ClientManager *pinstance_;
    static std::mutex mutex_;
public:
    Compiler *getCompiler() const;

protected:
    ClientManager() {
        compiler = new Compiler();
    }

    ~ClientManager() {}

public:
    ClientManager(ClientManager &other) = delete;

    void operator=(const ClientManager &) = delete;

    static ClientManager *getInstance();
    /**
     * @brief Compiles the received line and sends it to the server
     * @param line receives a line to send it to the server
     * @return the result object of the response
     */
    Response *process(string line) {
        auto *result = new Response();
        try {
            string message = this->compiler->compile(line);
            if (message[0] != '{' or message[message.length()-1] != '}') {

                throw message;
            }
            result = ServerConnection::sendMessage(message);
        } catch (string e) {
            result->setStatusCode(600);
            result->setLog(e);
            cerr << e << endl;
        }

        return result;
    }
};

ClientManager *ClientManager::pinstance_{nullptr};
std::mutex ClientManager::mutex_;

/**
 * @brief Singleton instantiation of the client manager
 * @return hte client manager singleton instance
 */
ClientManager *ClientManager::getInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new ClientManager();
    }
    return pinstance_;
}
/**
 *
 * @return returns the client manager compiler
 */
Compiler *ClientManager::getCompiler() const {
    return compiler;
}

#endif //MODEL_CLIENTMANAGER_H
