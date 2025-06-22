#include <iostream>
#include "vehicle_rental_system.h"
#include "store.h"
#include "user.h"
#include "car.h"
#include "bike.h"
#include "online_payment.h"
#include "cash_payment.h"

int main() {
    VehicleRentalSystem* vehicleRentalSystem = new VehicleRentalSystem();
    Store* store1 = new Store("store1", new Location("123 Main St", "CityA", "StateA", "12345"));
    Store* store2 = new Store("store2", new Location("456 Elm St", "CityB", "StateB", "67890"));
    store1->addVehicle(new Car("car1"));
    store1->addVehicle(new Bike("bike1"));
    store2->addVehicle(new Car("car2"));
    store2->addVehicle(new Bike("bike2"));
    User* user1 = new User("user1", "Alice");
    User* user2 = new User("user2", "Bob");
    vehicleRentalSystem->addStore(store1);
    vehicleRentalSystem->addStore(store2);
    vehicleRentalSystem->registerUser(user1);
    vehicleRentalSystem->registerUser(user2);

    // get user1 a vehicle (car)
    Location* user1Location = new Location("123 Main St", "CityA", "StateA", "12345");
    Store* user1Store = vehicleRentalSystem->getStore(user1Location);
    if (user1Store) {
        Vehicle* car1 = user1Store->chooseVehicle(VehicleType::CAR);
        if (car1) {
            Reservation* reservation = user1Store->createReservation(user1, car1, "2023-10-01", "2023-10-02", "2023-10-05");
            if (reservation) {
                // Process payment
                Invoice* invoice = user1Store->generateInvoice(reservation);
                user1Store->processPayment(invoice, new OnlinePayment());
                user1Store->pickVehicle(user1, reservation);
                user1Store->returnVehicle(user1, reservation, car1);
            } else {
                std::cout << "Failed to create reservation." << std::endl;
            }
        }
    } else {
        std::cout << "Store not found." << std::endl;
    }

    // get user2 a vehicle (car)
    Location* user2Location = new Location("456 Elm St", "CityB", "StateB", "67890");
    Store* user2Store = vehicleRentalSystem->getStore(user2Location);
    if (user2Store) {
        Vehicle* bike1 = user2Store->chooseVehicle(VehicleType::BIKE);
        if (bike1) {
            Reservation* reservation = user2Store->createReservation(user2, bike1, "2025-10-01", "2025-10-02", "2025-10-05");
            if (reservation) {
                // Process payment
                Invoice* invoice = user2Store->generateInvoice(reservation);
                user2Store->processPayment(invoice, new CashPayment());
                user2Store->pickVehicle(user2, reservation);
                // lets assume user2 didn't return the vehicle
                // user2Store->returnVehicle(user2, reservation, bike1);
            } else {
                std::cout << "Failed to create reservation." << std::endl;
            }
        }
    } else {
        std::cout << "Store not found." << std::endl;
    }
}