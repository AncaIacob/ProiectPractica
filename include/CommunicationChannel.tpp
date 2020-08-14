#include "CommunicationChannel.hpp"

#include <cstddef>
#include <vector>

using std::vector;

template <typename TChannel>
CommunicationChannel<TChannel>::CommunicationChannel(TChannel channel)
{
    m_channel = channel;
}

template <typename TChannel>
bool CommunicationChannel<TChannel>::sendMessage(OutputMessage msg)
{
    if ((msg.getHeader() == m_channel.send(getHeader())) && ((msg.getPayload() == m_channel.send(getPayload()))
        return true;
    else 
        return false;    
}

template <typename TChannel>
InputMessage CommunicationChannel<TChannel>::receiveMessage()
{   
    InputMessage msg;
    vector<byte> vecB;
    
    msg = m_channel.receive(vecB);
    return msg; 
}