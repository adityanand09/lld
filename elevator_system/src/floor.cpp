#include "floor.h"

Floor::Floor(int floor_number) {
	m_floor_number = floor_number;
}

void Floor::attatchButtonPanel(ButtonPanel* button_panel) {
	m_button_panel = button_panel;
}

int Floor::getFloorNumber() {
	return m_floor_number;
}