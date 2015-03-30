//////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Functions for Hw5
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
#include <vector>
#include <algorithm>



extern bool done;
extern std::vector<MediaItem*> itemVector;
extern std::vector<Author*> authorVector;

//compare function, recieves two mediaItem pointers
//compares the two names of the mediaItems. returns a boolean
//meant to be used as an argument to the std::sort function.
bool compareItemNames(MediaItem *item1, MediaItem *item2)
{
      return ( item1->getName() < item2->getName() );
}

//recieves no arguments and returns no values,
//prints the menu of options
void printMenu()
{
   std::cout << "+ - Create & Select new MediaItem of [B,M,V,*] types" <<std::endl;
   std::cout << "- - Delete selected MediaItem" <<std::endl;
   std::cout << "* - Display data for all Media Items" <<std::endl;
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
   std::cout << "U - Sort MediaItem Aggregation by Name" <<std::endl;
   std::cout << "V - Set Media Item value" <<std::endl;
   std::cout << "Y - Set Media Item Year Produced" << std::endl;
}






//processMenuIn recieves a single character, if it is a character from the menu above,
//handles the option and returns nothing. If not a character from the menu above, indicates
//invalid character and does nothing
//no return value
void processMenuIn(char menuIn)
{
   static int currentItemNumber=-1;
   switch(toupper(menuIn))  //handles all menu options and works for upper or lower case inputs
   {

      case '*': //prints everything
      {
	 int count=0;

	 std::cout << std::endl << "=== All Authors==="<< std::endl; // prints all authors
	 for( Author *auth: authorVector)
	 {
	    if( !(auth->isAuthorEmpty() ) )
	    {
	       std::cout<< "Author[" << count << "]" << std::endl;
	       std::cout<< (*auth);
	       count++;
	    }
	 }

	 count=0;
	 std::cout << std::endl << "=== All Items ===" << std::endl; // prints all items and their elements
	 for( MediaItem *item : itemVector)
	 {
	    if ( !(item->isEmpty() ))
	    {
	       std::cout << "mediaItem[" << count << "]" << std::endl;
	       (item)->toCout();
	       count++;
	    }

	 }
      }
      break;


      case '+':
      {
	 std::string newItemType;
	 std::cout<<"enter the type of item you wish to add [B,M,V,*]";
	 std::getline(std::cin,newItemType);
	 
	 if(newItemType.front()== 'B' || newItemType.front()=='b')
	 {
	    MediaItem *newItem= new Book();
	    itemVector.push_back(newItem);
	    currentItemNumber=itemVector.size()-1;
	 }
	 else if (newItemType.front()== 'M' || newItemType.front()=='m')
	 { 
	    MediaItem *newItem= new Music();
	    itemVector.push_back(newItem);
	    currentItemNumber=itemVector.size()-1;
	 }
	 else if (newItemType.front()== 'V' || newItemType.front()=='v')
	 { 
	    MediaItem *newItem= new Video();
	    itemVector.push_back(newItem);
	    currentItemNumber=itemVector.size()-1;
	 }
	 else
	 {
	    MediaItem *newItem= new MediaItem();
	    itemVector.push_back(newItem);
	    currentItemNumber=itemVector.size()-1;
	 }
      }
      break;


      case '-':
      {
	 for(MediaItem *item: itemVector)
	 {
	    if ( item->getSequel() == itemVector[currentItemNumber] )
	       item->setSequel(NULL);

	 }

	 delete itemVector[currentItemNumber];
	 itemVector.erase(itemVector.begin()+currentItemNumber);
	 currentItemNumber=-1;
      }     
      break;


      case '#':
      {
	 unsigned int number;
	 std::cout << "Enter the number of the Item: ";
	 std::cin >> number;

	 if( (number < 0) || (number > (itemVector.size()-1) ))
	    std::cout << "That is out of range." << std::endl;
	 else
	 {
	    currentItemNumber=number;
	    std::cout << "Index set to " << currentItemNumber << std::endl;
	 }
      }
      break;


      case '0': //clears the media item
      itemVector[currentItemNumber]->clearObject();
      break;

      case 'B': //set mediaItem duration/time
      {
	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 else if( typeid(*itemVector[currentItemNumber])==typeid(Music) )
	 {
	    float time;
	    std::cout << "Enter the duration of the Item: ";
	    std::cin >> time;

	    if(time>0)
	    {
	       ((Music*)itemVector[currentItemNumber])->setMinutes(time);
	    }
	    else
	    std::cout << "invalid duration."<<std::endl;
	 }
	 else if( typeid(*itemVector[currentItemNumber])==typeid(Video) )
	 {
	    float time;
	    std::cout << "Enter the duration of the Item: ";
	    std::cin >> time;

	    if(time>0)
	    {
	       ((Video*)itemVector[currentItemNumber])->setMinutes(time);
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
	 Author *newAuthor=new Author();

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
	    newAuthor->setBorn(dateBorn);
	    newAuthor->setDied(dateDied);
	    newAuthor->setName(author);
	 }
 	 authorVector.push_back(newAuthor);
      }
      break;


      case 'D': //prints the media item
      {
	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 else
	 {
	    itemVector[currentItemNumber]->toCout();
	 }
      }
      break;

      case 'E': // creates a new element
      {
	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 else
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

	    itemVector[currentItemNumber]->addNewElement(startElement, endElement, nameElement);
	 }

      }
      break;


      case 'F': //sets music/video producer/director respectively
      {
 	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }     
	 else if( typeid(*(itemVector[currentItemNumber]))==typeid(Music) )
	 {
	    std::string producerName;
	    std::cout<< "Enter the music's producer: ";
	    std::getline(std::cin,producerName);
	    ((Music*)itemVector[currentItemNumber])->setProducer(producerName);
	 }
	 else if (typeid(*(itemVector[currentItemNumber]))==typeid(Video))
	 {
	    std::string directorName;
	    std::cout << "Enter the video's director: ";
	    std::getline(std::cin,directorName);
	    ((Video*)itemVector[currentItemNumber])->setDirector(directorName);
	 }
	 else
	    std::cout << "this item doesn't have a producer or director"<<std::endl;


      }
      break;

      case 'J': //set book ISBN
      {
	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 else if(typeid(*(itemVector[currentItemNumber]))==typeid(Book))
	 {
	    std::string bookISBN;
	    std::cout << "Enter the book's ISBN: ";
	    std::getline(std::cin,bookISBN);
	    ((Book*)itemVector[currentItemNumber])->setISBN(bookISBN);
	 }
	 else
	    std::cout<< "This Item doesn't have an ISBN."<<std::endl;
      }
      break;

      case 'K': //set Music Genre
      {
	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 else if(typeid(*(itemVector[currentItemNumber]))==typeid(Music))
	 {
	    std::string theGenre;
	    std::cout<< "Enter the Music's Genre: ";
	    std::getline(std::cin,theGenre);
	    ((Music*)itemVector[currentItemNumber])->setGenre(theGenre);
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
	    for(MediaItem *item : itemVector)
	    {
	       if( (typeid(*item)==typeid(Music)) && (!item->isEmpty()) && (((Music*)item)->getGenre()==iterator) )
		  item->toCout();
	    }
	 }
      }
      break;


      case 'N': // enters the name of media item
      {
 	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 else
	 {
	    std::string name;
	    std::cout << "Enter the Item's Name: ";
	    std::getline(std::cin,name);
	    itemVector[currentItemNumber]->setName(name);
	 }
      }
      break;

      case 'T': // enters the author index of media item
      {
 	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 else
	 {
	    int index;
	    std::cout << "Enter the index of the Author: ";
	    std::cin >> index;
	    itemVector[currentItemNumber]->setAuthor(authorVector[index]);
	 }
      }
      break;


      case 'P': // enters the number of pages for the media item
      {
	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 else if (typeid(*(itemVector[currentItemNumber]))==typeid(Book))
	 {
	    int pages;
	    std::cout << "Enter the number of Pages: ";
	    std::cin >> pages;
	    ((Book*)itemVector[currentItemNumber])->setPages(pages);
	 }
	 else
	    std::cout << "This item doesn't have pages. " <<std::endl;
      }
      break;


      case 'I': // sets whether the item is in print
      {
	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 if(typeid(*(itemVector[currentItemNumber]))==typeid(Book))
	 {
	    bool isInPrint;
	    std::cout << "Enter wether or not the item is in print (0/1) ";
	    std::cin >> isInPrint;
	    ((Book*)itemVector[currentItemNumber])->setInPrint(isInPrint);
	 }
	 else
	    std::cout << "This item is not a book. "<<std::endl;
      }
      break;

      case 'U':
      {
	 std::cout<< std::endl << "=====Sorting Objects=====" << std::endl;
	 std::sort(itemVector.begin(), itemVector.end(), compareItemNames);
      }
      break;


      case 'V': // sets the value of the item
      {
	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 else
	 {
	    float value;
	    std::cout << "Enter the value: ";
	    std::cin >> value;
	    itemVector[currentItemNumber]->setValue(value);
	 }
      }
      break;


      case 'Y': // sets the year of publication
      {
	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 else
	 {
	    int year;
	    std::cout << "Enter the year of publication: ";
	    std::cin >> year;

	    if( year<0 || year>2016)
	       std::cout << "Not a valid year" << std::endl;
	    else
	       itemVector[currentItemNumber]->setYearOfPublication(year);
	 }

      }
      break;

      case 'S': // sets the sequel of the item
      {
	 if(currentItemNumber==-1)
	 {
	    std::cout << "No object selected"<< std::endl;
	 }
	 else if (typeid(*(itemVector[currentItemNumber]))==typeid(MediaItem))
	 {
	    int index;
	    std::cout << "Enter the index of the Sequel: ";
	    std::cin >> index;

	    if(index>=MAX_ITEMS || index < 0)
	       std::cout << "Index out of bounds" << std::endl;
	    else
	       ((Video*)itemVector[currentItemNumber])->setSequel(itemVector[index]);
	 }
	 else if (typeid(*(itemVector[currentItemNumber]))==typeid(Video))
	 {
	    int index;
	    std::cout << "Enter the index of the Sequel: ";
	    std::cin >> index;

	    if(index>=MAX_ITEMS || index < 0)
	       std::cout << "Index out of bounds" << std::endl;
	    else
	       ((Video*)itemVector[currentItemNumber])->setSequel(itemVector[index]);
	 }
	 else if (typeid(*itemVector[currentItemNumber])==typeid(Book))
	 {
	    int index;
	    std::cout << "Enter the index of the Sequel: ";
	    std::cin >> index;

	    if(index>=MAX_ITEMS || index < 0)
	       std::cout << "Index out of bounds" << std::endl;
	    else
	       ((Book*)itemVector[currentItemNumber])->setSequel(itemVector[index]);
	 }
	 else
	    std::cout<< "this item is not a book or video. ";
      }
      break;

      case 'R': //displays the memory usage
      {

	 std::cout<<std::endl;
	 std::cout<< "Authors in memory    = " << (Author::getNumberOfAuthors()) << " @ " << sizeof(Author) << " Bytes EA. " << std::endl;
	 std::cout<< "               bytes = " << ((Author::getNumberOfAuthors())* sizeof(Author)) << std::endl;

	 std::cout<< "Books in memory      = " << (Book::getNumberOfBooks()) << " @ " << sizeof(Book) << " Bytes EA. " << std::endl;
	 std::cout<< "               bytes = " << ( (Book::getNumberOfBooks())* sizeof(Book)) << std::endl;

	 std::cout<< "Music in memory      = " << (Music::getNumberOfMusics()) << " @ " << sizeof(Music) << " Bytes EA. " << std::endl;
	 std::cout<< "               bytes = " << ((Music::getNumberOfMusics())* sizeof(Music)) << std::endl;

	 std::cout<< "Videos in memory     = " << (Video::getNumberOfVideos()) << " @ " << sizeof(Video) << " Bytes EA. " << std::endl;
	 std::cout<< "               bytes = " << ((Video::getNumberOfVideos())* sizeof(Video)) << std::endl;

	 std::cout<< "Elements in memory   = " << (Element::getNumberOfElements()) << " @ " << sizeof(Element) << " Bytes EA. " << std::endl;
	 std::cout<< "               bytes = " << ((Element::getNumberOfElements())* sizeof(Element)) << std::endl;

	 std::cout<< "MediaItems in memory = " << (MediaItem::getNumberOfObjects()) << " @ " << sizeof(MediaItem) << " Bytes EA. " << std::endl;
	 std::cout<< "               bytes = " << ((MediaItem::getNumberOfObjects())* sizeof(MediaItem)) << std::endl;

	 std::cout << "        Total bytes = " << 
	 ( ((Author::getNumberOfAuthors())* sizeof(Author)) +
	 ( (Element::getNumberOfElements())*sizeof(Element)) +
	 ( (Book::getNumberOfBooks())* sizeof(Book)) + 
	 ((Music::getNumberOfMusics())* sizeof(Music)) + 
	 ((Video::getNumberOfVideos())* sizeof(Video)) + 
	 (( (MediaItem::getNumberOfObjects()) - 
	    ((Video::getNumberOfVideos()) + 
	    (Music::getNumberOfMusics()) + 
	    (Book::getNumberOfBooks())) )* sizeof(MediaItem) ) )<< std::endl;

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

   if (currentItemNumber==-1)
      std::cout<<std::endl<<"Menu[-] : ";
   else
      std::cout<<std::endl<<"Menu["<<currentItemNumber<<"] : ";
}



