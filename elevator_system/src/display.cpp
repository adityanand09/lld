#include "display.h"

Display::Display() {
	m_direction = NOT_MOVING;
	m_current_floor = 0;
}

void Display::updateDirection(DIRECTION direction) {
	m_direction = direction;
}

void Display::updateCurrentFloor(int current_floor) {
	m_current_floor = current_floor;
}