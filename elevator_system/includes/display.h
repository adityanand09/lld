#ifndef __DISPLAY__
#define __DISPLAY__

#include <enums.h>

class Display {

private:
	
	DIRECTION m_direction;
	int m_current_floor;

public:

	Display();

	void updateDirection(DIRECTION direction);

	void updateCurrentFloor(int current_floor);
};

#endif