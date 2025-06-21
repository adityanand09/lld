#include "button_dispatcher/floor_button_up_dispatcher.h"

FloorButtonUpDispatcher::FloorButtonUpDispatcher(FloorButtonUpHandler* floor_button_up_handler, std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers, int floor_number)
	: FloorButtonDispatcher(elevator_car_controllers) {
	m_floor_button_up_handler = floor_button_up_handler;
	m_floor_number = floor_number;
}

void FloorButtonUpDispatcher::performAction() {
	m_floor_button_up_handler->handleFloorButtonUpPress(m_floor_number, m_elevator_car_controllers);
}

int FloorButtonUpDispatcher::getFloorNumber() {
	return m_floor_number;
}