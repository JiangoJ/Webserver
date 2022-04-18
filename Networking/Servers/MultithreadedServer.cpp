//
// Created by Justin Jiang on 4/17/22.
//

#include "MultithreadedServer.h"

SS::MultithreadedServer::MultithreadedServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 100  ) {
    start_server();
}

SS::MultithreadedServer::~MultithreadedServer() {
    delete get_socket();
}

void SS::MultithreadedServer::accepter() {
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    int new_socket = accept(get_socket()->get_sock(), (struct sockaddr*)&client_addr, &length);

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

    while((std::chrono::duration_cast<std::chrono::seconds>(end - start).count() <= 5) && bytesRead <  SIMPLE_SERVER_BUFF_SIZE) {

        read_connection = read(socket, buffer + bytesRead, SIMPLE_SERVER_BUFF_SIZE - bytesRead);
        //get_socket()->test_connection(read_connection);

        handler(buffer + bytesRead);
        //read_connection is also how many bytes were read
        bytesRead += read_connection;

        responder(socket);
    }

    close(socket);

}

void SS::MultithreadedServer::handler(const char* buffer) {
    std::cout << "THREAD: " << std::this_thread::get_id() << " " << buffer << " " << reqCount << std::endl;
    reqCount += 1;
}

void SS::MultithreadedServer::responder(const int& socket) {
    char* response = "Hello Client";
    write(socket, response, strlen(response));
}

void SS::MultithreadedServer::start_server() {
    while(threadCount < 100){
        std::cout << ":::::::::WAITING::::::::" << std::endl;
        accepter();
        std::cout << ":::::::::DONE::::::::" << std::endl;
    }
}
