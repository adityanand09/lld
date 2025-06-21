#ifndef __SCAN_DISPATCHER_LOGIC__
#define __SCAN_DISPATCHER_LOGIC__

#include "dispatcher_logic.h"

class ScanDispatcherLogic : public DispatcherLogic {
public:
    ScanDispatcherLogic();
    void handleFloorButtonUpPress(int floor_number, std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers) override;
    void handleFloorButtonDownPress(int floor_number, std::vector<ElevatorCarControllerInterface*> *elevator_car_controllers) override;
    void handleElevatorCarNumberButtonPress(int elevator_id, int floor_number, ElevatorCarControllerInterface* elevator_car_controller) override;
    virtual void processElevatorControllerRequests(ElevatorCarControllerInterface* elevator_car_controller_interface) override;
};

#endif
