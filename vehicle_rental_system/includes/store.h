#ifndef __STORE_H__
#define __STORE_H__

#include <string>
#include <vector>
#include "location.h"
#include "vehicle.h"
#include "inventory.h"
#include "payment.h"

class Store {
    private:
        std::string m_store_id;
        Location* m_location;
        Inventory* m_inventory;
        std::vector<Reservation*> m_reservations;
    public:
        Store(std::string store_id, Location* location);
        void addVehicle(Vehicle* vehicle);
        void removeVehicle(const std::string vehicle_number);
        Vehicle* getVehicle(const std::string vehicle_number);
        std::vector<Vehicle*> getAllVehicles();
        std::vector<Vehicle*> getVehicles(VehicleType vehicle_type);
        std::string getStoreId();
        Location* getLocation();
        Vehicle* chooseVehicle(VehicleType vehicle_type);
        Reservation* createReservation(User* user, Vehicle* vehicle, std::string booking_date, std::string start_date, std::string end_date);
        Invoice* generateInvoice(Reservation* reservation);
        bool processPayment(Invoice* invoice, Payment* payment);
        void pickVehicle(User* user, Reservation* reservation);
        void returnVehicle(User* user, Reservation* reservation, Vehicle* vehicle);
};

#endif