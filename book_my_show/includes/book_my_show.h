#ifndef __BOOK_MY_SHOW_H__
#define __BOOK_MY_SHOW_H__

#include "theatre_controller.h"
#include "movie_controller.h"

class BookMyShow {
    private:
        TheatreController* m_theatre_controller;
        MovieController* m_movie_controller;
    public:
        BookMyShow();
        MovieController* getMovieController();
        TheatreController* getTheatreController();
        void init();
    private:
        void createMovies();
        void setupTheatres();
        void addScreens(Theatre* theatre);
        void addSeats(Screen* screen);
        void addShows();

};

#endif