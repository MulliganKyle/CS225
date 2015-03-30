///////////////////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Implementation of Music Class
///////////////////////////////////


#include <iostream>
#include <iomanip>
#include "Music.hpp"

//class wide attributes
int Music::numberOfMusics_=0;
std::string const Music::genreString_[] = {"Undef", "Reggae", "Country", "Rock", "Techno", "Hiphop", "Other"}; 


//constructor
Music::Music(std::string newName,
	     float newValue,
	     Author* newAuthor,
	     int newYear,
	     std::string newProducer,
	     float newMinutes) : MediaItem(newName, newValue, newAuthor, newYear)
{
   producer_=newProducer;
   minutes_=newMinutes;
   numberOfMusics_++;
}

//destructor
Music::~Music()
{
   numberOfMusics_--;
}

//mutators
//

//recieves a string and puts it into producer.
void Music::setProducer(std::string newProducer)
{
   producer_=newProducer;
}

//recieves a float and puts it into minutes.
void Music::setMinutes(float newMinutes)
{
   minutes_=newMinutes;
}

//recieves a std::string and checks if the first three letters
//match to one of the ENUMs. sets genre.
//returns nothing
void Music::setGenre(std::string newString)
{
   unsigned int count;
   for (count=0; (count<3) && (count< newString.length()) ; count++)
   {
      newString[count]=toupper(newString[count]);
   }
   if(newString.compare(0,3,"REG")==0)
      genre_=REGGAE;
   else if (newString.compare(0,3, "COU")==0)
      genre_=COUNTRY;
   else if (newString.compare(0,3, "ROC")==0)
      genre_=ROCK;
   else if (newString.compare(0,3, "TEC")==0)
      genre_=TECHNO;
   else if (newString.compare(0,3, "HIP")==0)
      genre_=HIPHOP;
   else
      genre_=OTHER;
}

//helpers
//

//recievs no argument returns bool dependent upon
//whether the object is empty.
bool Music::isEmpty()
{
   if( MediaItem::isEmpty() &&
       (producer_==DEF_PRODUCER)&&
       (minutes_==DEF_MINUTES) )
      return true;
   else
      return false;
}



void Music::toCout() const
{
   std::cout<<(*this);
}

//helper functions outside of class
//

//overloaded << operator
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
