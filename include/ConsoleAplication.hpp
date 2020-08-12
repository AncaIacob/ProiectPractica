#ifndef CONSOLEAPLICATION_HPP
#define CONSOLEAPLICATION_HPP
#include "ConsoleAplication.hpp"

class ConsoleAplication
{
   public:
   void run();

   private:
   void printMenu();

   void handleRegister();
   void handleLogin();
   
   void handleQuery();
   void handleDeposit();
   void handleWithdrawal();

   void handleExist();

};
#include "ConsoleAplication.cpp"
#endif /* CONSOLEAPLICATION_HPP */
