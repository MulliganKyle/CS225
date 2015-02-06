///////////////////////////////////
// CS225
// HW1
// 2/5/15
// Kyle Mulligan
//Implementation of mediaItem Class
///////////////////////////////////

#include <iostream>
#include <iomanip>
#include "mediaItem.hpp"


//class static attribute
//
int mediaItem::numberOfObjects=0;

//constructors
//
mediaItem::mediaItem(std::string newName,
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

void mediaItem::setValue(float newValue)
{
   value=newValue;
}

void mediaItem::setInPrint(bool newInPrint)
{
   inPrint=newInPrint;
}

void mediaItem::clearObject()
{
   name=DEF_NAME;
   author=DEF_AUTHOR;
   numberOfPages=DEF_NUMBER_OF_PAGES;
   value=DEF_VALUE;
   inPrint=DEF_IN_PRINT;
}


//helpers
//
bool mediaItem::isEmpty()
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
std::ostream& operator<<(std::ostream& outStream, const mediaItem& miOut)
{
   outStream << "MediaItem : " << miOut.getName() << std::endl;
   outStream << "   Author : " << miOut.getAuthor() << std::endl;
   outStream << "    Pages : " << miOut.getNumberOfPages() << std::endl;
   outStream << "    Value : $" << std::fixed << std::setprecision(2) << miOut.getValue() << std::endl;
   outStream << " In Print : " << miOut.getInPrint() << std::endl;
   return outStream;
}
