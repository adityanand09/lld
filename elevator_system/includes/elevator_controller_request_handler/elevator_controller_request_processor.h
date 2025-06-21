#ifndef __ELEVATOR_CONTROLLER_REQUEST_PROCESSOR__
#define __ELEVATOR_CONTROLLER_REQUEST_PROCESSOR__

#include "../elevator_car_controller_interface.h"

class ElevatorControllerRequestProcessor {
public:
    ElevatorControllerRequestProcessor();
    virtual void processElevatorControllerRequests(ElevatorCarControllerInterface* elevator_car_controller_interface) = 0;

};

#endif