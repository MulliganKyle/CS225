///////////////////////////////////
// CS225
// HW4
// 3/6/15
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
		     float newValue,
		     Author* newAuthor,
		     int newYear)
{
   name=newName;
   value=newValue;
   author=newAuthor;
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

void MediaItem::setYearOfPublication(int newYearOfPublication)
{
   yearOfPublication=newYearOfPublication;
}

void MediaItem::setValue(float newValue)
{
   value=newValue;
}


void MediaItem::clearObject()
{
   name=DEF_NAME;
   value=DEF_VALUE;
   author=DEF_AUTHOR;
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



//helpers
//
bool MediaItem::isEmpty()
{
   if( (name==DEF_NAME) && 
       (value==DEF_VALUE) &&
       (author==DEF_AUTHOR) &&
       (yearOfPublication==DEF_YEAR) )
      return true;
   else
      return false;
}

void MediaItem::toCout() const
{
   std::cout<<(*this);
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
   outStream << "     Year : " << miOut.getYearOfPublication() << std::endl;
   outStream << "    Value : $" << std::fixed << std::setprecision(2) << miOut.getValue() << std::endl;

   for(count=0; count<MAX_ELEMENTS; count++)
   {
      elementIndex=(miOut.indexElements(count));
      if( !(elementIndex->isElementEmpty()) )
      {
	 outStream << "Element[" << count << "]" << std::endl;
	 outStream << *elementIndex;
      }
   }


   return outStream;
}
