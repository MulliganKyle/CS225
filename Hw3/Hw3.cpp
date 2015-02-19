//////////////////////
// CS225
// HW3
// 2/5/15
// Kyle Mulligan
// menu based program which utilizes class mediaItem 
//////////////////////

#include <iostream>
#include "HwLib.hpp"
#include "MediaItem.hpp"



//globals
//
MediaItem *firstItem;
MediaItem *currentItem;
Author *authPtr;
bool done=false;
int currentItemNumber;

int main()
{
   std::string userInput;
   MediaItem mediaItems[MAX_ITEMS];
   Author authors[MAX_AUTHORS];

   firstItem=mediaItems;
   currentItem=firstItem;
   authPtr=authors;


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