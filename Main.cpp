#include "ClientSocket.hpp"
#include "ServerSocket.hpp"
#include <iostream>
#include <thread>
#include <string>
#include <stdlib.h>     //for using the function sleep
#include <cstddef>

#define PORT 8081

void createServerSocket()
{
    ServerSocket ss(PORT); //create new server socket
    ClientSocket newCs = ss.accept(); //accept pending client(s)

    std::vector<std::byte> message(6);
    newCs.receive(message); //read the client message

    std::cout << "Received Message: \n";
    for(auto a : message)
    {
        std::cout << (char)a << " ";
    }
    std::cout << "\nDONE" << std::endl;
}

void createClientSocket()
{
    ClientSocket cs("127.0.0.1", PORT); //create new client socket
    if(cs.connect())
    {
        std::cout << "Succesfully client connected" << std::endl;
    }else
    {
        std::cout << "Failed client connected" << std::endl;
    }
    

    std::vector<std::byte> message;
    message.push_back(static_cast<std::byte>('a'));
    message.push_back(static_cast<std::byte>('b'));
    message.push_back(static_cast<std::byte>('c'));

    cs.send(message);
}


int main()
{
    std::thread tss(createServerSocket);
    sleep(1);
    std::thread tcs(createClientSocket);

    tss.join();
    tcs.join();

    return 0;
}

