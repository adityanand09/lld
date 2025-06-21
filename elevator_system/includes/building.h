#ifndef __BUILDING__
#define __BUILDING__

#include "floor.h"
#include "elevator_system.h"
#include <vector>

class Building {
private:
	int m_floor_count;
	std::vector<Floor*> m_floors;
	ElevatorSystem* m_elevator_system;
public:
	Building();
	void addFloors(std::vector<Floor*> floors);
	void addFLoor(Floor* floor);
	void attatchElevatorSystem(ElevatorSystem* elevator_system);
};

#endif