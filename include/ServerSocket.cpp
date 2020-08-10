#include "ServerSocket.hpp"
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 

ServerSocket::ServerSocket(int port)
{
    if ((m_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    int opt = 1;
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(m_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 

    m_address.sin_family = AF_INET; 
    m_address.sin_addr.s_addr = INADDR_ANY; 
    m_address.sin_port = htons(port); 

}

ServerSocket::~ServerSocket()
{
    close(m_fd);
}

ClientSocket ServerSocket::accept()
{
    int newSocket;
    int addrlen = sizeof(m_address); 

    if ((newSocket = ::accept(m_fd, (struct sockaddr *)&m_address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    return ClientSocket(newSocket);
}
