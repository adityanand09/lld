#ifndef __ELEVATOR_SYSTEM__
#define __ELEVATOR_SYSTEM__

#include <vector>
#include "elevator_car_controller.h"
#include "floor.h"
#include "dispatcher_logic/dispatcher_logic.h"

class ElevatorSystem {
private:
	std::vector<ElevatorCarController*> *m_elevator_car_controllers;
	std::vector<int> m_floor_numbers;
	DispatcherLogic* m_dispatcher_logic;
public:
	ElevatorSystem();
	void supportNewFloor(Floor* floor);
	void supportNewElevatorCar();
};

#endif