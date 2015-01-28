///////////////////////////////////
// CS225
// HW1
// 1/15/15
// Kyle Mulligan
//Implementation of mediaItem Class
///////////////////////////////////

#include <iostream>
#include "mediaItem.hpp"


//class static attribute
//
int mediaItem::numberOfObjects=0;

//constructors
//
mediaItem::mediaItem(std::string newName,
		     std::string newAuthor,
		     int newNumberOfPages)
{
   name=newName;
   author=newAuthor;
   numberOfPages=newNumberOfPages;
   numberOfObjects++;
}

//destructors
//
mediaItem::~mediaItem()
{
   numberOfObjects--;

}


//mutators
//
void mediaItem::setName(std::string newName)
{
   name=newName;
}

void mediaItem::setAuthor(std::string newAuthor)
{
   author=newAuthor;
}

void mediaItem::setNumberOfPages(int newNumberOfPages)
{
   numberOfPages=newNumberOfPages;
}

void mediaItem::clearObject()
{
   name=DEF_NAME;
   author=DEF_AUTHOR;
   numberOfPages=DEF_NUMBER_OF_PAGES;
}


//helpers
//
bool mediaItem::isEmpty()
{
   if( (name==DEF_NAME) && (author==DEF_AUTHOR) && (numberOfPages==DEF_NUMBER_OF_PAGES) )
      return true;
   else
      return false;
}


std::ostream& operator<<(std::ostream& outStream, const mediaItem& miOut)
{
   outStream << "MediaItem : " << miOut.getName() << std::endl;
   outStream << "   Author : " << miOut.getAuthor() << std::endl;
   outStream << "    Pages : " << miOut.getNumberOfPages() << std::endl;
   return outStream;
}
