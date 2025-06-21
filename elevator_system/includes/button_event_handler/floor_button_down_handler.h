#ifndef __FLOOR_BUTTON_DOWN_HANDLER__
#define __FLOOR_BUTTON_DOWN_HANDLER__

#include <vector>
#include "../elevator_car_controller_interface.h"

class FloorButtonDownHandler {
public:
    FloorButtonDownHandler();
    virtual void handleFloorButtonDownPress(int floor_number, std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers) = 0;
};

#endif
