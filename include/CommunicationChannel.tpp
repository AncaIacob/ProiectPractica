#include "CommunicationChannel.hpp"

#include <cstddef>

template <typename TChannel>
CommunicationChannel<TChannel>::CommunicationChannel(TChannel channel)
{
    m_channel = channel;
}

template <typename TChannel>
bool sendMessage(OutputMessage msg)
{
    if (msg == m_channel.send(getHeader()))
        return true;
    else 
        return false;    
}

template <typename TChannel>
bool receiveMessage(InputMessage msg)
{   
    if (msg == m_channel.receive(getHeader()))
        return true;
    else 
        return false;   
}