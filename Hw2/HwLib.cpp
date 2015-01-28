//////////////////////
// CS225
// HW1
// 1/22/15
// Kyle Mulligan
// Functions for Hw1 
//////////////////////
#include "mediaItem.hpp"
#include <iostream>

extern bool done;
extern mediaItem book1;

void printMenu()
{
   std::cout << "0 - Clear MediaItem data" <<std::endl;
   std::cout << "D - Display Media Item data" <<std::endl;
   std::cout << "R - Print this menu again" <<std::endl;
   std::cout << "N - Set Media Item name" <<std::endl;
   std::cout << "A - Set Media Item author" <<std::endl;
   std::cout << "P - Set Media Item pages" <<std::endl;
   std::cout << "Q - Quit this program" <<std::endl;
}

void processMenuIn(char menuIn)
{
   switch(toupper(menuIn))  //handles all menu options and works for upper or lower case inputs
   {
      case '0': //clears the media item
	 book1.setName("");
	 book1.setAuthor("");
	 book1.setNumberOfPages(0);
	 break;


      case 'D': //prints the media item
	 std::cout<<book1;
	 
	 break;


      case 'R': //prints the menu again
	 printMenu();
	 break;


      case 'N': // enters the name of media item
      {
	 std::string name;
	 std::cout << "Enter the book's Name: ";
	 std::getline(std::cin,name);
	 book1.setName(name);
      }
      break;

      case 'A': // enters the author of media item
      {
	 std::string author;
	 std::cout << "Enter the author's Name: ";
	 std::getline(std::cin,author);
	 book1.setAuthor(author);
      }
      break;

      case 'P': // enters the number of pages for the media item
      {
	 int pages;
	 std::cout << "Enter the number of Pages: ";
	 std::cin >> pages;
	 book1.setNumberOfPages(pages);
      }
      break;

      case 'Q': // exits the menu
	 done= true;
	 break;
   }
}
