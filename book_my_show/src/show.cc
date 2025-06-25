#include "show.h"

int Show::m_id_gen = 0;

Show::Show(Screen* screen, Movie* movie, int start_time) : m_screen(screen), m_movie(movie), m_start_time(start_time) {
    m_id = m_id_gen;
    m_id_gen++;
}

// getters
int Show::getId() {
    return m_id;
}

Screen* Show::getScreen() {
    return m_screen;
}

Movie* Show::getMovie() {
    return m_movie;
}

int Show::getStartTime() {
    return m_start_time;
}

std::vector<int> Show::getAllBooking() {
    return m_booked_seat_ids;
}

// setters
void Show::addBookedSeatId(int seat_id) {
    m_booked_seat_ids.push_back(seat_id);
}