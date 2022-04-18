//
// Created by Justin Jiang on 4/16/22.
//

#include "TestServer.h"

SS::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 100  ) {
    start_server();
}

SS::TestServer::~TestServer() {
    delete get_socket();
}

void SS::TestServer::accepter() {
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);

    new_socket = accept(get_socket()->get_sock(), (struct sockaddr*)&client_addr, &length);
    read(new_socket, buffer, SIMPLE_SERVER_BUFF_SIZE);
}

void SS::TestServer::handler() {
    std::cout << buffer << " " << reqCount << std::endl;
    reqCount += 1;
}

void SS::TestServer::responder() {
    char* response = "Hello from server";
    write(new_socket, response, strlen(response));
    close(new_socket);
}

void SS::TestServer::start_server() {
    while(true){
        std::cout << ":::::::::WAITING::::::::" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << ":::::::::DONE::::::::" << std::endl;
    }
}