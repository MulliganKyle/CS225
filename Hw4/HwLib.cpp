//////////////////////
// CS225
// HW4
// 3/6/15
// Kyle Mulligan
// Functions for Hw4 
//////////////////////
#include "MediaItem.hpp"
#include "HwLib.hpp"
#include "Element.hpp"
#include "Author.hpp"
#include "Book.hpp"
#include "Music.hpp"
#include "Video.hpp"
#include <iostream>
#include <typeinfo>



extern bool done;
extern MediaItem *currentItem;
extern Author *firstAuthor;
extern MediaItem *mixedArray[ARR_MAX];

void printMenu()
{
   std::cout << "0-19 : Books" <<std::endl<<"20-39 : Music" <<std::endl << "40-59 : Videos" <<std::endl << "60-79 : Media Items" << std::endl;
   std::cout << "* - Display data for all Media Items" <<std::endl;
   std::cout << "+/- Increment / decrement the selected Item w/ in the Array" <<std::endl;
   std::cout << "# - Set the selected media Item" <<std::endl;
   std::cout << "0 - Clear MediaItem data" <<std::endl;
   std::cout << "B - set Media Item duration/time" << std::endl;
   std::cout << "C - Create author" <<std::endl;
   std::cout << "D - Display Media Item data" <<std::endl;
   std::cout << "E - Add Media Item Element" <<std::endl;
   std::cout << "F - Set Music/Video Producer/Director respectively" <<std::endl;
   std::cout << "I - Set Media Item in print status (0/1)" <<std::endl;
   std::cout << "J - Set Book ISBN" << std::endl;
   std::cout << "K - set Music Genre" << std::endl;
   std::cout << "L - Display Music Items by Genre" << std::endl;
   std::cout << "M - Print this menu again" <<std::endl;
   std::cout << "N - Set Media Item name" <<std::endl;
   std::cout << "Q - Quit this program" <<std::endl;
   std::cout << "P - Set Media Item pages" <<std::endl;
   std::cout << "R - Display the Memory used" << std::endl;
   std::cout << "S - Set Media Item Sequel from Index" << std::endl;
   std::cout << "T - Set Media Item Author Index" <<std::endl;
   std::cout << "V - Set Media Item value" <<std::endl;
   std::cout << "Y - Set Media Item Year Produced" << std::endl;
}

void processMenuIn(char menuIn)
{
   static int currentItemNumber=0;
   switch(toupper(menuIn))  //handles all menu options and works for upper or lower case inputs
   {

      case '*': //prints everything
      {
	 int count;

	 std::cout << std::endl << "=== All Authors==="<< std::endl; // prints all authors
	 for( count=0; count< MAX_AUTHORS; count++)
	 {
	    if( !(firstAuthor[count].isAuthorEmpty() ) )
	    {
	       std::cout<< "Author[" << count << "]" << std::endl;
	       std::cout<< (firstAuthor[count]);
	    }
	 }


	 std::cout << std::endl << "=== All Items ===" << std::endl; // prints all items and their elements
	 for(count=0;count<ARR_MAX;count++)
	 {
	    if ( !(mixedArray[count])->isEmpty() )
	    {
	       std::cout << "mediaItem[" << count << "]" << std::endl;
	       (mixedArray[count])->toCout();
	    }

	 }
      }
      break;


      case '+':
      {
	 if(currentItemNumber==(ARR_MAX-1))
	    std::cout << "At the last item already." << std::endl;
	 else
	 {
	    currentItemNumber++;
	    currentItem=mixedArray[currentItemNumber];
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
	    currentItem=mixedArray[currentItemNumber];
	    std::cout << "Index set to " << currentItemNumber << std::endl;
	 }
      }     
      break;


      case '#':
      {
	 int number;
	 std::cout << "Enter the number of the Item: ";
	 std::cin >> number;

	 if( (number < 0) || (number >(ARR_MAX-1)) )
	    std::cout << "That is out of range." << std::endl;
	 else
	 {
	    currentItemNumber=number;
	    currentItem=mixedArray[currentItemNumber];
	    std::cout << "Index set to " << currentItemNumber << std::endl;
	 }
      }
      break;


      case '0': //clears the media item
      currentItem->clearObject();
      break;

      case 'B': //set mediaItem duration/time
      {
	 if( typeid(*currentItem)==typeid(Music) )
	 {
	    float time;
	    std::cout << "Enter the duration of the Item: ";
	    std::cin >> time;

	    if(time>0)
	    {
	       ((Music*)currentItem)->setMinutes(time);
	    }
	    else
	    std::cout << "invalid duration."<<std::endl;
	 }
	 else if( typeid(*currentItem)==typeid(Video) )
	 {
	    float time;
	    std::cout << "Enter the duration of the Item: ";
	    std::cin >> time;

	    if(time>0)
	    {
	       ((Video*)currentItem)->setMinutes(time);
	    }
	    else
	    std::cout << "invalid duration."<<std::endl;
	 }
	 else
	 std::cout << "This mediaItem doesn't have a duration."<<std::endl;


      }
      break;


      case 'C':// creates new author
      {
      int dateBorn, dateDied;
      std::string author;
      int authorIndex;

	 for(authorIndex=0; (authorIndex<MAX_AUTHORS); authorIndex++)
	 {
	    if( (firstAuthor+authorIndex)->isAuthorEmpty() )
	    {
	       std::cout << "Enter date Born ";
	       std::cin >> dateBorn;

	       std::cout << "Enter date Died (0 if still alive) ";
	       std::cin >> dateDied;
	       std::cin.ignore();

	       std::cout<< "Enter the author's name: ";
	       std::getline(std::cin,author);

	       if( dateDied!=0 && dateDied<dateBorn)
		  std::cout << "invalid birth and death dates " <<std::endl;
	       else
	       {
		  (firstAuthor+authorIndex)->setBorn(dateBorn);
		  (firstAuthor+authorIndex)->setDied(dateDied);
		  (firstAuthor+authorIndex)->setName(author);
	       }

	       break;
	    }
	 }
      }
      break;


      case 'D': //prints the media item
      currentItem->toCout();
      break;

      case 'E': // creates a new element
      {
	 int startElement, endElement;
	 std::string nameElement;

	 std::cout << "Enter the start of the Element: ";
	 std::cin >> startElement;

	 std::cout << "Enter the end of the Element: ";
	 std::cin >> endElement;
	 std::cin.ignore();

	 std::cout << "Enter the name of the Element: ";
	 std::getline(std::cin, nameElement);

      currentItem->addNewElement(startElement, endElement, nameElement);

      }
      break;


      case 'F': //sets music/video producer/director respectively
      {
	 if( typeid(*currentItem)==typeid(Music) )
	 {
	    std::string producerName;
	    std::cout<< "Enter the music's producer: ";
	    std::getline(std::cin,producerName);
	    ((Music*)currentItem)->setProducer(producerName);
	 }
	 else if (typeid(*currentItem)==typeid(Video))
	 {
	    std::string directorName;
	    std::cout << "Enter the video's director: ";
	    std::getline(std::cin,directorName);
	    ((Video*)currentItem)->setDirector(directorName);
	 }
	 else
	    std::cout << "this item doesn't have a producer or director"<<std::endl;


      }
      break;

      case 'J': //set book ISBN
      {
	 if(typeid(*currentItem)==typeid(Book))
	 {
	    std::string bookISBN;
	    std::cout << "Enter the book's ISBN: ";
	    std::getline(std::cin,bookISBN);
	    ((Book*)currentItem)->setISBN(bookISBN);
	 }
	 else
	    std::cout<< "This Item doesn't have an ISBN."<<std::endl;
      }
      break;

      case 'K': //set Music Genre
      {
	 if(typeid(*currentItem)==typeid(Music))
	 {
	    std::string theGenre;
	    std::cout<< "Enter the Music's Genre: ";
	    std::getline(std::cin,theGenre);
	    ((Music*)currentItem)->setGenre(theGenre);
	 }
	 else
	    std::cout<< "This Item is not Music."<<std::endl;

      }
      break;

      case 'L': //Display Music Items by Genre
      {
	 int iterator;

	 std::cout<<std::endl<< std::endl << "=====Music By Genre=====" <<std::endl<<std::endl;
	 for(iterator=0; iterator<7; iterator++)
	 {
	    int count;
	    for(count=20; count<40; count++)
	    {
	       if( (!(mixedArray[count])->isEmpty()) && ((Music*)mixedArray[count])->getGenre()==iterator)
		  (mixedArray[count])->toCout();
	    }
	 }

      }
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


      case 'P': // enters the number of pages for the media item
      {
	 if(typeid(*currentItem)==typeid(Book))
	 {
	    int pages;
	    std::cout << "Enter the number of Pages: ";
	    std::cin >> pages;
	    ((Book*)currentItem)->setPages(pages);
	 }
	 else
	    std::cout << "This item doesn't have pages. " <<std::endl;
      }
      break;


      case 'I': // sets whether the item is in print
      {
	 if(typeid(*currentItem)==typeid(Book))
	 {
	    bool isInPrint;
	    std::cout << "Enter wether or not the item is in print (0/1) ";
	    std::cin >> isInPrint;
	    ((Book*)currentItem)->setInPrint(isInPrint);
	 }
	 else
	    std::cout << "This item is not a book. "<<std::endl;
      }
      break;


      case 'V': // sets the value of the item
      {
	 float value;
	 std::cout << "Enter the value: ";
	 std::cin >> value;
	 currentItem->setValue(value);
      }
      break;


      case 'Y': // sets the year of publication
      {
	 int year;
	 std::cout << "Enter the year of publication: ";
	 std::cin >> year;

	 if( year<0 || year>2016)
	    std::cout << "Not a valid year" << std::endl;
	 else
	    currentItem->setYearOfPublication(year);

      }
      break;

      case 'S': // sets the sequel of the item
      {
	 if (typeid(*currentItem)==typeid(Video))
	 {
	    int index;
	    std::cout << "Enter the index of the Sequel: ";
	    std::cin >> index;

	    if(index>=MAX_ITEMS || index < 0)
	       std::cout << "Index out of bounds" << std::endl;
	    else
	       ((Video*)currentItem)->setSequel(mixedArray[index]);
	 }
	 else if (typeid(*currentItem)==typeid(Book))
	 {
	    int index;
	    std::cout << "Enter the index of the Sequel: ";
	    std::cin >> index;

	    if(index>=MAX_ITEMS || index < 0)
	       std::cout << "Index out of bounds" << std::endl;
	    else
	       ((Book*)currentItem)->setSequel(mixedArray[index]);
	 }
	 else
	    std::cout<< "this item is not a book or video. ";
      }
      break;

      case 'R': //displays the memory usage
      {

	 std::cout<<std::endl;
	 std::cout<< "Authors in memory    = " << (firstAuthor->getNumberOfAuthors()) << " @ " << sizeof(Author) << " Bytes EA. " << std::endl;
	 std::cout<< "               bytes = " << ((firstAuthor->getNumberOfAuthors())* sizeof(Author)) << std::endl;

	 std::cout<< "Books in memory      = " << (((Book*)mixedArray[0])->getNumberOfBooks()) << " @ " << sizeof(Book) << " Bytes EA. " << std::endl;
	 std::cout<< "               bytes = " << (( ((Book*)mixedArray[0])->getNumberOfBooks())* sizeof(Book)) << std::endl;

	 std::cout<< "Music in memory      = " << (((Music*)mixedArray[20])->getNumberOfMusics()) << " @ " << sizeof(Music) << " Bytes EA. " << std::endl;
	 std::cout<< "               bytes = " << ((((Music*)mixedArray[20])->getNumberOfMusics())* sizeof(Music)) << std::endl;

	 std::cout<< "Videos in memory     = " << (((Video*)mixedArray[40])->getNumberOfVideos()) << " @ " << sizeof(Video) << " Bytes EA. " << std::endl;
	 std::cout<< "               bytes = " << ((((Video*)mixedArray[40])->getNumberOfVideos())* sizeof(Video)) << std::endl;

	 std::cout<< "MediaItems in memory = " << ((mixedArray[60])->getNumberOfObjects()) << " @ " << sizeof(MediaItem) << " Bytes EA. " << std::endl;
	 std::cout<< "               bytes = " << (((mixedArray[60])->getNumberOfObjects())* sizeof(MediaItem)) << std::endl;

	 std::cout << "        Total bytes = " << ( ((firstAuthor->getNumberOfAuthors())* sizeof(Author)) + (( ((Book*)mixedArray[0])->getNumberOfBooks())* sizeof(Book)) + ((((Music*)mixedArray[20])->getNumberOfMusics())* sizeof(Music)) + ((((Video*)mixedArray[40])->getNumberOfVideos())* sizeof(Video)) + (( ((mixedArray[60])->getNumberOfObjects()) - ((((Video*)mixedArray[40])->getNumberOfVideos()) + (((Music*)mixedArray[20])->getNumberOfMusics()) + ( ((Book*)mixedArray[0])->getNumberOfBooks())) )* sizeof(MediaItem) ) )<< std::endl;

      }
      break;


      case 'M': //prints the menu again
      printMenu();
      break;

      case 'Q': // exits the menu
      done= true;
      break;


      default:
	 std::cout << std::endl << "NOT A VALID INPUT" << std::endl;
   }
   std::cout<<std::endl<<"Menu["<<currentItemNumber<<"] : ";
}




int initMixedArray()
{
   int count;


   for(count=0; count<ARR_MAX; count++)
   {
      int type= (count/PER_GROUP);

      switch (type)
      {
	 case 0:
	    mixedArray[count] = new Book();
	 break;

	 case 1:
	    mixedArray[count] = new Music();
	 break;

	 case 2:
	    mixedArray[count] = new Video();
	 break;

	 case 3:
	    mixedArray[count] = new MediaItem();
	 break;

	 default:
	    std::cout <<"ERROR: in array initialize" << std::endl;
	    return -1;
      }
   }
   return 0;
}
