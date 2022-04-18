//
// Created by Justin Jiang on 4/15/22.
//

#include "ListeningSocket.h"

SS::ListeningSocket::ListeningSocket(const int &domain, const int &service, const int &protocol, const int &port,
                                     const u_long &interface, const int &bklg) : BindingSocket(domain, service, protocol, port, interface), backlog(bklg){

    start_listening();
    test_connection(listening);

}

void SS::ListeningSocket::start_listening() {
    listening = listen(get_sock(), backlog);
}

int SS::ListeningSocket::get_backlog() {
    return backlog;
}