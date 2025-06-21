#ifndef __FLOOR_BUTTON_UP_HANDLER__
#define __FLOOR_BUTTON_UP_HANDLER__

#include <vector>
#include "../elevator_car_controller_interface.h"

class FloorButtonUpHandler {
public:
    FloorButtonUpHandler();
    virtual void handleFloorButtonUpPress(int floor_number, std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers) = 0;
};

#endif
