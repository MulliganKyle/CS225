//////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Implementation of Author Class
//////////////////////


#include "Author.hpp"
#include <iostream>
#include <iomanip>

//class wide attributes
//
int Author::numberOfAuthors_=0;

//constructors
//
Author::Author(int newBorn,
	       int newDied,
	       std::string newName)
{
   born_=newBorn;
   died_=newDied;
   name_=newName;
   numberOfAuthors_++;
}


//destructors
//
Author::~Author()
{
   numberOfAuthors_--;
}

//mutators
//


//recieves an integer and puts the value in born_
void Author::setBorn(int newBorn)
{
   born_=newBorn;
}

//recieves an integer and puts the value in died_
void Author::setDied(int newDied)
{
   died_=newDied;
}


//recieves a std::string and puts the value in name_
void Author::setName(std::string newName)
{
   name_=newName;
}


//helpers
//


//recieves nothing and returns a boolean value dependent
//on whether the author object is empty
bool Author::isAuthorEmpty()
{
   if( born_==DEF_BORN &&
       died_==DEF_DIED &&
       name_==DEF_NAME)
      return true;
   else
      return false;
}


//helper functions not within the class
//

//overloaded << operator function
std::ostream& operator<<(std::ostream& outStream, const Author& authOut)
{
   outStream << "   Author : " << authOut.getName() << std::endl;
   outStream << "     Born : " << authOut.getBorn() << std::endl;
   outStream << "     Died : " << authOut.getDied() << std::endl;
   return outStream;
}
