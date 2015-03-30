///////////////////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Implementation of Video Class
///////////////////////////////////


#include <iostream>
#include <iomanip>
#include "Video.hpp"

//class wide attributes
int Video::numberOfVideos_=0;


//constructors
Video::Video(std::string newName,
	     float newValue,
	     Author* newAuthor,
	     int newYear,
	     std::string newDirector,
	     float newMinutes,
	     MediaItem* newSequel) : MediaItem(newName, newValue, newAuthor, newYear, newSequel)
{
   director_=newDirector;
   minutes_=newMinutes;
   numberOfVideos_++;
}

//destructor
Video::~Video()
{
   numberOfVideos_--;
}

//mutators
//

//recieves a string and puts it into director_
void Video::setDirector(std::string newDirector)
{
   director_=newDirector;
}

//recieves a float and puts it into minutes_
void Video::setMinutes(float newMinutes)
{
   minutes_=newMinutes;
}



//helpers
//

//recieves no argument and returns a boolean dependent upon
//whether the object is empty
bool Video::isEmpty()
{
   if( MediaItem::isEmpty() &&
       (director_==DEF_DIRECTOR) &&
       (minutes_==DEF_MINUTES))
      return true;
   else
      return false;
}

//recieves not argument returns nothing
//polymorphic function sends object to cout
void Video::toCout() const
{
   std::cout<<(*this);
}

//helper functions outside of class
//

//overloaded << operator
std::ostream& operator<<(std::ostream& outStream, const Video& vOut)
{

   outStream<<((MediaItem &)vOut);

   outStream<< " Director : " << vOut.getDirector() <<std::endl;
   outStream<< "  Minutes : " << vOut.getMinutes() << std::endl;

   outStream<< std::endl<< std::endl;

   return outStream;
}
