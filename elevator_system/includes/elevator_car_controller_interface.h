#ifndef __ELEVATOR_CAR_CONTROLLER_INTERFACE__
#define __ELEVATOR_CAR_CONTROLLER_INTERFACE__

#include "enums.h"
#include "elevator_controller_request.h"

class ElevatorCarControllerInterface {
public:
    virtual int getCurrentFloor() = 0;
	virtual DIRECTION getDirection() = 0;
	virtual ELEVATOR_CAR_STATUS getElevatorCarStatus() = 0;
	virtual void move(DIRECTION direction) = 0;
	virtual void stop() = 0;
	virtual ElevatorControllerRequest* getElevatorControllerRequest() = 0;
};

#endif
