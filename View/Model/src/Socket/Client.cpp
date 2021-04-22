//
// Created by josea4718 on 4/19/21.
//

#include "Client.h"
#include "string"

Client::Client() {}

void Client::Send(char *msg) {
    int sendRes = send(sock, msg, strlen(msg), 0);
    if (sendRes == -1) {
        std::cout << "Send message failed" << std::endl;
    }
}
