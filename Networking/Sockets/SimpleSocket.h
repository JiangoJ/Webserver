//
// Created by Justin Jiang on 4/15/22.
//

#pragma once
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace SS{

class SimpleSocket{
private:
    int connection;
    int sock;
    struct sockaddr_in address;
public:
    SimpleSocket(const int& domain, const int& service, const int& protocol, const int& port, const u_long& interface);
    virtual int connect_to_network(const int& sock, const struct sockaddr_in& address) = 0;
    void test_connection(int item);

    int get_connection() const;
    void set_connection(int s);
    int get_sock() const;
    struct sockaddr_in get_address() const;

};
}


