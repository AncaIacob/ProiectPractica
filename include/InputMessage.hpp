#ifndef INPUTMESSAGE_HPP
#define INPUTMESSAGE_HPP

#include "MessageHeader.hpp"

#include <cstddef>
#include <vector>

using std::byte;
using std::vector;

enum MessageType
{
    Invalid,
    Data1,
    Data2,
    Data3,
    End
};

class InputMessage
{
    public:
        InputMessage(const vector<byte>& headerBuffer);
        
        MessageType getType();
        void setPayload(const vector<byte>& payloadBuffer);

        template <typename TPayload>
        TPayload getPayload();

    private:
        MessageHeader m_header;
        vector<byte> m_payloadBuffer;    
};

#include "InputMessage.tpp"

#endif //INPUTMESSAGE_HPP