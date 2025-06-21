#include "elevator_car.h"

ElevatorCar::ElevatorCar(FloorSensor* sensor, Display* display, ButtonPanel* button_panel) {
	m_sensor = sensor;
	m_display = display;
	m_button_panel = button_panel;
}

int ElevatorCar::getElevatorId() {
	return m_elevator_id;
}

ButtonPanel* ElevatorCar::getElevatorCarButtonPanel() {
	return m_button_panel;
}

void ElevatorCar::updateCurrentFloor() {
	m_current_floor = m_sensor->getFloorNumber();
	updateDisplay();
}

void ElevatorCar::updateDisplay() {
	m_display->updateDirection(m_direction);
	m_display->updateCurrentFloor(m_current_floor);
}

void ElevatorCar::move(DIRECTION direction) {
	m_direction = direction;
	m_elevator_car_status = MOVING;
	updateDisplay();
	// some logic to move the elevator car
}

void ElevatorCar::stop() {
	m_direction = NOT_MOVING;
	m_elevator_car_status = IDLE;
	updateDisplay();
	// some logic to stop the elevator car
}

DIRECTION ElevatorCar::getDirection() {
	return m_direction;
}

ELEVATOR_CAR_STATUS ElevatorCar::getElevatorCarStatus() {
	return m_elevator_car_status;
}

int ElevatorCar::getCurrentFloor() {
	return m_current_floor;
}


