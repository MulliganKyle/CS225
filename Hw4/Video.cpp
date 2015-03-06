///////////////////////////////////
// CS225
// HW4
// 3/6/15
// Kyle Mulligan
// Implementation of Video Class
///////////////////////////////////


#include <iostream>
#include <iomanip>
#include "Video.hpp"

//class wide attributes
int Video::numberOfVideos=0;


//constructors
Video::Video(std::string newName,
	     float newValue,
	     Author* newAuthor,
	     int newYear,
	     std::string newDirector,
	     float newMinutes,
	     MediaItem* newSequel) : MediaItem(newName, newValue, newAuthor, newYear)
{
   director=newDirector;
   minutes=newMinutes;
   sequel=newSequel;
   numberOfVideos++;
}

//destructor
Video::~Video()
{
   numberOfVideos--;
}

//mutators
void Video::setDirector(std::string newDirector)
{
   director=newDirector;
}

void Video::setMinutes(float newMinutes)
{
   minutes=newMinutes;
}

void Video::setSequel(MediaItem *newSequel)
{
   sequel=newSequel;
}


//helpers
bool Video::isEmpty()
{
   if( MediaItem::isEmpty() &&
       (director==DEF_DIRECTOR) &&
       (minutes==DEF_MINUTES) &&
       (sequel==DEF_SEQUEL) )
      return true;
   else
      return false;
}

void Video::toCout() const
{
   std::cout<<(*this);
}

//helper functions outside of class
std::ostream& operator<<(std::ostream& outStream, const Video& vOut)
{

   outStream<<((MediaItem &)vOut);

   outStream<< " Director : " << vOut.getDirector() <<std::endl;
   outStream<< "  Minutes : " << vOut.getMinutes() << std::endl;

   if (vOut.getSequel()!=NULL)
   {
      outStream<< "   Sequel : " << (vOut.getSequel())->getName()<<std::endl;
   }

   outStream<< std::endl<< std::endl;

   return outStream;
}
