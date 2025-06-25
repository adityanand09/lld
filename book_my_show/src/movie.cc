#include "movie.h"

int Movie::m_id_gen = 0;

Movie::Movie(std::string movie_name, int duration) : m_movie_name(movie_name), m_duration(duration) {
    m_id = m_id_gen;
    m_id_gen++;
}

int Movie::getId() {
    return m_id;
}

std::string Movie::getMovieName() {
    return m_movie_name;
}

int Movie::getDuration() {
    return m_duration;
}