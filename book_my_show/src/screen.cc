#include "screen.h"

int Screen::m_id_gen = 0;

Screen::Screen() {
    m_id = m_id_gen;
    m_id_gen++;
}

int Screen::getId() {
    return m_id;
}

void Screen::addSeat(Seat* seat) {
    m_seats.push_back(seat);
}

std::vector<Seat*> Screen::getSeats() {
    return m_seats;
}