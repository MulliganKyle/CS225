///////////////////////////////////
// CS225
// HW3
// 2/20/15
// Kyle Mulligan
// Implementation of mediaItem Class
///////////////////////////////////

#include <iostream>
#include <iomanip>
#include "MediaItem.hpp"


//class static attribute
//
int MediaItem::numberOfObjects=0;

//constructors
//
MediaItem::MediaItem(std::string newName,
		     int newNumberOfPages,
		     float newValue,
		     bool newInPrint,
		     Author* newAuthor,
		     MediaItem* newSequel,
		     int newYear)
{
   name=newName;
   numberOfPages=newNumberOfPages;
   value=newValue;
   inPrint=newInPrint;
   author=newAuthor;
   sequel=newSequel;
   yearOfPublication=newYear;
   numberOfObjects++;
}

//destructors
//
MediaItem::~MediaItem()
{
   numberOfObjects--;

}


//mutators
//
void MediaItem::setName(std::string newName)
{
   name=newName;
}

void MediaItem::setAuthor(Author *newAuthor)
{
   author=newAuthor;
}

void MediaItem::setNumberOfPages(int newNumberOfPages)
{
   numberOfPages=newNumberOfPages;
}

void MediaItem::setYearOfPublication(int newYearOfPublication)
{
   yearOfPublication=newYearOfPublication;
}

void MediaItem::setValue(float newValue)
{
   value=newValue;
}

void MediaItem::setInPrint(bool newInPrint)
{
   inPrint=newInPrint;
}

void MediaItem::clearObject()
{
   name=DEF_NAME;
   numberOfPages=DEF_NUMBER_OF_PAGES;
   value=DEF_VALUE;
   inPrint=DEF_IN_PRINT;
   author=DEF_AUTHOR;
   sequel=DEF_SEQUEL;
   yearOfPublication=DEF_YEAR;
}

void MediaItem::addNewElement(int newStart, int newEnd, std::string newName)
{
   Element *toBeAdded=NULL;
   int count;
   
   for(count=0; (count<MAX_ELEMENTS) && (toBeAdded==NULL);count++)
   {
      if( (chapters[count]).isElementEmpty() )
	 toBeAdded=&(chapters[count]);
   }

   if(toBeAdded==NULL)
      std::cout << "Array is full" << std::endl;
   else
   {
      toBeAdded->setStart(newStart);
      toBeAdded->setEnd(newEnd);
      toBeAdded->setName(newName);
   }
}

void MediaItem::setSequel(MediaItem *newSequel)
{
   sequel=newSequel;
}


//helpers
//
bool MediaItem::isEmpty()
{
   if( (name==DEF_NAME) && 
       (numberOfPages==DEF_NUMBER_OF_PAGES) &&
       (value==DEF_VALUE) &&
       (inPrint==DEF_IN_PRINT) &&
       (author==DEF_AUTHOR) &&
       (sequel==DEF_SEQUEL) &&
       (yearOfPublication==DEF_YEAR) )
      return true;
   else
      return false;
}

//helper functions not within the class
//
std::ostream& operator<<(std::ostream& outStream, const MediaItem& miOut)
{
   int count;
   const Element *elementIndex;

   outStream << "MediaItem : " << miOut.getName() << std::endl;
   if( miOut.getAuthor()!=NULL)
   {
      outStream << "   Author : " << (miOut.getAuthor())->getName() << std::endl;
   }
   if(miOut.getSequel()!=NULL)
   {
      outStream << "   Sequel : " << (miOut.getSequel())->getName() << std::endl;
   }
   outStream << "     Year : " << miOut.getYearOfPublication() << std::endl;
   outStream << "    Pages : " << miOut.getNumberOfPages() << std::endl;
   outStream << "    Value : $" << std::fixed << std::setprecision(2) << miOut.getValue() << std::endl;
   outStream << " In Print : " << miOut.getInPrint() << std::endl;

   for(count=0; count<MAX_ELEMENTS; count++)
   {
      elementIndex=(miOut.indexElements(count));
      if( !(elementIndex->isElementEmpty()) )
      {
	 outStream << "Element[" << count << "]" << std::endl;
	 outStream << *elementIndex;
      }
   }

   outStream << std::endl << std::endl;


   return outStream;
}
