//////////////////////
// CS225
// HW1
// 1/15/15
// Kyle Mulligan
// Declaration of mediaItem Class
//////////////////////

#include <iostream>

#define DEF_NAME=""
#define DEF_AUTHOR=""
#define DEF_NUMBER_OF_PAGES=0



class mediaItem 
{

   private:
   //attributes of mediaItem
   //
      std::string name;
      std::string author;
      int numberOfPages;

   //class attributes
      static int numberOfObjects;

   public:
   //methods of mediaItem
   //

      //constructors
      //
      mediaItem(std::string=DEF_NAME,
	        std::string=DEF_AUTHOR,
	        int=DEF_NUMBER_OF_PAGES);

      //destructors
      //
      ~mediaItem();

      
      //accessors
      //
      std::string getName(){ return name;}
      std::string getAuthor(){ return author;}
      int getNumberOfPages(){ return numberOfPages;}


      //mutators
      //
      void setName(std::string);
      void setAuthor(std::string);
      void setNumberOfPages(int);
      void clearObject();

      //helpers
      //
      bool isEmpty();
      

};
