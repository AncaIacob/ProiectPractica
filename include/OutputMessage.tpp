#include "OutputMessage.hpp"

#include <cstddef>
#include <vector>

using std::vector;
using std::byte;

template <typename TPayload>
OutputMessage::OutputMessage(MessageType type)
{        
    MessageHeader(type, m_payloadBuffer.size()).serialize(m_headerBuffer);
}

template <typename THeader, typename TPayload>
OutputMessage::OutputMessage(const THeader& header, const TPayload& payload)
{   
    header.serialize(m_headerBuffer);     
    payload.serialize(m_payloadBuffer);
}

const vector<byte>& OutputMessage::getHeader() const
{
    return m_headerBuffer;
}

const vector<byte>& OutputMessage::getPayload() const
{
    return m_payloadBuffer;
}

