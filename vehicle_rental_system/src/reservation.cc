#include "reservation.h"

int Reservation::m_reservation_id_gen = 0;

Reservation::Reservation(User* user, Vehicle* vehicle, 
                         std::string booking_date, std::string start_date, 
                         std::string end_date)
    : m_user(user), m_vehicle(vehicle), 
      m_booking_date(booking_date), m_start_date(start_date), 
      m_end_date(end_date), m_status(ReservationStatus::PENDING) {
        m_reservation_id = m_reservation_id_gen;
        m_reservation_id_gen++;
}

void Reservation::setStatus(ReservationStatus status) {
    m_status = status;
}

ReservationStatus Reservation::getStatus() {
    return m_status;
}

int Reservation::getReservationId() {
    return m_reservation_id;
}

User* Reservation::getUser() {
    return m_user;
}

Vehicle* Reservation::getVehicle() {
    return m_vehicle;
}

std::string Reservation::getBookingDate() {
    return m_booking_date;
}

std::string Reservation::getStartDate() {
    return m_start_date;
}

std::string Reservation::getEndDate() {
    return m_end_date;
}