#ifndef __FLOOR_BUTTON_DOWN_DISPATCHER__
#define __FLOOR_BUTTON_DOWN_DISPATCHER__

#include "floor_button_dispatcher.h"
#include "button_event_handler/floor_button_down_handler.h"

class FloorButtonDownDispatcher : public FloorButtonDispatcher {
private:
	FloorButtonDownHandler* m_floor_button_down_handler;
	int m_floor_number;
public:
	FloorButtonDownDispatcher(FloorButtonDownHandler* floor_button_down_handler, std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers, int floor_number);
	void performAction();
	int getFloorNumber();
};

#endif