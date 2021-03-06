//////////////////////
// CS225
// HW1
// 2/5/15
// Kyle Mulligan
// menu based program which utilizes class mediaItem 
//////////////////////

#include <iostream>
#include "HwLib.hpp"
#include "mediaItem.hpp"

#define MAX_ITEMS 20

//globals
//
mediaItem *firstItem;
mediaItem *currentItem;
bool done=false;
int currentItemNumber;

int main()
{
   std::string userInput;
   mediaItem mediaItems[MAX_ITEMS];
   
   firstItem=mediaItems;
   currentItem=firstItem;

   printMenu();
   while(!done) // loops until the user is done using the menu
   {
      std::cout << std::endl << "Menu[" << currentItemNumber << "] : ";
      std::cin >> userInput;
      std::cin.ignore();
      processMenuIn(userInput[0]);
   }
   std::cout << "Goodbye" << std::endl;
}
