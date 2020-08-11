#include "OutputMessage.hpp"

#include <cstddef>
#include <vector>

using std::vector;
using std::byte;

template <typename TPayload>
void OutputMessage(MessageType type)
{        
    MessageHeader(type, m_payloadBuffer.size()).serialize(m_headerBuffer);
}

template <typename TPayload>
void OutputMessage(MessageType type, const TPayload& payload)
{        
    payload.serialize(m_payloadBuffer);
}

const vector<byte>& getHeader()
{
    return m_headerBuffer;
}

const vector<byte>& getPayload()
{
    return m_payloadBuffer;
}

