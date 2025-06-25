#include "booking.h"

int Booking::m_id_gen = 0;

Booking::Booking(Show* show, std::vector<Seat*> seats) : m_show(show), m_seats(seats) {
    m_id = m_id_gen;
    m_id_gen++;
}

std::vector<Seat*> Booking::getSeats() {
    return m_seats;
}

void Booking::makePayment() {
    // on the basis of movie and booked seat and time or any other factors make payment;
    payment->makePayment(1000);
}