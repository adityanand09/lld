#ifndef __MOVIE_CONTROLLER_H__
#define __MOVIE_CONTROLLER_H__

#include "movie.h"
#include "city.h"
#include <unordered_map>
#include <vector>

class MovieController {
    private:
        std::unordered_map<City*, std::vector<Movie*>> m_city_movies;
        std::vector<Movie*> m_movies;
    public:
        MovieController();
        
        // setters
        void addMovie(Movie* movie, City* city);

        // getters
        Movie* getMovieByName(std::string movie_name);
        std::vector<Movie*> getMoviesByCity(City* city);
    };

#endif