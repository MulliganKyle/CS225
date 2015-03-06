//////////////////////
// CS225
// HW4
// 3/6/15
// Kyle Mulligan
// menu based program which utilizes class mediaItem 
//////////////////////

#include <iostream>
#include "HwLib.hpp"
#include "MediaItem.hpp"
#include "Author.hpp"
#include "Element.hpp"


//globals
//
MediaItem *currentItem;
Author *firstAuthor;
bool done=false;
MediaItem *mixedArray[ARR_MAX];

int main()
{
   std::string userInput;
   initMixedArray();
   Author authors[MAX_AUTHORS];

   currentItem=mixedArray[0];
   firstAuthor=authors;

   
   printMenu();
   std::cout<<std::endl<<"Menu[0] : ";
   while(!done) // loops until the user is done using the menu
   {
      std::cin >> userInput;
      if(userInput[0]=='/')
	 std::cin.ignore(256,'\n');
      else
      {
	 std::cin.ignore();
	 processMenuIn(userInput[0]);
      }
   }
   std::cout << "Goodbye" << std::endl;
}
