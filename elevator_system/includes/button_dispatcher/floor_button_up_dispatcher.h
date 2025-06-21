#ifndef __FLOOR_BUTTON_UP_DISPATCHER__
#define __FLOOR_BUTTON_UP_DISPATCHER__

#include "floor_button_dispatcher.h"
#include "button_event_handler/floor_button_up_handler.h"

class FloorButtonUpDispatcher : public FloorButtonDispatcher {
private:
	FloorButtonUpHandler* m_floor_button_up_handler;
	int m_floor_number;
public:
	FloorButtonUpDispatcher(FloorButtonUpHandler* floor_button_up_handler, std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers, int floor_number);
	void performAction();
	int getFloorNumber();
};

#endif