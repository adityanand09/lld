#ifndef __THEATRE_CONTROLLER_H__
#define __THEATRE_CONTROLLER_H__

#include "theatre.h"
#include <unordered_map>

class TheatreController {
    private:
        std::unordered_map<City*, std::vector<Theatre*>> m_city_theatres;
        std::vector<Theatre*> m_theatres;
    public:
        TheatreController();

        // setters
        void addTheatre(Theatre* theatre, City* city);

        // getters
        std::vector<Theatre*> getTheatresByCity(City* city);
        Theatre* getTheatreByName(std::string theatre_name);
        std::unordered_map<Theatre*, std::vector<Show*>> getAllShows(Movie* movie, City* city);
};
#endif