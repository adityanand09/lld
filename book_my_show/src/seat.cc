#include "seat.h"

Seat::Seat(int id, int row, SeatCategory seat_category) : m_id(id), m_row(row), m_seat_category(seat_category) {}

int Seat::getId() {
    return m_id;
}

int Seat::getRow() {
    return m_row;
}

SeatCategory Seat::getSeatCategory() {
    return m_seat_category;
}