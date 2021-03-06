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
        m_fd = 0;
    } 

    int opt = 1;
    if (setsockopt(m_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
    } 

    m_address.sin_family = AF_INET; 
    m_address.sin_addr.s_addr = INADDR_ANY; 
    m_address.sin_port = htons(port); 

    if (bind(m_fd, (struct sockaddr *)&m_address,  
                                 sizeof(m_address))<0) 
    { 
        perror("bind failed"); 
    } 

    if(listen(m_fd, 1) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

ServerSocket::~ServerSocket()
{
    close(m_fd);
}

ClientSocket ServerSocket::accept()
{
<<<<<<< HEAD
     
}
=======
    int newSocket;
    int addrlen = sizeof(m_address); 


    if ((newSocket = ::accept(m_fd, (sockaddr *)&m_address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept failed");  
    } 

    return ClientSocket(newSocket);
}
>>>>>>> 843c64c143ee528e4331b5bb23cce0b875ac869d
