#include <iostream>

#include "main.h"

int main() {
//    std::cout << "Starting..." << std::endl;
//
//    std::cout << "Binding Socket..." << std::endl;
//    SS::BindingSocket bs(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY);
//
//    std::cout << "Listening Socket..." << std::endl;
//    SS::ListeningSocket ls(AF_INET, SOCK_STREAM, 0, 81, INADDR_ANY, 10);
//
//    std::cout << "Success..." << std::endl;

    SS::MultithreadedServer();
    //SS::TestServer();
    return 0;
}
