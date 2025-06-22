#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include <string>
#include "vehicle_status.h"
#include "vehicle_type.h"

class Vehicle {
    private:
        std::string m_vehicle_number;
        VehicleType m_vehicle_type;
        VehicleStatus m_vehicle_status;
    public:
        Vehicle(std::string vehicle_number, VehicleType vehicle_type);
        void setVehicleStatus(VehicleStatus vehicle_status);
        VehicleStatus getVehicleStatus();
        VehicleType getVehicleType();
        std::string getVehicleNumber();    
};

#endif