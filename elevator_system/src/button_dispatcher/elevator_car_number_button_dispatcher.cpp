#include "button_dispatcher/elevator_car_number_button_dispatcher.h"

ElevatorCarNumberButtonDispatcher::ElevatorCarNumberButtonDispatcher(ElevatorCarNumberButtonHandler* elevator_car_number_button_handler, ElevatorCarControllerInterface* elevator_car_controller, int elevator_id, int floor_number)
	: ElevatorCarButtonDispatcher(elevator_car_controller){
		m_elevator_car_number_button_handler = elevator_car_number_button_handler;
		m_elevator_id = elevator_id;
		m_floor_number = floor_number;
}

void ElevatorCarNumberButtonDispatcher::performAction() {
	m_elevator_car_number_button_handler->handleElevatorCarNumberButtonPress(m_elevator_id, m_floor_number, m_elevator_car_controller);
}

int ElevatorCarNumberButtonDispatcher::getFloorNumber() {
	return m_floor_number;
}