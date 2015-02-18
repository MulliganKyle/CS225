//////////////////////
// CS225
// HW3
// 2/18/15
// Kyle Mulligan
// Declaration of Author Class
//////////////////////

#include <iostream>

#define DEF_BORN 0
#define DEF_DIED 0
#define DEF_NAME ""


class Author
{
   private:
   //attributes of Author class
   //
      int born;
      int died;
      std::string name;

      //class attributes
      //
      

   public:
   //methods of Author class
   //

      //constructors
      //
      Author(int=DEF_BORN,
	     int=DEF_DIED,
	     std::string=DEF_NAME);

      //destructors
      //
      ~Author();

      //accessors
      //
      int getBorn() const {return born;}
      int getDied() const {return died;}
      std::string getName() const {return name;}

      //mutators
      //
      void setBorn(int);
      void setDied(int);
      void setName(std::string);

      //helpers
      //






};
