#ifndef __USER_H__
#define __USER_H__

#include <string>
#include <vector>

// forward declaration
class Reservation;

class User {
    private :
        std::string m_user_id;
        std::string m_name;
        std::vector<Reservation*> m_reservations;
    public:
        User(std::string user_id, std::string name);
        void addReservation(Reservation* reservation);
        std::string getUserId();
        std::string getName();
        std::vector<Reservation*> getReservations();
};

#endif