//////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Declaration of Music Class
//////////////////////

#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include "HwLib.hpp"
#include "MediaItem.hpp"
#include "Author.hpp"
#include "Element.hpp"
#include "Book.hpp"
#include "Video.hpp"

#define DEF_PRODUCER ""
#define DEF_MINUTES 0



class Music : public MediaItem
{
   private:
   //attributes of Music
   //
      enum Genre_e { UNDEF=0, REGGAE, COUNTRY, ROCK, TECHNO, HIPHOP, OTHER};

      //producer of the music
      std::string producer_;

      //number of minutes in the music
      float minutes_;

      //genre of the music
      Genre_e genre_;


   //class attributes
      static int numberOfMusics_;
      static std::string const genreString_[];

   public:
   //methods of mediaItem
   //

      //constructors
      //
      Music(std::string=DEF_NAME,
	    float=DEF_VALUE,
	    Author* =DEF_AUTHOR,
	    int=DEF_YEAR,
	    std::string=DEF_PRODUCER,
	    float=DEF_MINUTES);

      //destructors
      //
      ~Music();

      
      //accessors
      //

      //recieves no argument, returns string producer_
      std::string getProducer() const {return producer_;}

      //recieves no argument, returns float minutes_
      float getMinutes() const {return minutes_;}

      //recieves no argument, returns int numberOfMusics_
      static int getNumberOfMusics() {return numberOfMusics_;}
      
      //recieves no arguments, returns the Genre_e enumeration genre_
      Genre_e getGenre() const {return genre_;}

      //recieves a Genre_e enumeration and returns the corresponding string
      std::string getGenreString(Genre_e genre) const {return genreString_[genre];}


      //mutators
      //
      void setProducer(std::string);
      void setMinutes(float);
      void setGenre(std::string);

      //helpers
      //
      bool isEmpty();
      void toCout() const;




};




std::ostream& operator<<(std::ostream&, const Music&);

#endif
