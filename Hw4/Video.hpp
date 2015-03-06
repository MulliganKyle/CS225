//////////////////////
// CS225
// HW4
// 3/6/15
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
#define DEF_SEQUEL NULL

class Video : public MediaItem
{
   private:
   //attributes of video
   //
   std::string director;
   float minutes;
   MediaItem *sequel;


   //class attributes
      static int numberOfVideos;

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
      std::string getDirector() const {return director;}
      float getMinutes() const {return minutes;}
      MediaItem* getSequel() const {return sequel;}
      int getNumberOfVideos() const {return numberOfVideos;}


      //mutators
      //
      void setDirector(std::string);
      void setMinutes(float);
      void setSequel(MediaItem*);


      //helpers
      //
      bool isEmpty();
      void toCout() const;








};


std::ostream& operator<<(std::ostream&, const Video&);

#endif
