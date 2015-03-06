//////////////////////
// CS225
// HW4
// 3/6/15
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
#define DEF_SEQUEL NULL




class Book : public MediaItem
{
   
   private:
   //attributes of Book
   //
      std::string ISBN;
      int pages;
      bool inPrint;
      MediaItem *sequel;

   
   //class attributes
      static int numberOfBooks;

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
      std::string getISBN() const {return ISBN;}
      int getPages() const {return pages;}
      bool getInPrint() const {return inPrint;}
      MediaItem* getSequel() const {return sequel;}
      int getNumberOfBooks() const {return numberOfBooks;}


      //mutators
      //
      void setISBN(std::string);
      void setPages(int);
      void setInPrint(bool);
      void setSequel(MediaItem*);


      //helpers
      //
      bool isEmpty();
      void toCout() const;





};

std::ostream& operator<<(std::ostream&, const Book&);




#endif
