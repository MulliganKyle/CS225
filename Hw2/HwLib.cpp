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
extern int currentItemNumber;
extern mediaItem *firstItem;
extern mediaItem *currentItem;


void printMenu()
{
   std::cout << "* - Displa data for all Media Items" <<std::endl;
   std::cout << "+/- Increment / decrement the selected Item w/ in the Array" <<std::endl;
   std::cout << "# - Set the selected media Item" <<std::endl;
   std::cout << "0 - Clear MediaItem data" <<std::endl;
   std::cout << "D - Display Media Item data" <<std::endl;
   std::cout << "N - Set Media Item name" <<std::endl;
   std::cout << "A - Set Media Item author" <<std::endl;
   std::cout << "P - Set Media Item pages" <<std::endl;
   std::cout << "I - Set Media Item in print status (0/1)" <<std::endl;
   std::cout << "V - Set Media Item value" <<std::endl;
   std::cout << "M - Print this menu again" <<std::endl;
   std::cout << "Q - Quit this program" <<std::endl;
}

void processMenuIn(char menuIn)
{
   switch(toupper(menuIn))  //handles all menu options and works for upper or lower case inputs
   {

      case '*':
      {
	 int count;

	 std::cout << std::endl << "=== All Items ===" << std::endl;
	 for(count=0;count<20;count++)
	 {
	    if ( (firstItem[count]).isEmpty() )
	    {
	       std::cout << "mediaItem[" << count << "]: is Empty" << std::endl;
	    }
	    else
	    {
	    std::cout << "mediaItem[" << count << "]" << std::endl;
	    std::cout << (firstItem[count]);
	    }

	 }
      }
      break;


      case '+':
      {
	 if(currentItemNumber==19)
	    std::cout << "At the last item already." << std::endl;
	 else
	 {
	    currentItemNumber++;
	    currentItem++;
	    std::cout << "Index set to " << currentItemNumber << std::endl;
	 }
      }
      break;


      case '-':
       {
	 if(currentItemNumber==0)
	    std::cout << "At the first item already." << std::endl;
	 else
	 {
	    currentItemNumber--;
	    currentItem--;
	    std::cout << "Index set to " << currentItemNumber << std::endl;
	 }
      }     
      break;


      case '#':
      {
	 int number;
	 std::cout << "Enter the number of the Item: ";
	 std::cin >> number;

	 if( (number < 0) || (number >19) )
	    std::cout << "That is out of range." << std::endl;
	 else
	 {
	    currentItemNumber=number;
	    currentItem=firstItem+number;
	    std::cout << "Index set to " << currentItemNumber << std::endl;
	 }
      }
      break;


      case '0': //clears the media item
      currentItem->clearObject();
      break;


      case 'D': //prints the media item
      std::cout<<(*currentItem);
      break;


      case 'N': // enters the name of media item
      {
	 std::string name;
	 std::cout << "Enter the book's Name: ";
	 std::getline(std::cin,name);
	 currentItem->setName(name);
      }
      break;

      case 'A': // enters the author of media item
      {
	 std::string author;
	 std::cout << "Enter the author's Name: ";
	 std::getline(std::cin,author);
	 currentItem->setAuthor(author);
      }
      break;

      case 'P': // enters the number of pages for the media item
      {
	 int pages;
	 std::cout << "Enter the number of Pages: ";
	 std::cin >> pages;
	 currentItem->setNumberOfPages(pages);
      }
      break;


      case 'I':
      {
	 bool isInPrint;
	 std::cout << "Enter wether or not the item is in print (0/1) ";
	 std::cin >> isInPrint;
	 currentItem->setInPrint(isInPrint);
      }
      break;


      case 'V':
      {
	 float value;
	 std::cout << "Enter the value: ";
	 std::cin >> value;
	 currentItem->setValue(value);
      }
      break;


      case 'M': //prints the menu again
      printMenu();
      break;

      case 'Q': // exits the menu
      done= true;
      break;
   }
}
