//
// Created by Justin Jiang on 4/17/22.
//

#pragma once
#include "SimpleServer.h"
#include <chrono>
#include <thread>
#include <vector>

namespace SS{
class MultithreadedServer : SimpleServer{
private:
//    std::vector<std::array<char, SIMPLE_SERVER_BUFF_SIZE>> buffers;
//    std::vector<int> sockets;
    int reqCount;

    void accepter();
    void read_loop(const int& socket);
    void handler(const char* buffer);
    void responder(const int& socket);
    void handler(){};
    void responder(){};

    int threadCount;
    std::vector<std::thread> threads;

public:
    MultithreadedServer();
    ~MultithreadedServer();
    void start_server();

};
}
