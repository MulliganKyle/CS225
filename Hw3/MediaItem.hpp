//////////////////////
// CS225
// HW3
// 2/20/15
// Kyle Mulligan
// Declaration of mediaItem Class
//////////////////////

#include <iostream>
#include "HwLib.hpp"
#include "Element.hpp"
#include "Author.hpp"

#ifndef MEDIAITEM_H
#define MEDIAITEM_H


#define DEF_NAME ""
#define DEF_NUMBER_OF_PAGES 0
#define DEF_VALUE 0.0
#define DEF_IN_PRINT false
#define DEF_AUTHOR NULL
#define DEF_SEQUEL NULL
#define DEF_YEAR 0



class MediaItem 
{

   private:
   //attributes of mediaItem
   //
      std::string name;
      int numberOfPages;
      int yearOfPublication;
      float value;
      bool inPrint;
      Author *author;
      MediaItem *sequel;
      Element chapters[MAX_ELEMENTS];



   //class attributes
      static int numberOfObjects;

   public:
   //methods of mediaItem
   //

      //constructors
      //
      MediaItem(std::string=DEF_NAME,
	        int=DEF_NUMBER_OF_PAGES,
		float=DEF_VALUE,
		bool=DEF_IN_PRINT,
		Author* =DEF_AUTHOR,
		MediaItem* =DEF_SEQUEL,
		int=DEF_YEAR);

      //destructors
      //
      ~MediaItem();

      
      //accessors
      //
      std::string getName() const { return name;}
      int getYearOfPublication() const {return yearOfPublication;}
      int getNumberOfPages() const { return numberOfPages;}
      int getNumberOfObjects() const { return numberOfObjects;}
      float getValue() const {return value;}
      bool getInPrint() const {return inPrint;}
      Author* getAuthor() const {return author;}
      MediaItem* getSequel() const {return sequel;}
      const Element* indexElements(int index) const {return &chapters[index];}



      //mutators
      //
      void setName(std::string);
      void setAuthor(Author*);
      void setSequel(MediaItem*);
      void setNumberOfPages(int);
      void setYearOfPublication(int);
      void setValue(float);
      void setInPrint(bool);
      void clearObject();
      void addNewElement(int, int, std::string);

      //helpers
      //
      bool isEmpty();
      

};

std::ostream& operator<<(std::ostream&, const MediaItem&);


#endif
