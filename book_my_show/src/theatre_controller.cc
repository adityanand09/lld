#include "theatre_controller.h"

TheatreController::TheatreController() {}

void TheatreController::addTheatre(Theatre* theatre, City* city) {
    bool added = false;
    for (auto &city_theatres : m_city_theatres) {
        if (city_theatres.first->getCityName() == city->getCityName()) {
            city_theatres.second.push_back(theatre);
            added = true;
            break;
        }
    }
    if (!added) {
        m_city_theatres[city].push_back(theatre);
    }
    m_theatres.push_back(theatre);
}

// getters
std::vector<Theatre*> TheatreController::getTheatresByCity(City* city) {
    for (auto city_theatres : m_city_theatres) {
        if (city_theatres.first->getCityName() == city->getCityName()) {
            return city_theatres.second;
        }
    }
    return {};
}

Theatre* TheatreController::getTheatreByName(std::string theatre_name) {
    for (auto theatre : m_theatres) {
        if (theatre->getTheatreName() == theatre_name) {
            return theatre;
        }
    }
    return nullptr;
}

std::unordered_map<Theatre*, std::vector<Show*>> TheatreController::getAllShows(Movie* movie, City* city) {
    std::unordered_map<Theatre*, std::vector<Show*>> theatre_shows;    
    for (auto city_theatres : m_city_theatres) {
        if (city_theatres.first->getCityName() == city->getCityName()) {
            for (auto theatre : city_theatres.second) {
                std::vector<Show*> shows;
                for (Show* show : theatre->getShows()) {
                    if (show->getMovie()->getId() == movie->getId()) {
                        shows.push_back(show);
                    }
                }
                if (!shows.empty()) {
                    theatre_shows[theatre] = shows;
                }
            }

        }
    }
    return theatre_shows;
}