//////////////////////
// CS225
// HW1
// 1/15/15
// Kyle Mulligan
// Declaration of mediaItem Class
//////////////////////

#include <iostream>

#define DEF_NAME ""
#define DEF_AUTHOR ""
#define DEF_NUMBER_OF_PAGES 0
#define DEF_VALUE 0.0
#define DEF_IN_PRINT false



class mediaItem 
{

   private:
   //attributes of mediaItem
   //
      std::string name;
      std::string author;
      int numberOfPages;
      float value;
      bool inPrint;




   //class attributes
      static int numberOfObjects;

   public:
   //methods of mediaItem
   //

      //constructors
      //
      mediaItem(std::string=DEF_NAME,
	        std::string=DEF_AUTHOR,
	        int=DEF_NUMBER_OF_PAGES,
		float=DEF_VALUE,
		bool=DEF_IN_PRINT);

      //destructors
      //
      ~mediaItem();

      
      //accessors
      //
      std::string getName() const { return name;}
      std::string getAuthor() const { return author;}
      int getNumberOfPages() const { return numberOfPages;}
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

std::ostream& operator<<(std::ostream&, const mediaItem&);
