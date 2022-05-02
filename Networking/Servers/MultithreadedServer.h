//
// Created by Justin Jiang on 4/17/22.
//

#pragma once
#include "SimpleServer.h"
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>

namespace SS{
class MultithreadedServer : SimpleServer{
private:
//    std::vector<std::array<char, SIMPLE_SERVER_BUFF_SIZE>> buffers;
//    std::vector<int> sockets;
    int reqCount;
    std::vector<std::string> messageThread;
    std::string messageThreadStr;
    mutable std::shared_mutex mutex_;
    std::condition_variable_any cv;

    void accepter();
    void handler(){};
    void responder(){};

    void read_loop(const int& socket);
    void write_handler(const char* buffer);
    void responder_handler(const int& socket);


    int threadCount = 0;

public:
    MultithreadedServer();
    ~MultithreadedServer();
    void start_server();

};
}
