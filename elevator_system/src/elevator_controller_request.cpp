#include "elevator_controller_request.h"

ElevatorControllerRequest::ElevatorControllerRequest() {}

void ElevatorControllerRequest::addElevatorCarNumberRequest(int number) {
    m_elevator_car_number_requests.insert(number);
}

void ElevatorControllerRequest::removeElevatorCarNumberRequest(int number) {
    m_elevator_car_number_requests.erase(number);
}

void ElevatorControllerRequest::addFloorRequest(int floor, DIRECTION direction) {
    if (direction == DIRECTION::UP) {
        m_floor_up_requests.insert(floor);
    } else if (direction == DIRECTION::DOWN) {
        m_floor_down_requests.insert(floor);
    }
}

void ElevatorControllerRequest::removeFloorRequest(int floor, DIRECTION direction) {
    if (direction == DIRECTION::UP) {
        m_floor_up_requests.erase(floor);
    } else if (direction == DIRECTION::DOWN) {
        m_floor_down_requests.erase(floor);
    }
}

bool ElevatorControllerRequest::hasFloorRequest(int floor, DIRECTION direction) {
    if (direction == DIRECTION::UP) {
        return m_floor_up_requests.find(floor) != m_floor_up_requests.end();
    } else if (direction == DIRECTION::DOWN) {
        return m_floor_down_requests.find(floor) != m_floor_down_requests.end();
    }
    return false;
}

bool ElevatorControllerRequest::hasElevatorCarNumberRequest(int number) {
    return m_elevator_car_number_requests.find(number) != m_elevator_car_number_requests.end();
}