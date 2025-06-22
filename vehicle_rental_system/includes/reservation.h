#ifndef __RESERVATION_H__
#define __RESERVATION_H__

#include "user.h"
#include "vehicle.h"
#include "reservation_status.h"

class Reservation {
    private:
        static int m_reservation_id_gen;
        int m_reservation_id;
        User* m_user;
        Vehicle* m_vehicle;
        std::string m_booking_date;
        std::string m_start_date;
        std::string m_end_date;
        ReservationStatus m_status;
    public:
        Reservation(User* user, Vehicle* vehicle, 
                    std::string booking_date, std::string start_date, 
                    std::string end_date);
        void setStatus(ReservationStatus status);
        ReservationStatus getStatus() ;
        int getReservationId() ;
        User* getUser();
        Vehicle* getVehicle();
        std::string getBookingDate();
        std::string getStartDate();
        std::string getEndDate();
};

#endif