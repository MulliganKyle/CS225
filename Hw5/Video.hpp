//////////////////////
// CS225
// HW5
// 3/27/15
// Kyle Mulligan
// Declaration of Video Class
//////////////////////

#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include "HwLib.hpp"
#include "MediaItem.hpp"
#include "Author.hpp"
#include "Element.hpp"
#include "Book.hpp"
#include "Music.hpp"

#define DEF_DIRECTOR ""
#define DEF_MINUTES 0

class Video : public MediaItem
{
   private:
   //attributes of video
   //

   //director of the video
   std::string director_;

   //number of minutes in the video
   float minutes_;


   //class attributes
      static int numberOfVideos_;

   public:
   //methods of mediaItem
   //

      //constructors
      //
      Video(std::string=DEF_NAME,
	    float=DEF_VALUE,
	    Author* =DEF_AUTHOR,
	    int=DEF_YEAR,
	    std::string=DEF_DIRECTOR,
	    float=DEF_MINUTES,
	    MediaItem* =DEF_SEQUEL);


      //destructors
      //
      ~Video();

      
      //accessors
      //

      //recieves no argument, returns string director_
      std::string getDirector() const {return director_;}

      //recieves no argument, returns float minutes_
      float getMinutes() const {return minutes_;}

      //recieves no argument, returns int numberOfVideos_
      static int getNumberOfVideos() {return numberOfVideos_;}


      //mutators
      //
      void setDirector(std::string);
      void setMinutes(float);


      //helpers
      //
      bool isEmpty();
      void toCout() const;








};


std::ostream& operator<<(std::ostream&, const Video&);

#endif
