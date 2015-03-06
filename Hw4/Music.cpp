///////////////////////////////////
// CS225
// HW4
// 3/6/15
// Kyle Mulligan
// Implementation of Music Class
///////////////////////////////////


#include <iostream>
#include <iomanip>
#include "Music.hpp"

//class wide attributes
int Music::numberOfMusics=0;
std::string const Music::genreString[] = {"Undef", "Reggae", "Country", "Rock", "Techno", "Hiphop", "Other"}; 


//constructor
Music::Music(std::string newName,
	     float newValue,
	     Author* newAuthor,
	     int newYear,
	     std::string newProducer,
	     float newMinutes) : MediaItem(newName, newValue, newAuthor, newYear)
{
   producer=newProducer;
   minutes=newMinutes;
   numberOfMusics++;
}

//destructor
Music::~Music()
{
   numberOfMusics--;
}

//mutators
void Music::setProducer(std::string newProducer)
{
   producer=newProducer;
}

void Music::setMinutes(float newMinutes)
{
   minutes=newMinutes;
}

void Music::setGenre(std::string newString)
{
   unsigned int count;
   for (count=0; (count<3) && (count< newString.length()) ; count++)
   {
      newString[count]=toupper(newString[count]);
   }
   if(newString.compare(0,3,"REG")==0)
      genre=REGGAE;
   else if (newString.compare(0,3, "COU")==0)
      genre=COUNTRY;
   else if (newString.compare(0,3, "ROC")==0)
      genre=ROCK;
   else if (newString.compare(0,3, "TEC")==0)
      genre=TECHNO;
   else if (newString.compare(0,3, "HIP")==0)
      genre=HIPHOP;
   else
      genre=OTHER;
}

//helpers
bool Music::isEmpty()
{
   if( MediaItem::isEmpty() &&
       (producer==DEF_PRODUCER)&&
       (minutes==DEF_MINUTES) )
      return true;
   else
      return false;
}



void Music::toCout() const
{
   std::cout<<(*this);
}

//helper functions outside of class
std::ostream& operator<<(std::ostream& outStream, const Music& muOut)
{

   outStream<<((MediaItem &)muOut);

   outStream<< " Producer : " << muOut.getProducer() <<std::endl;
   outStream<< "  Minutes : " << muOut.getMinutes() <<std::endl;

   if( ( (muOut).getGenreString(muOut.getGenre()) ).compare("Undef")!=0 )
      outStream<< "    Genre : " << muOut.getGenreString(muOut.getGenre()) << std::endl;


   outStream<< std::endl<< std::endl;

   return outStream;
}
