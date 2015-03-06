//////////////////////
// CS225
// HW4
// 3/6/15
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

      std::string producer;
      float minutes;
      Genre_e genre;


   //class attributes
      static int numberOfMusics;
      static std::string const genreString[];

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
      std::string getProducer() const {return producer;}
      float getMinutes() const {return minutes;}
      int getNumberOfMusics() const {return numberOfMusics;}
      
      Genre_e getGenre() const {return genre;}
      std::string getGenreString(Genre_e genre) const {return genreString[genre];}


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
