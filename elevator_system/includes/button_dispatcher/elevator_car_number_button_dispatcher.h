#ifndef __ELEVATOR_CAR_NUMBER_BUTTON_DISPATCHER__
#define __ELEVATOR_CAR_NUMBER_BUTTON_DISPATCHER__

#include "elevator_car_button_dispatcher.h"
#include "button_event_handler/elevator_car_number_button_handler.h"

class ElevatorCarNumberButtonDispatcher : public ElevatorCarButtonDispatcher {
private:
	ElevatorCarNumberButtonHandler* m_elevator_car_number_button_handler;
	int m_elevator_id;
	int m_floor_number;
public:
	ElevatorCarNumberButtonDispatcher(ElevatorCarNumberButtonHandler* elevator_car_number_button_handler, ElevatorCarControllerInterface* elevator_car_controller, int elevator_id, int floor_number);
	void performAction();
	int getFloorNumber();
	int getElevatorId();
};

#endif