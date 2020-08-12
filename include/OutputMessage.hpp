#ifndef OUTPUTMESSAGE_HPP
#define OUTPUTMESSAGE_HPP

#include <cstddef>
#include <vector>

using std::byte;
using std::vector;

enum MessageType
{
    Invalid,
    Register,
    Login,
    Query,
    Deposit,
    Withdraw,
    End
};

class OutputMessage 
{
    public:
        template <typename TPayload>
        OutputMessage(MessageType type);

        template <typename THeader, typename TPayload>
        OutputMessage(const THeader& header, const TPayload& payload);

        const vector<byte>& getHeader() const;
        const vector<byte>& getPayload() const;

    private:
        vector<byte> m_headerBuffer;
        vector<byte> m_payloadBuffer; 
};

#include "OutputMessage.tpp"

#endif //OUTPUTMESSAGE_HPP