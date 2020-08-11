#include "InputMessage.hpp"
#include "MessageHeader.hpp"

#include <vector>
#include <cstddef>

using std::byte;
using std::vector;

InputMessage::InputMessage(const vector<byte>& headerBuffer)
{
    m_header = headerBuffer;
}

MessageType InputMessage::getType()
{
    return m_header;
}

void InputMessage::setPayload(const vector<byte>& payloadBuffer)
{
     m_payloadBuffer = payloadBuffer;   
}

template <typename TPayload>
TPayload InputMessage::getPayload()
{
    TPayload obj;
    obj.deserialize(m_payloadBuffer);

    return obj;
}