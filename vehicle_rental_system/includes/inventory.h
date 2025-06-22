#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <vector>
#include <string>
#include "vehicle.h"

class Inventory {
    private:
        std::vector<Vehicle*> m_vehicles;
    public:
        Inventory();
        void addVehicle(Vehicle* vehicle);
        void removeVehicle(const std::string vehicle_number);
        Vehicle* getVehicle(const std::string vehicle_number);
        std::vector<Vehicle*> getAllVehicles();
        std::vector<Vehicle*> getVehicles(VehicleType vehicle_type);
};

#endif