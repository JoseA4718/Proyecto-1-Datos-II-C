//
// Created by josea4718 on 4/19/21.
//

#ifndef VIEW_CLIENT_H
#define VIEW_CLIENT_H


#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

#pragma once

using namespace std;

class Client {
private:
    int sock;
    int port = 5000;
    int connectRes;
    sockaddr_in hint;
    std::string ipAddress = "127.0.0.1";
    char buf[4092];
    static Client *instance;

    Client();

public:
    static Client getInstance() {
        if (instance == nullptr) {
            instance = new Client;
        }
        return *instance;
    }

    [[noreturn]] void Start() {

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            exit(1);
        }

        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

        //    Connect to the server on the socket
        connectRes = connect(sock, (sockaddr *) &hint, sizeof(hint));
        if (connectRes == -1) {
            exit(1);
        }

        bool run = true;
        while (run) {
            memset(buf, 0, 4096);
            int bytesReceived = recv(sock, buf, 4096, 0);
            if (bytesReceived == -1) {
                std::cout << "Error getting response" << std::endl;
            } else {

                //        Display response
                std::cout << "From Server:" << std::string(buf, bytesReceived) << std::endl;
            }
        }
    }

    void Send(char *);

};
#endif