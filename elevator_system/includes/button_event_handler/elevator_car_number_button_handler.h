#ifndef __ELEVATOR_CAR_NUMBER_BUTTON_HANDLER__
#define __ELEVATOR_CAR_NUMBER_BUTTON_HANDLER__

#include <vector>
#include "../elevator_car_controller_interface.h"

class ElevatorCarNumberButtonHandler {
public:
    ElevatorCarNumberButtonHandler();
    virtual void handleElevatorCarNumberButtonPress(int elevator_id, int floor_number, ElevatorCarControllerInterface* elevator_car_controller) = 0;
};

#endif
