#ifndef __ENUMS__
#define __ENUMS__

enum DIRECTION {
	UP,
	DOWN,
	NOT_MOVING
};

enum ELEVATOR_CAR_STATUS {
	IDLE, // elevator car is not moving
	MOVING, // elevator car is moving
};

enum BUTTON_STATUS {
	ACTIVE, // showing elevator system is currently serving this button's request.
	INACTIVE // showing elevator system has no request from this button.
};

#endif