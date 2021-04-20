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
    static Client getInstance();

    [[noreturn]] void Start();

    void Send(char *);

};

#endif