//////////////////////
// CS225
// HW1
// 1/15/15
// Kyle Mulligan
// Declaration of mediaItem Class
//////////////////////

#include <iostream>

class mediaItem 
{

   private:
   //attributes of mediaItem
   //
      std::string name;
      std::string author;
      int numberOfPages;

   public:
   //methods of mediaItem
   //
      void setName(std::string);
      std::string getName(){ return name;}
      void setAuthor(std::string);
      std::string getAuthor(){ return author;}
      void setNumberOfPages(int);
      int getNumberOfPages(){ return numberOfPages;}
};
