#include "button_dispatcher/elevator_car_button_dispatcher.h"

ElevatorCarButtonDispatcher::ElevatorCarButtonDispatcher(ElevatorCarControllerInterface* elevator_car_controller) {
	m_elevator_car_controller = elevator_car_controller;
}