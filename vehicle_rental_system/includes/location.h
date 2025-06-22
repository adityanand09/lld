#ifndef __LOCATION_H__
#define __LOCATION_H__

#include <string>

class Location {
    private:
        std::string m_address;
        std::string m_city;
        std::string m_state;
        std::string m_zip_code;
    public:
        Location(std::string address, std::string city, std::string state, std::string zip_code);
        std::string getAddress();
        std::string getCity();
        std::string getState();
        std::string getZipCode();
};

#endif