#ifndef __ELEVATOR_CAR_BUTTON_DISPATCHER__
#define __ELEVATOR_CAR_BUTTON_DISPATCHER__

#include "../elevator_car_controller_interface.h"
#include "button_dispatcher.h"
#include <vector>

class ElevatorCarButtonDispatcher : public ButtonDispatcher {
protected:
	ElevatorCarControllerInterface* m_elevator_car_controller;
public:
	ElevatorCarButtonDispatcher(ElevatorCarControllerInterface* elevator_car_controller);
	virtual void performAction() = 0;
};

#endif