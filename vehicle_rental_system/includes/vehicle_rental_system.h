#ifndef __VEHICLE_RENTAL_SYSTEM_H__
#define __VEHICLE_RENTAL_SYSTEM_H__

#include <vector>
#include "store.h"
#include "user.h"
#include "location.h"

class VehicleRentalSystem {
    private:
        std::vector<Store*> m_stores;
        std::vector<User*> m_users;
    public:
        VehicleRentalSystem();
        void addStore(Store* store);
        void removeStore(const std::string store_id);
        Store* getStore(Location* location);
        void registerUser(User* user);
        void removeUser(const std::string user_id);
        User* getUser(const std::string user_id);
};

#endif