#include "button_dispatcher/floor_button_dispatcher.h"

FloorButtonDispatcher::FloorButtonDispatcher(std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers) {
	m_elevator_car_controllers = elevator_car_controllers;
}