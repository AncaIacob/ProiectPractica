#ifndef COMMUNICATIONCHANNEL_HPP
#define COMMUNICATIONCHANNEL_HPP

#include "InputChannel.hpp"
#include "OutputChannel.hpp"

#include <cstddef>

template <typename TChannel>
class CommunicationChannel
{
    public:
        CommunicationChannel(TChannel channel);

        bool sendMessage(OutputMessage msg);
        bool receiveMessage(InputMessage msg);

    private:
        TChannel m_channel;
};

#include "CommunicationChannel.tpp"

#endif //COMMUNICATIONCHANNEL_HPP