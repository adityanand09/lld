#include "theatre.h"

int Theatre::m_id_gen = 0;

Theatre::Theatre(std::string theatre_name, City* city) : m_theatre_name(theatre_name), m_city(city) {
    m_id = m_id_gen;
}

// setters
void Theatre::addScreen(Screen* screen) {
    m_screens.push_back(screen);
}

void Theatre::addShow(Show* show) {
    m_shows.push_back(show);
}

// getters
std::vector<Show*> Theatre::getShows() {
    return m_shows;
}

std::string Theatre::getTheatreName() {
    return m_theatre_name;
}

std::vector<Screen*> Theatre::getScreens() {
    return m_screens;
}