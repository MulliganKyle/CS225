//////////////////////
// CS225
// HW3
// 2/5/15
// Kyle Mulligan
// Declaration of mediaItem Class
//////////////////////

#include <iostream>
#include "HwLib.hpp"
#include "Element.hpp"
#include "Author.hpp"


#define DEF_NAME ""
#define DEF_AUTHOR ""
#define DEF_NUMBER_OF_PAGES 0
#define DEF_VALUE 0.0
#define DEF_IN_PRINT false



class MediaItem 
{

   private:
   //attributes of mediaItem
   //
      std::string name;
      std::string author;
      int numberOfPages;
      float value;
      bool inPrint;
      //Author *author;
      Element chapters[MAX_ELEMENTS];



   //class attributes
      static int numberOfObjects;

   public:
   //methods of mediaItem
   //

      //constructors
      //
      MediaItem(std::string=DEF_NAME,
	        std::string=DEF_AUTHOR,
	        int=DEF_NUMBER_OF_PAGES,
		float=DEF_VALUE,
		bool=DEF_IN_PRINT);

      //destructors
      //
      ~MediaItem();

      
      //accessors
      //
      std::string getName() const { return name;}
      std::string getAuthor() const { return author;}
      int getNumberOfPages() const { return numberOfPages;}
      int getNumberOfObjects() const { return numberOfObjects;}
      float getValue() const {return value;}
      bool getInPrint() const {return inPrint;}

      //mutators
      //
      void setName(std::string);
      void setAuthor(std::string);
      void setNumberOfPages(int);
      void setValue(float);
      void setInPrint(bool);
      void clearObject();

      //helpers
      //
      bool isEmpty();
      

};

std::ostream& operator<<(std::ostream&, const MediaItem&);
