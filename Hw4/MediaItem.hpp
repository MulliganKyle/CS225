//////////////////////
// CS225
// HW4
// 3/6/15
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
#define DEF_VALUE 0.0
#define DEF_AUTHOR NULL
#define DEF_YEAR 0



class MediaItem 
{

   private:
   //attributes of mediaItem
   //
      std::string name;
      int yearOfPublication;
      float value;
      Author *author;
      Element chapters[MAX_ELEMENTS];



   //class attributes
      static int numberOfObjects;

   public:
   //methods of mediaItem
   //

      //constructors
      //
      MediaItem(std::string=DEF_NAME,
		float=DEF_VALUE,
		Author* =DEF_AUTHOR,
		int=DEF_YEAR);

      //destructors
      //
      ~MediaItem();

      
      //accessors
      //
      std::string getName() const { return name;}
      int getYearOfPublication() const {return yearOfPublication;}
      int getNumberOfObjects() const { return numberOfObjects;}
      float getValue() const {return value;}
      Author* getAuthor() const {return author;}
      const Element* indexElements(int index) const {return &chapters[index];}



      //mutators
      //
      void setName(std::string);
      void setAuthor(Author*);
      void setYearOfPublication(int);
      void setValue(float);
      void clearObject();
      void addNewElement(int, int, std::string);

      //helpers
      //
      virtual bool isEmpty();
      virtual void toCout() const;
      

};

std::ostream& operator<<(std::ostream&, const MediaItem&);


#endif
