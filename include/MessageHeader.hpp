#ifndef MESSAGEHEADER_HPP
#define MESSAGEHEADER_HPP
#include "MessageHeader.hpp"
#include "MessageType.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

class MessageHeader
{
    
   public:
   MessageHeader();
   MessageHeader(  MessageType type, std::size_t size);

   MessageType getType();
   size_t getPayload();

   void serialize(int value,std::vector<std::byte>& buffer);
   void deserialize(int& value, const std::vector<std::byte>& buffer);
    
    private:
    MessageType m_type;
    std::size_t m_payloadSize;

};

#include "MessageHeader.cpp"
#endif /* MESSAGEHEADER_HPP */
