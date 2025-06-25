#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "seat.h"
#include <vector>

class Screen {
    private:
        static int m_id_gen;
        int m_id;
        std::vector<Seat*> m_seats;
    public:
        Screen();
        int getId();
        void addSeat(Seat* seat);
        std::vector<Seat*> getSeats();
};

#endif