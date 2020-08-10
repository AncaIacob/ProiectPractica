#include "ClientSocket.hpp"
#include <iostream>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <string.h>
#define SIZEREAD 1024

ClientSocket::ClientSocket(std::string address, int port)
{
    m_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(m_fd == -1)
    {
        perror("Couldn't create socket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET; //Internet Protocol v4 addresses
    serv_addr.sin_port = htons(port);

    //converts text to binary form 
    if(inet_pton(AF_INET, address.c_str(), &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        exit(EXIT_FAILURE);
    } 

}

ClientSocket::ClientSocket(int fd)
{
    m_fd = fd;
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
    if (::connect(m_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return false; 
    } 
    return true;
}

void ClientSocket::send(std::vector<std::byte> &message)
{
    ::send(m_fd , &message , message.size() , 0 );
    std::cout << "Message sent from client\n";
}

void ClientSocket::receive()
{
    char buffer[SIZEREAD] = {0};
    int readStuff = ::read(m_fd, buffer, SIZEREAD);
    std::cout << "Message read (" << readStuff << " characters) from server:\n";
    std::cout << buffer << std::endl;
}