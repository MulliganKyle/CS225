//////////////////////
// CS225
// HW1
// 1/22/15
// Kyle Mulligan
// menu based program which utilizes class mediaItem 
//////////////////////

#include <iostream>
#include "HwLib.hpp"
#include "mediaItem.hpp"


mediaItem book1;
bool done=false;

int main()
{
   std::string userInput;


   printMenu();
   while(!done) // loops until the user is done using the menu
   {
      std::cout << std::endl << "Menu : ";
      std::cin >> userInput;
      std::cin.ignore(256,'\n');
      processMenuIn(userInput[0]);
   }
   std::cout << "Goodbye" << std::endl;
}
