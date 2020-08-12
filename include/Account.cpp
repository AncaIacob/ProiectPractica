#include<iostream>
#include "Account.hpp"

Account::Account(std::string name, std::string password)
{
 
 
}
   std::string Account::getName()
   {
      return m_name;
   }
   std::string Account::getPassword()
   {
       return m_password;
   }
   double Account::getBalance()
   {
         return balance;
   }

   bool deposit(double sum)
   {   std::cout<<"Enter the sum you want to deposit ";
       std::cin>>sum;
        balance= balance +sum;
   }
   bool withdraw(double sum)
   {   
       std::cout<<"Enter the sum you want to withdraw ";
       std::cin>>sum;
       
       if(sum <=  balance)
       {
           balance= balance - sum;
       }
       else
       std::cout<<"Less Balance ";
   }

 void Account::serialize(int value, std::vector<std::byte>& buffer)
  {
      buffer.push_back(static_cast<std::byte>(value >> 24));
      buffer.push_back(static_cast<std::byte>((value >> 16) & 0xFF));
      buffer.push_back(static_cast<std::byte>((value >> 8) & 0xFF));
      buffer.push_back(static_cast<std::byte>(value & 0xFF));

  }
  void Account::deserialize(int& value , const std::vector<std::byte>& buffer)
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
