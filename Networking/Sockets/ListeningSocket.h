//
// Created by Justin Jiang on 4/15/22.
//

#pragma once
#include "BindingSocket.h"

namespace SS{
class ListeningSocket : public BindingSocket{
private:
    int backlog;
    int listening;
public:
    ListeningSocket(const int& domain, const int& service, const int& protocol, const int& port, const u_long& interface, const int& bklg);
    void start_listening();
    int get_backlog();
};
}



