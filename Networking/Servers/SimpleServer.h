//
// Created by Justin Jiang on 4/15/22.
//

#pragma once
#include "../Sockets/jjjlibc-sockets.h"
#include <stdio.h>
#include <unistd.h>

#define SIMPLE_SERVER_BUFF_SIZE 30000

namespace SS{
class SimpleServer {
private:
    ListeningSocket* socket;
    virtual void accepter() = 0;
    virtual void handler() = 0;
    virtual void responder() = 0;

public:
    SimpleServer(const int& domain, const int& service, const int& protocol, const int& port, const u_long& interface, const int& bklg);
    ~SimpleServer();
    ListeningSocket* get_socket() const;
};
}


