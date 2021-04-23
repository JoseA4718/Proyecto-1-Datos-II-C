//
// Created by eduardo218 on 4/23/21.
//

#include "ClientManager.h"


ClientManager *ClientManager::instance = nullptr;


ClientManager::ClientManager() {
    this->compiler = new Compiler();

}

ClientManager *ClientManager::getInstance() {
    if (instance == nullptr) {
        instance = new ClientManager();
    }
    return instance;
}