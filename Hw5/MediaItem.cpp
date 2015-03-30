///////////////////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Implementation of mediaItem Class
///////////////////////////////////

#include <iostream>
#include <iomanip>
#include "MediaItem.hpp"


//class static attribute
//
int MediaItem::numberOfObjects_=0;

//constructors
//
MediaItem::MediaItem(std::string newName,
		     float newValue,
		     Author* newAuthor,
		     int newYear,
		     MediaItem* newSequel)
{
   name_=newName;
   value_=newValue;
   author_=newAuthor;
   yearOfPublication_=newYear;
   sequel_=newSequel;
   numberOfObjects_++;
}

//destructors
//
MediaItem::~MediaItem()
{
   while(!elementList_.empty())
   {
      delete elementList_.back();
      elementList_.pop_back();
   }
   numberOfObjects_--;

}


//mutators
//

//recieves a string and puts it into name_
void MediaItem::setName(std::string newName)
{
   name_=newName;
}

//recieves an Author  pointer and puts it into author_
void MediaItem::setAuthor(Author *newAuthor)
{
   author_=newAuthor;
}

//recieves an integer and puts it into yearOfPublication_
void MediaItem::setYearOfPublication(int newYearOfPublication)
{
   yearOfPublication_=newYearOfPublication;
}

//recieves a float and puts it into value_
void MediaItem::setValue(float newValue)
{
   value_=newValue;
}

//recieves a MediaItem pointer and puts it into sequel_
void MediaItem::setSequel(MediaItem *newSequel)
{
   sequel_=newSequel;
}


//recieves no argument, changes the values of name_,
//value_, author_, and yearOfPublication_ to their default values
void MediaItem::clearObject()
{
   name_=DEF_NAME;
   value_=DEF_VALUE;
   author_=DEF_AUTHOR;
   yearOfPublication_=DEF_YEAR;
}

//recieves two integers and a std::string, creates a new element
//object and puts the values given by the arguments into the element
//pushes the element to the back of elementList
void MediaItem::addNewElement(int newStart, int newEnd, std::string newName)
{
   Element *newElement=new Element();
   
   newElement->setStart(newStart);
   newElement->setEnd(newEnd);
   newElement->setName(newName);

   elementList_.push_back(newElement);

}



//helpers
//

//recieves no argument, returns bool dependent upon
//whether the object is empty.
bool MediaItem::isEmpty()
{
   if( (name_==DEF_NAME) && 
       (value_==DEF_VALUE) &&
       (author_==DEF_AUTHOR) &&
       (yearOfPublication_==DEF_YEAR) )
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


//overloaded << operator
std::ostream& operator<<(std::ostream& outStream, const MediaItem& miOut)
{
   int count=0;
   std::list<Element*> theElements=miOut.getAllElements();

   outStream << "MediaItem : " << miOut.getName() << std::endl;
   if( miOut.getAuthor()!=NULL)
   {
      outStream << "   Author : " << (miOut.getAuthor())->getName() << std::endl;
   }
   outStream << "     Year : " << miOut.getYearOfPublication() << std::endl;
   outStream << "    Value : $" << std::fixed << std::setprecision(2) << miOut.getValue() << std::endl;

   if (miOut.getSequel()!=NULL)
   {
      outStream<< "   Sequel : " << (miOut.getSequel())->getName()<<std::endl;
   }
   
   
   for(Element *element: theElements)
   {
      if( !(element->isElementEmpty()) )
      {
	 outStream << "Element[" << count << "]" << std::endl;
	 outStream << *element;
	 count++;
      }
   }


   return outStream;
}
