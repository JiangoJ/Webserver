//
// Created by Justin Jiang on 4/15/22.
//

#include "BindingSocket.h"

SS::BindingSocket::BindingSocket(const int &domain, const int &service, const int &protocol, const int &port,
                                 const u_long &interface) : SimpleSocket(domain, service, protocol, port, interface){

    set_connection(connect_to_network(get_sock(), get_address()));
    test_connection(get_connection());
}

int SS::BindingSocket::connect_to_network(const int &sock, const struct sockaddr_in &address) {
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}
