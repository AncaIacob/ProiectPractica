#ifndef CLIENTSOCKET_HPP
#define CLIENTSOCKET_HPP
#include "ClientSocket.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <netinet/in.h>

class ClientSocket
{
public:
    ClientSocket(std::string address, int port);
    ClientSocket(int fd);
    ~ClientSocket();

    operator bool();
    bool connect();

    void send(std::vector<std::byte> &message);
    void receive();

private:
    int m_fd;
    struct sockaddr_in serv_addr;
};

#include "ClientSocket.cpp"
#endif //CLIENTSOCKET_HPP