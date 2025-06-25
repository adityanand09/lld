#ifndef __BOOKING_H__
#define __BOOKING_H__

#include "show.h"
#include "payment.h"
#include <vector>

class Booking {
    private:
        static int m_id_gen;
        int m_id;
        Show* m_show;
        std::vector<Seat*> m_seats;
        Payment* payment;
    public:
        Booking(Show* show, std::vector<Seat*> seats);
        std::vector<Seat*> getSeats();
        void makePayment();

};
#endif