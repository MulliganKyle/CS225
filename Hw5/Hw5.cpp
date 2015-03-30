//////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// menu based program which utilizes class mediaItem 
//////////////////////

#include <iostream>
#include <vector>
#include "HwLib.hpp"
#include "MediaItem.hpp"
#include "Author.hpp"
#include "Element.hpp"


//globals
//
MediaItem *currentItem;
bool done=false;
std::vector<MediaItem*> itemVector;
std::vector<Author*> authorVector;


int main()
{
   std::string userInput;

   
   printMenu();
   std::cout<<std::endl<<"Menu[-] : ";
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
