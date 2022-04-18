cmake_minimum_required(VERSION 3.21)
project(Webserver)

set(CMAKE_CXX_STANDARD 17)

add_executable(Webserver main.cpp Networking/Sockets/SimpleSocket.cpp Networking/Sockets/SimpleSocket.h Networking/Sockets/BindingSocket.cpp Networking/Sockets/BindingSocket.h Networking/Sockets/ConnectingSocket.cpp Networking/Sockets/ConnectingSocket.h Networking/Sockets/ListeningSocket.cpp Networking/Sockets/ListeningSocket.h Networking/Sockets/jjjlibc-sockets.h Networking/jjjlibc-networking.h main.h Networking/Servers/SimpleServer.cpp Networking/Servers/SimpleServer.h Networking/Servers/TestServer.cpp Networking/Servers/TestServer.h Networking/Servers/jjjlibc-servers.h Networking/Servers/MultithreadedServer.cpp Networking/Servers/MultithreadedServer.h)
