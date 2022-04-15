//
// Created by Justin Jiang on 4/15/22.
//

#pragma once
#include "SimpleSocket.h"

namespace SS{
class ConnectingSocket : public SimpleSocket{
public:
    ConnectingSocket(const int& domain, const int& service, const int& protocol, const int& port, const u_long& interface);
    int connect_to_network(const int &sock, const struct sockaddr_in &address);

};
}

