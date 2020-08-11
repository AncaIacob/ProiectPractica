#include<iostream>
#include "Data.hpp"

Data::Data(std::string data)
{

}
 void Data::serialize(int value, std::vector<std::byte>& buffer)
  {
      buffer.push_back(static_cast<std::byte>(value >> 24));
      buffer.push_back(static_cast<std::byte>((value >> 16) & 0xFF));
      buffer.push_back(static_cast<std::byte>((value >> 8) & 0xFF));
      buffer.push_back(static_cast<std::byte>(value & 0xFF));

  }
  void Data::deserialize(int& value , const std::vector<std::byte>& buffer)
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
