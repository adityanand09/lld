#ifndef __ELEVATOR_CONTROLLER_REQUEST__
#define __ELEVATOR_CONTROLLER_REQUEST__

#include <set>
#include "enums.h"

class ElevatorControllerRequest {
    private:
        std::set<int> m_floor_up_requests;
        std::set<int> m_floor_down_requests;
        std::set<int> m_elevator_car_number_requests;
    public:
        ElevatorControllerRequest();
        void addElevatorCarNumberRequest(int number);
        void removeElevatorCarNumberRequest(int number);
        void addFloorRequest(int floor, DIRECTION direction);
        void removeFloorRequest(int floor, DIRECTION direction);
        bool hasFloorRequest(int floor, DIRECTION direction);
        bool hasElevatorCarNumberRequest(int number);
};

#endif
