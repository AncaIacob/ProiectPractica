#ifndef OUTPUTMESSAGE_HPP
#define OUTPUTMESSAGE_HPP

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

class OutputMessage 
{
    public:
        template <typename TPayload>
        void OutputMessage(MessageType type);

        template <typename TPayload>
        void OutputMessage(MessageType type, TPayload payload);

        const vector<byte>& getHeader();
        const vector<byte>& getPayload();

    private:
        vector<byte> m_headerBuffer;
        vector<byte> m_payloadBuffer; 
};

#include "OutputMessage.tpp"

#endif //OUTPUTMESSAGE_HPP