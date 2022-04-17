//
// Created by Justin Jiang on 4/16/22.
//

#pragma once
#include "SimpleServer.h"

namespace SS{

class TestServer : public SimpleServer {
private:
    char buffer[SIMPLE_SERVER_BUFF_SIZE] = {0};
    int new_socket;

    void accepter();
    void handler();
    void responder();

public:
    TestServer();
    ~TestServer();
    void start_server();
};

}



