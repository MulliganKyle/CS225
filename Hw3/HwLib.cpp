//////////////////////
// CS225
// HW3
// 2/5/15
// Kyle Mulligan
// Functions for Hw2 
//////////////////////
#include "MediaItem.hpp"
#include "HwLib.hpp"
#include "Element.hpp"
#include "Author.hpp"
#include <iostream>



extern bool done;
extern int currentItemNumber;
extern MediaItem *firstItem;
extern MediaItem *currentItem;
extern Author *authPtr;
extern Author *firstAuthor;

void printMenu()
{
   std::cout << "* - Display data for all Media Items" <<std::endl;
   std::cout << "+/- Increment / decrement the selected Item w/ in the Array" <<std::endl;
   std::cout << "# - Set the selected media Item" <<std::endl;
   std::cout << "0 - Clear MediaItem data" <<std::endl;
   std::cout << "C - Create author" <<std::endl;
   std::cout << "D - Display Media Item data" <<std::endl;
   std::cout << "N - Set Media Item name" <<std::endl;
   std::cout << "T - Set Media Item Author Index" <<std::endl;
   std::cout << "E - Add Media Item Element" <<std::endl;
   std::cout << "P - Set Media Item pages" <<std::endl;
   std::cout << "I - Set Media Item in print status (0/1)" <<std::endl;
   std::cout << "V - Set Media Item value" <<std::endl;
   std::cout << "Y - Set Media Item Year Produced" << std::endl;
   std::cout << "S - Set Media Item Sequel from Index" << std::endl;
   std::cout << "R - Display the Memory used" << std::endl;
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
	 for(count=0;count<MAX_ITEMS;count++)
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
	 std::cout << "The number of Items in Memory is: " << currentItem->getNumberOfObjects() << std::endl;
      }
      break;


      case '+':
      {
	 if(currentItemNumber==(MAX_ITEMS-1))
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

      case 'C':// creates new author
      {
      int date;
      std::string author;
      int authorIndex;

	 for(authorIndex=0; (authorIndex<MAX_AUTHORS); authorIndex++)
	 {
	    if( (firstAuthor+authorIndex)->isAuthorEmpty() )
	    {
	       std::cout << "Enter date Born";
	       std::cin >> date;
	       (firstAuthor+authorIndex)->setBorn(date);

	       std::cout << "Enter date Died (0 if still alive)";
	       std::cin >> date;
	       (firstAuthor+authorIndex)->setDied(date);

	       std::cout<< "Enter the author's name: ";
	       std::getline(std::cin,author);
	       (firstAuthor+authorIndex)->setName(author);

	       break;
	    }
	 }
      }
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

      case 'T': // enters the author index of media item
      {
      int index;
      std::cout << "Enter the index of the Author: ";
      std::cin >> index;
      currentItem->setAuthor(firstAuthor+index);
      }
      break;

      case 'E':
      {
      int startElement, endElement;
      std::string nameElement;

      std::cout << "Enter the start of the Element: ";
      std::cin >> startElement;

      std::cout << "Enter the end of the Element: ";
      std::cin >> endElement;

      std::cout << "Enter the name of the Element: ";
      std::getline(std::cin, nameElement);

      currentItem->addNewElement(startElement, endElement, nameElement);

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


      case 'Y':
      {


      }
      break;

      case 'S':
      {


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
