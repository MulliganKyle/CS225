//////////////////////
// CS225
// HW3
// 2/20/15
// Kyle Mulligan
// Implementation of Author Class
//////////////////////


#include "Author.hpp"
#include <iostream>
#include <iomanip>

//class wide attributes
//
int Author::numberOfAuthors=0;

//constructors
//
Author::Author(int newBorn,
	       int newDied,
	       std::string newName)
{
   born=newBorn;
   died=newDied;
   name=newName;
   numberOfAuthors++;
}


//destructors
//
Author::~Author()
{
   numberOfAuthors--;
}

//mutators
//
void Author::setBorn(int newBorn)
{
   born=newBorn;
}

void Author::setDied(int newDied)
{
   died=newDied;
}

void Author::setName(std::string newName)
{
   name=newName;
}


//helpers
//
bool Author::isAuthorEmpty()
{
   if( born==DEF_BORN &&
       died==DEF_DIED &&
       name==DEF_NAME)
      return true;
   else
      return false;
}


//helper functions not within the class
//
std::ostream& operator<<(std::ostream& outStream, const Author& authOut)
{
   outStream << "   Author : " << authOut.getName() << std::endl;
   outStream << "     Born : " << authOut.getBorn() << std::endl;
   outStream << "     Died : " << authOut.getDied() << std::endl;
   return outStream;
}
