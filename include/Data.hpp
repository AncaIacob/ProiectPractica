#ifndef DATA_HPP
#define DATA_HPP
#include "Data.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
 class Data
 {
  public:

   Data(std::string data);

   void serialize(int value,std::vector<std::byte>& buffer);
   void deserialize(int& value, const std::vector<std::byte>& buffer);

   private:
   std::string m_data;


 };


#include "Data.cpp"
#endif /* DATA_HPP */
