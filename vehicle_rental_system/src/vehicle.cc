#include "vehicle.h"
#include "vehicle_status.h"

Vehicle::Vehicle(std::string vehicle_number, VehicleType vehicle_type) {
    m_vehicle_number = vehicle_number;
    m_vehicle_type = vehicle_type;
    m_vehicle_status = VehicleStatus::AVAILABLE;
}

void Vehicle::setVehicleStatus(VehicleStatus vehicle_status) {
    m_vehicle_status = vehicle_status;
}

VehicleStatus Vehicle::getVehicleStatus() {
    return m_vehicle_status;
}

VehicleType Vehicle::getVehicleType() {
    return m_vehicle_type;
}

std::string Vehicle::getVehicleNumber() {
    return m_vehicle_number;
}