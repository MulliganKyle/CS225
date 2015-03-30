//////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Declaration of Book Class
//////////////////////





#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "HwLib.hpp"
#include "MediaItem.hpp"
#include "Author.hpp"
#include "Element.hpp"
#include "Music.hpp"
#include "Video.hpp"

#define DEF_ISBN ""
#define DEF_PAGES 0
#define DEF_IN_PRINT false




class Book : public MediaItem
{
   
   private:
   //attributes of Book
   //

      //string of ISBN
      std::string ISBN_;

      //number of pages in the book
      int pages_;

      //boolean of whether the book is in print or not
      bool inPrint_;

   
   //class attributes

      //number of objects in memory
      static int numberOfBooks_;

   public:
   //methods of mediaItem
   //

      //constructors
      //
      Book(std::string=DEF_NAME,
	   float=DEF_VALUE,
	   Author* =DEF_AUTHOR,
	   int=DEF_YEAR,
	   std::string=DEF_ISBN,
	   int=DEF_PAGES,
	   bool=DEF_IN_PRINT,
	   MediaItem* =DEF_SEQUEL);


      //destructors
      //
      ~Book();

      
      //accessors
      //

      //recieves no argument and returns a string ISBN_
      std::string getISBN() const {return ISBN_;}

      //recieves no argument and returns an int pages_
      int getPages() const {return pages_;}

      //recieves no argument and returns a bool inPrint_
      bool getInPrint() const {return inPrint_;}

      //recieves no argument and returns an int numberOfBooks_
      static int getNumberOfBooks() {return numberOfBooks_;}


      //mutators
      //
      void setISBN(std::string);
      void setPages(int);
      void setInPrint(bool);


      //helpers
      //
      bool isEmpty();
      void toCout() const;





};

std::ostream& operator<<(std::ostream&, const Book&);




#endif
