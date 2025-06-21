#include "button_dispatcher/floor_button_down_dispatcher.h"

FloorButtonDownDispatcher::FloorButtonDownDispatcher(FloorButtonDownHandler* floor_button_down_handler, std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers, int floor_number)
	: FloorButtonDispatcher(elevator_car_controllers) {
	m_floor_button_down_handler = floor_button_down_handler;
	m_floor_number = floor_number;
}

void FloorButtonDownDispatcher::performAction() {
	m_floor_button_down_handler->handleFloorButtonDownPress(m_floor_number, m_elevator_car_controllers);
}

int FloorButtonDownDispatcher::getFloorNumber() {
	return m_floor_number;
}