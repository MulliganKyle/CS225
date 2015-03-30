//////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Declaration of Element Class
//////////////////////

#include <iostream>


#ifndef ELEMENT_H
#define ELEMENT_H



#define DEF_START 0
#define DEF_END 0
#define DEF_NAME ""


class Element
{
   private:
   //attributes of Element
   //
      
      //start of the element (ex page number)
      int start_;

      //end of the element (ex page number)
      int end_;

      //name of the element
      std::string name_;


   //class attributes
   //
      static int numberOfElements_;

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

      //recieves no argument returns an int start_
      int getStart() const { return start_;}

      //recieves no argument returns an int end_
      int getEnd() const {return end_;}

      //recieves no argument returns a string name_
      std::string getName() const { return name_;}

      //recieves no argument returns an int numberOfElements_
      static int getNumberOfElements() { return numberOfElements_;}


      //mutators
      //
      void setStart(int);
      void setEnd(int);
      void setName(std::string);

      //helpers
      //
      bool isElementEmpty() const ;

};

std::ostream& operator<<(std::ostream&, const Element&);
#endif
