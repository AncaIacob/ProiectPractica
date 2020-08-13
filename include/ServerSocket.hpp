#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP
#include "ClientSocket.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <netinet/in.h>

class ServerSocket
{
public:
    ServerSocket(int port);
    ~ServerSocket();

    ClientSocket accept();
    // void listen(int backlog);

private:
    std::size_t m_fd;
    std::string m_port;
    struct sockaddr_in m_address;
};

#include "ServerSocket.cpp"
#endif //SERVERSOCKET_HPP