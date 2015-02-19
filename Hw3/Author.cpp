//////////////////////
// CS225
// HW3
// 2/18/15
// Kyle Mulligan
// Implementation of Author Class
//////////////////////


#include "Author.hpp"
#include <iostream>
#include <iomanip>



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


