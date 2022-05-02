//
// Created by Justin Jiang on 4/17/22.
//

#include "MultithreadedServer.h"

SS::MultithreadedServer::MultithreadedServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 1000  ) {
    start_server();
}

SS::MultithreadedServer::~MultithreadedServer() {
    delete get_socket();
}

void SS::MultithreadedServer::accepter() {
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    int new_socket = accept(get_socket()->get_sock(), (struct sockaddr*)&client_addr, &length);

    threadCount ++;
    std::cout << "Thread Count: " << threadCount << std::endl;

    std::thread t(&MultithreadedServer::read_loop, this, new_socket);
    t.detach();
}

void SS::MultithreadedServer::read_loop(const int &socket) {
    int bytesRead = 0;

    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    int read_connection;
    //Fill with Null character so that cout can easily stop printing after each individual message
    char buffer[SIMPLE_SERVER_BUFF_SIZE] = {0};

    std::thread t_read(&SS::MultithreadedServer::responder_handler, this, socket);

    while((std::chrono::duration_cast<std::chrono::seconds>(end - start).count() <= 5) && bytesRead <  SIMPLE_SERVER_BUFF_SIZE) {

        read_connection = read(socket, buffer, SIMPLE_SERVER_BUFF_SIZE);

        //reset 5-second timer whenever we read something
        if(read_connection > 0){
            start = std::chrono::system_clock::now();
        }
        std::cout << "READ CONNECTION " << read_connection << std::endl;
        write_handler(buffer);
        bytesRead += read_connection;
        memset(buffer, 0, SIMPLE_SERVER_BUFF_SIZE);
        end = std::chrono::system_clock::now();
    }

    close(socket);
    //Join read thread after close socket
    t_read.join();

}

void SS::MultithreadedServer::write_handler(const char* buffer) {

    std::cout << "THREAD: " << std::this_thread::get_id() << " " << buffer << " " << reqCount << std::endl;
    reqCount += 1;

    std::unique_lock lock(mutex_);
    std::cout << std::this_thread::get_id() << "has the write lock" << std::endl;
    messageThread.push_back(buffer);
    messageThreadStr += std::string(buffer) + '\n';
    std::cout << std::this_thread::get_id() << "has RELEASED the write lock" << std::endl;
    cv.notify_all();

}

void SS::MultithreadedServer::responder_handler(const int& socket) {

    while(get_socket()){
        std::shared_lock lock(mutex_);
        std::cout << std::this_thread::get_id() << "has the read lock" << std::endl;
        //Conditional Variable to wait for a writ.e to be made by a thread
        cv.wait(lock);
        write(socket, messageThreadStr.c_str(), strlen(messageThreadStr.c_str()));
        std::cout << std::this_thread::get_id() << "has RELEASED the read lock" << std::endl;
    }

}


void SS::MultithreadedServer::start_server() {
    //Why was threadcout set to like 1billion here???
    while(threadCount < 100){
        std::cout << ":::::::::WAITING::::::::" << std::endl;
        accepter();
        std::cout << ":::::::::DONE::::::::" << std::endl;
    }
}
