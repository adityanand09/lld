#include "movie_controller.h"

MovieController::MovieController() {}

// setters
void MovieController::addMovie(Movie* movie, City* city) {
    bool added = false;
    for (auto &city_movies : m_city_movies) {
        if (city_movies.first->getCityName() == city->getCityName()) {
            city_movies.second.push_back(movie);
            added = true;
        }
    }
    if (!added) {
        m_city_movies[city].push_back(movie);
    }
    m_movies.push_back(movie);
}

Movie* MovieController::getMovieByName(std::string movie_name) {
    for (Movie* movie : m_movies) {
        if (movie->getMovieName() == movie_name) {
            return movie;
        }
    }
    return nullptr;
}

std::vector<Movie*> MovieController::getMoviesByCity(City* city) {
    for (auto &city_movies : m_city_movies) {
        if (city_movies.first->getCityName() == city->getCityName()) {
            return city_movies.second;
        }
    }
    return {};
}