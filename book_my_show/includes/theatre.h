#ifndef __THEATRE_H__
#define __THEATRE_H__

#include "city.h"
#include "screen.h"
#include "show.h"
#include <vector>

class Theatre {
    private:
        static int m_id_gen;
        int m_id;
        City* m_city;
        std::string m_theatre_name;
        std::vector<Screen*> m_screens;
        std::vector<Show*> m_shows;
    public:
        Theatre(std::string theatre_name, City* city);

        // setters
        void addScreen(Screen* screen);
        void addShow(Show* show);

        // getters
        std::vector<Show*> getShows();
        std::string getTheatreName();
        std::vector<Screen*> getScreens();
};
#endif