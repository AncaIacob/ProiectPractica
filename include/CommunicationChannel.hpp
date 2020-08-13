#ifndef COMMUNICATIONCHANNEL_HPP
#define COMMUNICATIONCHANNEL_HPP

#include "InputMessage.hpp"
#include "OutputMessage.hpp"

#include <cstddef>

template <typename TChannel>
class CommunicationChannel
{
    public:
        CommunicationChannel(TChannel channel);

        bool sendMessage(OutputMessage msg);
        InputMessage receiveMessage();

    private:
        TChannel m_channel;
};

#include "CommunicationChannel.tpp"

#endif //COMMUNICATIONCHANNEL_HPP