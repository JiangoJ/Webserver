cmake_minimum_required(VERSION 3.21)
project(Webserver)

set(CMAKE_CXX_STANDARD 17)

add_executable(Webserver main.cpp Networking/SimpleSocket.cpp Networking/SimpleSocket.h Networking/BindingSocket.cpp Networking/BindingSocket.h Networking/ConnectingSocket.cpp Networking/ConnectingSocket.h)
