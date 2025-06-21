#ifndef __ELEVATOR_CAR__
#define __ELEVATOR_CAR__

#include "sensor/floor_sensor.h"
#include "display.h"
#include "button_panel.h"

class ButtonPanel;

class ElevatorCar {
private:
	int m_elevator_id;
	int m_current_floor;
	FloorSensor* m_sensor;
	Display *m_display;
	DIRECTION m_direction;
	ButtonPanel *m_button_panel;
	ELEVATOR_CAR_STATUS m_elevator_car_status;
	
public:
	ElevatorCar(FloorSensor* sensor, Display* display, ButtonPanel* button_panel);
	void move(DIRECTION direction);
	void stop();
	int getElevatorId();
	DIRECTION getDirection();
	int getCurrentFloor();
	ELEVATOR_CAR_STATUS getElevatorCarStatus();
	ButtonPanel* getElevatorCarButtonPanel();
	void updateCurrentFloor();
	void updateDisplay();
};

#endif