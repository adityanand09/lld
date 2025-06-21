#include "elevator_car_controller.h"
#include "button/number_button.h"

ElevatorCarController::ElevatorCarController(ElevatorControllerRequestProcessor* elevator_controller_request_processor, ElevatorCar* elevator_car) {
	m_elevator_controller_request_processor = elevator_controller_request_processor;
	m_elevator_car = elevator_car;
	m_requests = new ElevatorControllerRequest();
}

int ElevatorCarController::getElevatorId() {
	return m_elevator_car->getElevatorId();
}

void ElevatorCarController::addNumberButton(int floor_number, ButtonDispatcher* button_dispatcher) {
	ButtonPanel* button_panel = m_elevator_car->getElevatorCarButtonPanel();
	NumberButton* number_button = new NumberButton(button_dispatcher, floor_number);
	button_panel->addButton(number_button);
}

void ElevatorCarController::acceptRequest(int floor_number, DIRECTION direction) {
	m_requests->addFloorRequest(floor_number, direction);
	m_elevator_controller_request_processor->processElevatorControllerRequests(this);
}

void ElevatorCarController::notify() {
	m_elevator_car->updateCurrentFloor();
	m_elevator_controller_request_processor->processElevatorControllerRequests(this);
}

int ElevatorCarController::getCurrentFloor() {
    return m_elevator_car->getCurrentFloor();
}

DIRECTION ElevatorCarController::getDirection() {
    return m_elevator_car->getDirection();
}

ELEVATOR_CAR_STATUS ElevatorCarController::getElevatorCarStatus() {
    return m_elevator_car->getElevatorCarStatus();
}

void ElevatorCarController::move(DIRECTION direction) {
    m_elevator_car->move(direction);
}

void ElevatorCarController::stop() {
    m_elevator_car->stop();
}

ElevatorControllerRequest* ElevatorCarController::getElevatorControllerRequest() {
	return m_requests;
}

void ElevatorCarController::updateTopFloor(int top_floor) {
	m_top_floor = top_floor;
}

void ElevatorCarController::updateBottomFloor(int bottom_floor) {
	m_bottom_floor = bottom_floor;
}

bool ElevatorCarController::isAtTopFloor() {
	return m_elevator_car->getCurrentFloor() == m_top_floor;
}

bool ElevatorCarController::isAtBottomFloor() {
	return m_elevator_car->getCurrentFloor() == m_bottom_floor;
}