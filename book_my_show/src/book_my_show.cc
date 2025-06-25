#include "book_my_show.h"

BookMyShow::BookMyShow() : m_movie_controller(new MovieController()), m_theatre_controller(new TheatreController()) {}

void BookMyShow::init() {
    setupTheatres();
    createMovies();
    addShows();
}

void BookMyShow::createMovies() {
    // create movies
    Movie* golmaal = new Movie("Golmaal", 180);
    Movie* hulchal = new Movie("Hulchal", 200);

    // create cities
    City* city1 = new City("Bangalore");
    City* city2 = new City("Delhi");

    // add movies to movie controller
    m_movie_controller->addMovie(golmaal, city1);
    m_movie_controller->addMovie(hulchal, city1);
    m_movie_controller->addMovie(golmaal, city2);
    m_movie_controller->addMovie(hulchal, city2);
}

void BookMyShow::setupTheatres() {

    // theatre1
    City* bangalore = new City("Bangalore");
    Theatre* inox = new Theatre("INOX", bangalore);
    addScreens(inox);
    m_theatre_controller->addTheatre(inox, bangalore);

    City* delhi = new City("Delhi");
    Theatre* pvr = new Theatre("PVR", delhi);
    addScreens(pvr);
    m_theatre_controller->addTheatre(pvr, delhi);
}

void BookMyShow::addScreens(Theatre* theatre) {
    for (int i=0; i<3; i++) {
        Screen* screen = new Screen();
        addSeats(screen);
        theatre->addScreen(screen);
    }
}

void BookMyShow::addSeats(Screen* screen) {
    for (int id=101; id<=110; id++) {
        Seat* seat = new Seat(id, 1, SILVER);
        screen->addSeat(seat);
    }
    for (int id=111; id<=120; id++) {
        Seat* seat = new Seat(id, 1, GOLD);
        screen->addSeat(seat);
    }
    for (int id=121; id<=130; id++) {
        Seat* seat = new Seat(id, 1, PLATINUM);
        screen->addSeat(seat);
    }
}

void BookMyShow::addShows() {
    
    Movie* golmaal = m_movie_controller->getMovieByName("Golmaal");
    Movie* hulchal = m_movie_controller->getMovieByName("Hulchal");
    
    Theatre* theatre1 = m_theatre_controller->getTheatresByCity(new City("Bangalore"))[0];
    Screen* screen1 = theatre1->getScreens()[0];
    Show* show1 = new Show(screen1, golmaal, 1700);
    Show* show2 = new Show(screen1, hulchal, 2200);
    theatre1->addShow(show1);
    theatre1->addShow(show2);

    Theatre* theatre2 = m_theatre_controller->getTheatresByCity(new City("Delhi"))[0];
    Screen* screen2 = theatre2->getScreens()[0];
    Show* show3 = new Show(screen2, golmaal, 1700);
    Show* show4 = new Show(screen2, hulchal, 2200);
    theatre2->addShow(show3);
    theatre2->addShow(show4);
}

MovieController* BookMyShow::getMovieController() {
    return m_movie_controller;
}

TheatreController* BookMyShow::getTheatreController() {
    return m_theatre_controller;
}