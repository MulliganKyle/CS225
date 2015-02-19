//////////////////////
// CS225
// HW3
// 2/18/15
// Kyle Mulligan
// Declaration of Element Class
//////////////////////

#include <iostream>

#define DEF_START 0
#define DEF_END 0
#define DEF_NAME ""


class Element
{
   private:
   //attributes of Element
   //
      int start;
      int end;
      std::string name;

   //class attributes
   //
      static int numberOfElements;

   public:
   //methods of Element
   //

      //constructors
      //
      Element(int=DEF_START,
	      int=DEF_END,
	      std::string=DEF_NAME);


      //destructors
      //
      ~Element();


      //accessors
      //
      int getStart() const { return start;}
      int getEnd() const {return end;}
      std::string getName() const { return name;}
      int getNumberOfElements() const { return numberOfElements;}


      //mutators
      //
      void setStart(int);
      void setEnd(int);
      void setName(std::string);

      //helpers
      //


      



};

