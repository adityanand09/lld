#include "location.h"

Location::Location(std::string address, std::string city, std::string state, std::string zip_code) {
    m_address = address;
    m_city = city;
    m_state = state;
    m_zip_code = zip_code;
}

std::string Location::getAddress() {
    return m_address;
}

std::string Location::getCity() {
    return m_city;
}

std::string Location::getState() {
    return m_state;
}

std::string Location::getZipCode() {
    return m_zip_code;
}