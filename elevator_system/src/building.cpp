#include "building.h"

Building::Building() {
	m_floor_count = 0;
	m_elevator_system = nullptr;
}

void Building::addFloors(std::vector<Floor*> floors) {
	for (Floor* floor : floors) {
		m_floors.push_back(floor);
		if (m_elevator_system != nullptr) {
			m_elevator_system->supportNewFloor(floor);
		}
		m_floor_count += 1;
	}
}

void Building::addFLoor(Floor* floor) {
	m_floors.push_back(floor);
	if (m_elevator_system != nullptr) {
		m_elevator_system->supportNewFloor(floor);
	}
	m_floor_count += 1;
}

void Building::attatchElevatorSystem(ElevatorSystem* elevator_system) {
	if (m_elevator_system != nullptr) {
		// assuming a building can have only one elevator system
		return;
	}
	m_elevator_system = elevator_system;
	for (int i=0; i<m_floor_count; i++) {
		m_elevator_system->supportNewFloor(m_floors[i]);
	}
}