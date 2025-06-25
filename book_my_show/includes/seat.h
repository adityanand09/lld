#ifndef __SEAT_H__
#define __SEAT_H__

#include "seat_category.h"

class Seat {
    private:
        int m_id;
        int m_row;
        SeatCategory m_seat_category;
    public:
        Seat(int id, int row, SeatCategory seat_category);
        int getId();
        int getRow();
        SeatCategory getSeatCategory();
};

#endif