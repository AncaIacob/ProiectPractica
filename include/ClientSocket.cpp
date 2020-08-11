#include "ClientSocket.hpp"
#include <iostream>

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h> 

ClientSocket::ClientSocket(std::string address, int port)
{
    

}
ClientSocket::~ClientSocket()
{
    close(m_fd);
}

ClientSocket::operator bool()
{  
 return m_fd != 0; 
}

bool ClientSocket::connect()
{

}

void ClientSocket::send(std::vector<std::byte> message)
{

}
void ClientSocket::receive(std::vector<std::byte> message)
{ 

}