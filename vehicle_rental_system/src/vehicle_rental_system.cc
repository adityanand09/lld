#include "vehicle_rental_system.h"

VehicleRentalSystem::VehicleRentalSystem() {}

void VehicleRentalSystem::addStore(Store* store) {
    m_stores.push_back(store);
}

void VehicleRentalSystem::removeStore(const std::string store_id) {
    for (auto it = m_stores.begin(); it != m_stores.end(); ++it) {
        if ((*it)->getStoreId() == store_id) {
            m_stores.erase(it);
            return;
        }
    }
}

Store* VehicleRentalSystem::getStore(Location* location) {
    for (auto& store : m_stores) {
        if (store->getLocation()->getAddress() == location->getAddress() &&
            store->getLocation()->getCity() == location->getCity() &&
            store->getLocation()->getState() == location->getState() &&
            store->getLocation()->getZipCode() == location->getZipCode()) {
            return store;
        }
    }
    return nullptr;
}

void VehicleRentalSystem::registerUser(User* user) {
    m_users.push_back(user);
}

void VehicleRentalSystem::removeUser(const std::string user_id) {
    for (auto it = m_users.begin(); it != m_users.end(); ++it) {
        if ((*it)->getUserId() == user_id) {
            m_users.erase(it);
            return;
        }
    }
}

User* VehicleRentalSystem::getUser(const std::string user_id) {
    for (auto& user : m_users) {
        if (user->getUserId() == user_id) {
            return user;
        }
    }
    return nullptr;
}