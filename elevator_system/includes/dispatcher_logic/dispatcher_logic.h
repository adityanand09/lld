#ifndef __DISPATCHER_LOGIC__
#define __DISPATCHER_LOGIC__

#include <vector>
#include "../enums.h"
#include "../elevator_car_controller.h"
#include "../button_event_handler/floor_button_up_handler.h"
#include "../button_event_handler/floor_button_down_handler.h"
#include "../button_event_handler/elevator_car_number_button_handler.h"
#include "../elevator_controller_request_handler/elevator_controller_request_processor.h"

class DispatcherLogic : public FloorButtonUpHandler, public FloorButtonDownHandler, public ElevatorCarNumberButtonHandler, public ElevatorControllerRequestProcessor {
private: 
public:
    DispatcherLogic();
    virtual void handleFloorButtonUpPress(int floor_number, std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers) override = 0;
    virtual void handleFloorButtonDownPress(int floor_number, std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers) override = 0;
    virtual void handleElevatorCarNumberButtonPress(int elevator_id, int floor_number, ElevatorCarControllerInterface* elevator_car_controller) override = 0;
    virtual void processElevatorControllerRequests(ElevatorCarControllerInterface* elevator_car_controller_interface) override = 0;
};

#endif