///////////////////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Implementation of Book Class
///////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Book.hpp"

//class wide attributes
//
int Book::numberOfBooks_=0;

//constructors
Book::Book(std::string newName,
	   float newValue,
	   Author* newAuthor,
	   int newYear,
	   std::string newISBN,
	   int newPages,
	   bool newInPrint,
	   MediaItem* newSequel) : MediaItem(newName, newValue, newAuthor, newYear, newSequel)
{
   ISBN_=newISBN;
   pages_=newPages;
   inPrint_=newInPrint;
   numberOfBooks_++;
}

//destructor
Book::~Book()
{
   numberOfBooks_--;
}

//mutators
//

//recieves a std::string and puts the value in ISBN_
void Book::setISBN(std::string newISBN)
{
   ISBN_=newISBN;
}

//recieves an integer and puts the value in pages_
void Book::setPages(int newPages)
{
   pages_=newPages;
}

//recieves a boolean and puts the value in inPrint_
void Book::setInPrint(bool newInPrint)
{
   inPrint_=newInPrint;
}


//helpers
//


//recieves no arguments and returns a boolean
//dependent on whether or not the object is empty
bool Book::isEmpty()
{
   if( MediaItem::isEmpty() &&
       (pages_==DEF_PAGES) &&
       (inPrint_==DEF_IN_PRINT) &&
       (ISBN_==DEF_ISBN) )
      return true;
   else
      return false;
}

//recieves no arguments and returns nothing
//is a polymorphic function that inserts the object to cout
void Book::toCout() const
{
   std::cout<<(*this);
}


//helpers outside the class
//


//overloaded << operator
std::ostream& operator<<(std::ostream& outStream, const Book& bOut)
{

   outStream<<((MediaItem &)bOut);

   outStream<< std::endl<< "    Pages : " << bOut.getPages() << std::endl;

   if (bOut.getInPrint())
   {
      outStream<< " In Print : True"<<std::endl;
   }
   else
   {
      outStream<< " In Print : False"<<std::endl;
   }
   
   outStream<< "     ISBN : " << bOut.getISBN() << std::endl;

   if (bOut.getSequel()!=NULL)
   {
      outStream<< "   Sequel : " << (bOut.getSequel())->getName()<<std::endl;
   }

   outStream<< std::endl<< std::endl;

   return outStream;
}
