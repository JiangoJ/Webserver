//
// Created by Justin Jiang on 4/15/22.
//

#include "SimpleServer.h"

SS::SimpleServer::SimpleServer(const int &domain, const int &service, const int &protocol, const int &port,
                               const u_long &interface, const int &bklg) {
    socket = new ListeningSocket(domain, service, protocol, port, interface, bklg);
}

SS::SimpleServer::~SimpleServer() {
    delete socket;
}

SS::ListeningSocket* SS::SimpleServer::get_socket() const {
    return socket;
}

