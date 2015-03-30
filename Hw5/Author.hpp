//////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Declaration of Author Class
//////////////////////

#include <iostream>


#ifndef AUTHOR_H
#define AUTHOR_H



#define DEF_BORN 0
#define DEF_DIED 0
#define DEF_NAME ""


class Author
{
   private:
   //attributes of Author class
   //

   
      //year born
      int born_;

      //year died (0 if still alive)
      int died_;

      //name of Author
      std::string name_;

      //class attributes
      //

      //number of objects in memory
      static int numberOfAuthors_;

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


      //recieves no arguments and returns the value in born_
      int getBorn() const {return born_;}

      //recieves no arguments and returns the value in died_
      int getDied() const {return died_;}

      //recieves no arguments and returns the value in name_
      std::string getName() const {return name_;}

      //recieves no arguments and returns the value in numberOfAuthors_
      static int getNumberOfAuthors() {return numberOfAuthors_;}

      //mutators
      //
      void setBorn(int);
      void setDied(int);
      void setName(std::string);

      //helpers
      //
      bool isAuthorEmpty();





};

std::ostream& operator<<(std::ostream&, const Author&);


#endif
