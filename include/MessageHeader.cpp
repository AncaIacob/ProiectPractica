#include "MessageHeader.hpp"
#include<iostream>
MessageHeader::MessageHeader()
{

}
MessageHeader::MessageHeader( MessageType type, std::size_t size)
{

}
 MessageType MessageHeader::getType()
 { 
    return m_type;
 }
  size_t MessageHeader::getPayload()
  {
     return m_payloadSize;
  }
  void MessageHeader::serialize(int value, std::vector<std::byte>& buffer)
  {
      buffer.push_back(static_cast<std::byte>(value >> 24));
      buffer.push_back(static_cast<std::byte>((value >> 16) & 0xFF));
      buffer.push_back(static_cast<std::byte>((value >> 8) & 0xFF));
      buffer.push_back(static_cast<std::byte>(value & 0xFF));

  }
  void MessageHeader::deserialize(int& value , const std::vector<std::byte>& buffer)
  {
      value = static_cast<int>(buffer[0]);
      value <<= 8;
      value = static_cast<int>(buffer[1]);
      value <<= 8;
      value = static_cast<int>(buffer[2]);
      value <<= 8;
      value = static_cast<int>(buffer[3]);
      value <<= 8;


  }
