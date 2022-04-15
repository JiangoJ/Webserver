//
// Created by Justin Jiang on 4/15/22.
//

#include "SimpleSocket.h"

SS::SimpleSocket::SimpleSocket(const int &domain, const int &service, const int &protocol, const int& port, const u_long& interface){

    // define address structure
    address.sin_family = domain;
    // htons reverses the little endian formatting of integer in memory. We want most significant first
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // establish connection
    sock = socket(domain, service, protocol);
    test_connection(sock);

}

void SS::SimpleSocket::test_connection(int item) {
    if(item < 0){
        perror("Failed Connection ....");
        exit(EXIT_FAILURE);
    }
    printf("Successful Connection");
}

int SS::SimpleSocket::get_connection() const {return connection;}

void SS::SimpleSocket::set_connection(int c) { connection = c ; }

int SS::SimpleSocket::get_sock() const {return sock;}

struct sockaddr_in SS::SimpleSocket::get_address() const { return address;}
