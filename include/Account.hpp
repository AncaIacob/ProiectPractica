#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include "Account.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

 class Account
 {
  public:

   Account(std::string name, std::string password);

   std::string getName();
   std::string getPassword();
   double getBalance();

   bool deposit(double sum);
   bool withdraw(double sum);


   void serialize(int value,std::vector<std::byte>& buffer);
   void deserialize(int& value, const std::vector<std::byte>& buffer);

   private:
   std::string m_name;
   std::string m_password;
   double balance;

 };


#include "Account.cpp"
#endif /* DATA_HPP */
