#ifndef __CITY_H__
#define __CITY_H__

#include <string>

class City {
    private:
        std::string m_city_name;
    public:
        City(std::string city_name);
        std::string getCityName();
};

#endif