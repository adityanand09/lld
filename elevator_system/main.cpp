#include "building.h"
#include "floor.h"
#include <iostream>

int main() {
	// create a building
	Building *building = new Building();
	// create floor list
	std::vector<Floor*> floors;
	for (int i=0; i<10; i++) {
		Floor *floor = new Floor(i);
		floors.push_back(floor);
	}
	// add floors to the building
	building->addFloors(floors);

	// create an elevator system
	ElevatorSystem *elevator_system = new ElevatorSystem();
	elevator_system->supportNewElevatorCar();
	elevator_system->supportNewElevatorCar();

	// attatch elevator system to the building
	building->attatchElevatorSystem(elevator_system);


	Floor *floor = new Floor(10);
	building->addFLoor(floor);
	
	elevator_system->supportNewElevatorCar();
}