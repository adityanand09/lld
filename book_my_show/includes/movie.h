#ifndef __MOVIE_H__
#define __MOVIE_H__

#include <string>

class Movie {
    private:
        static int m_id_gen;
        int m_id;
        std::string m_movie_name;
        int m_duration;
    public:
        Movie(std::string movie_name, int duration);
        int getId();
        std::string getMovieName();
        int getDuration();

};

#endif