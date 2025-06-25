#ifndef __SHOW_H__
#define __SHOW_H__

#include "screen.h"
#include "movie.h"
#include <vector>

class Booking;

class Show {
    private:
        static int m_id_gen;
        int m_id;
        Screen* m_screen;
        Movie* m_movie;
        int m_start_time;
        std::vector<int> m_booked_seat_ids;
    public:
        Show(Screen* screen, Movie* movie, int start_time);
        
        // getters
        int getId();
        Screen* getScreen();
        Movie* getMovie();
        int getStartTime();
        std::vector<int> getAllBooking();
        
        // setters
        void addBookedSeatId(int seat_id);
};
#endif