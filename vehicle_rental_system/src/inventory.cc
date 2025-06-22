#include "inventory.h"

Inventory::Inventory() {}
void Inventory::addVehicle(Vehicle* vehicle) {
    m_vehicles.push_back(vehicle);
    vehicle->setVehicleStatus(VehicleStatus::AVAILABLE);
}

void Inventory::removeVehicle(const std::string vehicle_number) {
    for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it) {
        if ((*it)->getVehicleNumber() == vehicle_number) {
            m_vehicles.erase(it);
            return;
        }
    }
}

Vehicle* Inventory::getVehicle(const std::string vehicle_number) {
    for (auto& vehicle : m_vehicles) {
        if (vehicle->getVehicleNumber() == vehicle_number) {
            return vehicle;
        }
    }
    return nullptr;
}

std::vector<Vehicle*> Inventory::getAllVehicles() {
    return m_vehicles;
}

std::vector<Vehicle*> Inventory::getVehicles(VehicleType vehicle_type) {
    std::vector<Vehicle*> filtered_vehicles;
    for (auto& vehicle : m_vehicles) {
        if (vehicle->getVehicleType() == vehicle_type) {
            filtered_vehicles.push_back(vehicle);
        }
    }
    return filtered_vehicles;
}