#include "user.h"

User::User(std::string user_id, std::string name) {
    m_user_id = user_id;
    m_name = name;
}

void User::addReservation(Reservation* reservation) {
    m_reservations.push_back(reservation);
}

std::string User::getUserId() {
    return m_user_id;
}

std::string User::getName() {
    return m_name;
}

std::vector<Reservation*> User::getReservations() {
    return m_reservations;
}