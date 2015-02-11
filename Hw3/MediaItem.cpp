///////////////////////////////////
// CS225
// HW3
// 2/5/15
// Kyle Mulligan
//Implementation of mediaItem Class
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
		     std::string newAuthor,
		     int newNumberOfPages,
		     float newValue,
		     bool newInPrint)
{
   name=newName;
   author=newAuthor;
   numberOfPages=newNumberOfPages;
   value=newValue;
   inPrint=newInPrint;
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

void MediaItem::setAuthor(std::string newAuthor)
{
   author=newAuthor;
}

void MediaItem::setNumberOfPages(int newNumberOfPages)
{
   numberOfPages=newNumberOfPages;
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
   author=DEF_AUTHOR;
   numberOfPages=DEF_NUMBER_OF_PAGES;
   value=DEF_VALUE;
   inPrint=DEF_IN_PRINT;
}


//helpers
//
bool MediaItem::isEmpty()
{
   if( (name==DEF_NAME) && 
       (author==DEF_AUTHOR) && 
       (numberOfPages==DEF_NUMBER_OF_PAGES) &&
       (value==DEF_VALUE) &&
       (inPrint==DEF_IN_PRINT) )
      return true;
   else
      return false;
}

//helper functions not within the class
//
std::ostream& operator<<(std::ostream& outStream, const MediaItem& miOut)
{
   outStream << "MediaItem : " << miOut.getName() << std::endl;
   outStream << "   Author : " << miOut.getAuthor() << std::endl;
   outStream << "    Pages : " << miOut.getNumberOfPages() << std::endl;
   outStream << "    Value : $" << std::fixed << std::setprecision(2) << miOut.getValue() << std::endl;
   outStream << " In Print : " << miOut.getInPrint() << std::endl;
   return outStream;
}
