#include "elevator_system.h"
#include "button_dispatcher/elevator_car_number_button_dispatcher.h"
#include "button_dispatcher/floor_button_down_dispatcher.h"
#include "button_dispatcher/floor_button_up_dispatcher.h"
#include "button/number_button.h"
#include "button/button_down.h"
#include "button/button_up.h"
#include "sensor/floor_sensor.h"
#include "dispatcher_logic/scan_dispatcher_logic.h"

ElevatorSystem::ElevatorSystem() {
	m_dispatcher_logic = new ScanDispatcherLogic();
	m_elevator_car_controllers = new std::vector<ElevatorCarController*>();
}

void ElevatorSystem::supportNewFloor(Floor* floor) {
	std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers = new std::vector<ElevatorCarControllerInterface*>();
	for (ElevatorCarController* elevator_car_controller : *m_elevator_car_controllers) {
		int elevator_id = elevator_car_controller->getElevatorId();
		ElevatorCarButtonDispatcher* button_dispatcher = new ElevatorCarNumberButtonDispatcher(m_dispatcher_logic, elevator_car_controller, elevator_id, floor->getFloorNumber());
		elevator_car_controller->addNumberButton(floor->getFloorNumber(), button_dispatcher);
		elevator_car_controllers->push_back(elevator_car_controller);
	}
	ButtonPanel* button_panel = new ButtonPanel();
	FloorButtonDispatcher* button_dispatcher_up = new FloorButtonUpDispatcher(m_dispatcher_logic, elevator_car_controllers, floor->getFloorNumber());
	Button* button_up = new ButtonUp(button_dispatcher_up);
	button_panel->addButton(button_up);
	FloorButtonDispatcher* button_dispatcher_down = new FloorButtonDownDispatcher(m_dispatcher_logic, elevator_car_controllers, floor->getFloorNumber());
	Button* button_down = new ButtonDown(button_dispatcher_down);
	button_panel->addButton(button_down);
	m_floor_numbers.push_back(floor->getFloorNumber());
	floor->attatchButtonPanel(button_panel);
}

void ElevatorSystem::supportNewElevatorCar() {
	// create a display for new elevator car
	Display* display = new Display();
	// create a new button panel for new elevator car
	ButtonPanel* button_panel = new ButtonPanel();
	// create a new elevator car sensor
	FloorSensor* sensor = new FloorSensor();
	// create a new elevator car
	ElevatorCar* elevator_car = new ElevatorCar(sensor, display, button_panel);
	// create a elevator controller
	ElevatorCarController* elevator_car_controller = new ElevatorCarController(m_dispatcher_logic, elevator_car);
	m_elevator_car_controllers->push_back(elevator_car_controller);
	sensor->addObserver(elevator_car_controller);
	// add buttons to this new button panel
	for (int floor_number : m_floor_numbers) {
		int elevator_id = elevator_car->getElevatorId();
		ElevatorCarButtonDispatcher* button_dispatcher = new ElevatorCarNumberButtonDispatcher(m_dispatcher_logic, elevator_car_controller, elevator_id, floor_number);
		NumberButton* number_button = new NumberButton(button_dispatcher, floor_number);
		button_panel->addButton(number_button);
	}
}