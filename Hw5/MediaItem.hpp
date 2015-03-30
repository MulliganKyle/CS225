//////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Declaration of mediaItem Class
//////////////////////

#include <iostream>
#include <list>
#include "HwLib.hpp"
#include "Element.hpp"
#include "Author.hpp"

#ifndef MEDIAITEM_H
#define MEDIAITEM_H


#define DEF_NAME ""
#define DEF_VALUE 0.0
#define DEF_AUTHOR NULL
#define DEF_YEAR 0
#define DEF_SEQUEL NULL


class MediaItem 
{

   private:
   //attributes of mediaItem
   //

      //name of the item
      std::string name_;

      //year the item was published
      int yearOfPublication_;

      //monetary value of the item
      float value_;

      //pointer to the author of the item
      Author *author_;
      
      //pointer to the sequel of the item
      MediaItem *sequel_;

      //standard template list of element pointers
      std::list<Element*> elementList_;



   //class attributes
      static int numberOfObjects_;

   public:
   //methods of mediaItem
   //
      //constructors
      //
      MediaItem(std::string=DEF_NAME,
		float=DEF_VALUE,
		Author* =DEF_AUTHOR,
		int=DEF_YEAR,
		MediaItem* =DEF_SEQUEL);

      //destructors
      //
      virtual ~MediaItem();

      
      //accessors
      //

      //recieves no argument, returns a string name_
      std::string getName() const { return name_;}

      //recieves no argument, returns an int yearOfPublication_
      int getYearOfPublication() const {return yearOfPublication_;}

      //recieves no argument, returns an int numberOfObjects_
      static int getNumberOfObjects() { return numberOfObjects_;}

      //recieves no argument, returns a float value_
      float getValue() const {return value_;}

      //recieves no argument, returns an Author pointer author_
      Author* getAuthor() const {return author_;}

      //recieves no argument, returns the entire elementList_
      std::list<Element*> getAllElements() const {return elementList_;}

      //recieves no argument, returns a MediaItem pointer sequel_
      MediaItem* getSequel() const {return sequel_;}



      //mutators
      //
      void setName(std::string);
      void setAuthor(Author*);
      void setYearOfPublication(int);
      void setValue(float);
      void clearObject();
      void addNewElement(int, int, std::string);
      void setSequel(MediaItem*);

      //helpers
      //
      virtual bool isEmpty();
      virtual void toCout() const;
      

};

std::ostream& operator<<(std::ostream&, const MediaItem&);


#endif
