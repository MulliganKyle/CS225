///////////////////////////////////
// CS225
// HW4
// 3/6/15
// Kyle Mulligan
// Implementation of Book Class
///////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Book.hpp"

//class wide attributes
//
int Book::numberOfBooks=0;

//constructors
Book::Book(std::string newName,
	   float newValue,
	   Author* newAuthor,
	   int newYear,
	   std::string newISBN,
	   int newPages,
	   bool newInPrint,
	   MediaItem* newSequel) : MediaItem(newName, newValue, newAuthor, newYear)
{
   ISBN=newISBN;
   pages=newPages;
   inPrint=newInPrint;
   sequel=newSequel;
   numberOfBooks++;
}

//destructor
Book::~Book()
{
   numberOfBooks--;
}

//mutators
void Book::setISBN(std::string newISBN)
{
   ISBN=newISBN;
}

void Book::setPages(int newPages)
{
   pages=newPages;
}

void Book::setInPrint(bool newInPrint)
{
   inPrint=newInPrint;
}

void Book::setSequel(MediaItem *newSequel)
{
   sequel=newSequel;
}


//helpers
bool Book::isEmpty()
{
   if( MediaItem::isEmpty() &&
       (pages==DEF_PAGES) &&
       (inPrint==DEF_IN_PRINT) &&
       (sequel==DEF_SEQUEL) &&
       (ISBN==DEF_ISBN) )
      return true;
   else
      return false;
}


void Book::toCout() const
{
   std::cout<<(*this);
}


//helpers outside the class
std::ostream& operator<<(std::ostream& outStream, const Book& bOut)
{

   outStream<<((MediaItem &)bOut);

   outStream<< "    Pages : " << bOut.getPages() << std::endl;

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
