#ifndef __ELEVATOR_CAR_CONTROLLER__
#define __ELEVATOR_CAR_CONTROLLER__

#include "elevator_car.h"
#include "button_panel.h"
#include "sensor/sensor_observer.h"
#include "elevator_controller_request.h"
#include "elevator_controller_request_handler/elevator_controller_request_processor.h"
#include "elevator_car_controller_interface.h"

class ElevatorCarController : public SensorObserver, public ElevatorCarControllerInterface {
	private:
		ElevatorControllerRequestProcessor* m_elevator_controller_request_processor;
		ElevatorCar* m_elevator_car;
		ElevatorControllerRequest* m_requests;
		int m_top_floor;
		int m_bottom_floor;
	public:
		ElevatorCarController(ElevatorControllerRequestProcessor* m_elevator_controller_request_processor, ElevatorCar* elevator_car);
		int getElevatorId();
		void addNumberButton(int floor_number, ButtonDispatcher* button_dispatcher);
		void acceptRequest(int floor_number, DIRECTION direction);
		void notify();
		int getCurrentFloor() override;
		DIRECTION getDirection() override;
		ELEVATOR_CAR_STATUS getElevatorCarStatus() override;
		ElevatorControllerRequest* getElevatorControllerRequest() override;
		void move(DIRECTION direction) override;
		void stop() override;
		void updateTopFloor(int top_floor);
		void updateBottomFloor(int bottom_floor);
		bool isAtTopFloor();
		bool isAtBottomFloor();
};

#endif