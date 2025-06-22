#include "store.h"
#include "user.h"
#include "invoice.h"

Store::Store(std::string store_id, Location* location) {
    m_store_id = store_id;
    m_location = location;
    m_inventory = new Inventory();
}

void Store::addVehicle(Vehicle* vehicle) {
    m_inventory->addVehicle(vehicle);
}

void Store::removeVehicle(const std::string vehicle_number) {
    m_inventory->removeVehicle(vehicle_number);
}

Vehicle* Store::getVehicle(const std::string vehicle_number) {
    return m_inventory->getVehicle(vehicle_number);
}

std::vector<Vehicle*> Store::getAllVehicles() {
    return m_inventory->getAllVehicles();
}

std::vector<Vehicle*> Store::getVehicles(VehicleType vehicle_type) {
    return m_inventory->getVehicles(vehicle_type);
}

std::string Store::getStoreId() {
    return m_store_id;
}

Location* Store::getLocation() {
    return m_location;
}

Vehicle* Store::chooseVehicle(VehicleType vehicle_type) {
    std::vector<Vehicle*> vehicles = m_inventory->getVehicles(vehicle_type);
    if (!vehicles.empty()) {
        for (auto& vehicle : vehicles) {
            if (vehicle->getVehicleStatus() == VehicleStatus::AVAILABLE) {
                return vehicle;
            } else if (vehicle->getVehicleStatus() == VehicleStatus::RESERVED) {
                // check reservations to see if the vehicle can be made available
                // make this vehicle available if the reservation is expired
                for (Reservation* reservation : m_reservations) {
                    if (reservation->getVehicle()->getVehicleNumber() == vehicle->getVehicleNumber()) {
                        if (reservation->getStatus() == ReservationStatus::PENDING) {
                            int current_date = 10;
                            int booking_date = std::stoi(reservation->getBookingDate());
                            int booking_period = 5;
                            if (current_date - booking_date > booking_period) {
                                reservation->setStatus(ReservationStatus::CANCELLED);
                                vehicle->setVehicleStatus(VehicleStatus::AVAILABLE);
                                return vehicle; // Return the vehicle as available
                            }
                        } else if (reservation->getStatus() == ReservationStatus::CONFIRMED) {
                            int current_date = 10;
                            int booking_end_date = std::stoi(reservation->getEndDate());
                            if (current_date > booking_end_date) {
                                if (vehicle->getVehicleStatus() == VehicleStatus::RESERVED) {
                                    reservation->setStatus(ReservationStatus::COMPLETED);
                                    vehicle->setVehicleStatus(VehicleStatus::AVAILABLE);
                                    return vehicle; // Return the vehicle as available
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return nullptr;
}

Reservation* Store::createReservation(User* user, Vehicle* vehicle, std::string booking_date, std::string start_date, std::string end_date) {
    if (vehicle->getVehicleStatus() == VehicleStatus::AVAILABLE) {
        Reservation* reservation = new Reservation(user, vehicle, booking_date, start_date, end_date);
        m_reservations.push_back(reservation);
        vehicle->setVehicleStatus(VehicleStatus::RESERVED);
        user->addReservation(reservation);
        return reservation;
    }
    return nullptr;
}

Invoice* Store::generateInvoice(Reservation* reservation) {
    if (reservation->getStatus() != ReservationStatus::PENDING) {
        return nullptr;
    }
    return new Invoice(reservation->getBookingDate(), reservation);
}

bool Store::processPayment(Invoice* invoice, Payment* payment) {
    if (invoice->getReservation()->getStatus() != ReservationStatus::PENDING) {
        return false; // Cannot process payment for non-pending reservations
    }
    if (payment->processPayment(invoice)) {
        invoice->getReservation()->setStatus(ReservationStatus::CONFIRMED);
        return true;
    }
    return false;
}

void Store::pickVehicle(User* user, Reservation* reservation) {
    if (reservation->getUser()->getUserId() != user->getUserId()) {
        return; // User does not match the reservation
    }
    if (reservation->getStatus() != ReservationStatus::CONFIRMED) {
        return; // Reservation is not confirmed
    }
    Vehicle* vehicle = reservation->getVehicle();
    vehicle->setVehicleStatus(VehicleStatus::VEHICLE_PICKED_UP);
}

void Store::returnVehicle(User* user, Reservation* reservation, Vehicle* vehicle) {
    if (reservation->getUser()->getUserId() != user->getUserId()) {
        return; // User does not match the reservation
    }
    if (reservation->getVehicle()->getVehicleNumber() != vehicle->getVehicleNumber()) {
        return; // Reservation is not confirmed
    }
    vehicle->setVehicleStatus(VehicleStatus::AVAILABLE);
    reservation->setStatus(ReservationStatus::COMPLETED);
}