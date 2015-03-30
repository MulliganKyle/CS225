//////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Implementation of Element Class
//////////////////////


#include "Element.hpp"
#include <iostream>
#include <iomanip>


//class wide attributes
//
int Element::numberOfElements_=0;


//constructors
//
Element::Element(int newStart,
	         int newEnd,
		 std::string newName)
{
   start_=newStart;
   end_=newEnd;
   name_=newName;
   numberOfElements_++;
}

//destructors
//
Element::~Element()
{
   numberOfElements_--;
}


//mutators
//

//recieves an int and puts it into start_
void Element::setStart(int newStart)
{
   start_=newStart;
}

//recieves an int and puts it into end_
void Element::setEnd(int newEnd)
{
   end_=newEnd;
}

//recieves a string and puts it into name_
void Element::setName(std::string newName)
{
   name_=newName;
}

//helpers
//

//recieves no argument and returns a bool dependent
//on whether or not the object is empty
bool Element::isElementEmpty() const
{
   if( start_==DEF_START &&
       end_==DEF_END &&
       name_==DEF_NAME)
      return true;
   else
      return false;
}


//helper functions not within the class
//

//overloaded << operator
std::ostream& operator<<(std::ostream& outStream, const Element& elOut)
{
   outStream << "  Chapter : " << elOut.getName() << std::endl;
   outStream << "    Start : " << elOut.getStart() << std::endl;
   outStream << "      End : " << elOut.getEnd() << std::endl;
   return outStream;
}

