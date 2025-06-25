#include "city.h"

City::City(std::string city_name) : m_city_name(city_name) {};

std::string City::getCityName() {
    return m_city_name;
}