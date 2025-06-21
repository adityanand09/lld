#ifndef __FLOOR_BUTTON_DISPATCHER__
#define __FLOOR_BUTTON_DISPATCHER__

#include "elevator_car_controller.h"
#include "button_dispatcher.h"
#include <vector>

class FloorButtonDispatcher : public ButtonDispatcher {
protected:
	std::vector<ElevatorCarControllerInterface*> *m_elevator_car_controllers;
public:
	FloorButtonDispatcher(std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers);
	virtual void performAction() = 0;
};

#endif