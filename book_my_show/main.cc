#include <iostream>
#include "book_my_show.h"
#include "booking.h"

bool isSeatBooked(Show* show, int seat_no) {
    std::vector<int> booked_seat_ids = show->getAllBooking();
    for (int seat_id : booked_seat_ids) {
        if (seat_id == seat_no) {
            return true;
        }
    }
    return false;
}

void createBooking(BookMyShow* bms, std::string movie_name, std::string city_name) {
    
    City* city = new City(city_name);
    // select the movie
    std::vector<Movie*> movie_list = bms->getMovieController()->getMoviesByCity(city);
    Movie* interested_movie = nullptr;
    for (Movie* movie : movie_list) {
        if (movie->getMovieName() == movie_name) {
            interested_movie = movie;
            break;
        }
    }
    
    // get all shows in choosen city
    std::unordered_map<Theatre*, std::vector<Show*>> theatre_shows = bms->getTheatreController()->getAllShows(interested_movie, city);
    Show* interested_show = theatre_shows.begin()->second[0];
    int interested_seat = 101;
    if (!isSeatBooked(interested_show, interested_seat)) {
        interested_show->addBookedSeatId(interested_seat);
        
        // create booking
        std::vector<Seat*> seats;
        for (Seat* seat : interested_show->getScreen()->getSeats()) {
            if (seat->getId() == interested_seat) {
                seats.push_back(seat);
            }
        }
        Booking* booking = new Booking(interested_show, seats);
        booking->makePayment();
        std::cout << "Booking success for " << movie_name << " at " << theatre_shows.begin()->first->getTheatreName() << " at time : " << interested_show->getStartTime() << std::endl;
    } else {
        std::cout << "Booking failed : Seat already booked" << std::endl;
    }
    
}

int main() {
    BookMyShow* bms = new BookMyShow();
    bms->init();
    createBooking(bms, "Golmaal", "Bangalore");
    createBooking(bms, "Hulchal", "Bangalore");
    createBooking(bms, "Golmaal", "Delhi");
    createBooking(bms, "Golmaal", "Bangalore");
}