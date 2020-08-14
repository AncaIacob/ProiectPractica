#include "ClientSocket.hpp"
#include <iostream>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <string.h>

ClientSocket::ClientSocket(std::string address, int port)
{
    m_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(bool())
    {
        perror("Couldn't create socket");
        m_fd = 0;

    }else
    {
        std::cout << "Succesfully created Client Socket" << std::endl;
    }
    

    serv_addr.sin_family = AF_INET; //Internet Protocol v4 addresses
    serv_addr.sin_port = htons(port);

    //converts text to binary form 
    if(inet_pton(AF_INET, address.c_str(), &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
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
    if (::connect(m_fd, (sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return false; 
    } 
    return true;
}

void ClientSocket::send(std::vector<std::byte> &message)
{
    ::send(m_fd , message.data() , message.size() , 0 );
    std::cout << "client(" << m_fd << "):Message sent from client\n";
}
<<<<<<< HEAD
void ClientSocket::receive(std::vector<std::byte> message)
{
} 

void ClientSocket::receive(std::vector<std::byte> &buffer)
{
    int readStuff = ::read(m_fd, buffer.data(), buffer.size());
    if(readStuff < 0)
    {
        perror("read");
    }
    std::cout << "client(" << m_fd << "): Message received (" << readStuff << " characters)\n";
}