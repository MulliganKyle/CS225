//////////////////////
// CS225
// HW4
// 3/6/15
// Kyle Mulligan
// Implementation of Element Class
//////////////////////


#include "Element.hpp"
#include <iostream>
#include <iomanip>


//class wide attributes
//
int Element::numberOfElements=0;


//constructors
//
Element::Element(int newStart,
	         int newEnd,
		 std::string newName)
{
   start=newStart;
   end=newEnd;
   name=newName;
   numberOfElements++;
}

//destructors
//
Element::~Element()
{
   numberOfElements--;
}


//mutators
//
void Element::setStart(int newStart)
{
   start=newStart;
}

void Element::setEnd(int newEnd)
{
   end=newEnd;
}

void Element::setName(std::string newName)
{
   name=newName;
}

//helpers
//

bool Element::isElementEmpty() const
{
   if( start==DEF_START &&
       end==DEF_END &&
       name==DEF_NAME)
      return true;
   else
      return false;
}


//helper functions not within the class
//
std::ostream& operator<<(std::ostream& outStream, const Element& elOut)
{
   outStream << "  Chapter : " << elOut.getName() << std::endl;
   outStream << "    Start : " << elOut.getStart() << std::endl;
   outStream << "      End : " << elOut.getEnd() << std::endl;
   return outStream;
}

