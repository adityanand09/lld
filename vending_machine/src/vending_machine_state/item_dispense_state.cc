#include "vending_machine_state/item_dispense_state.h"
#include "vending_machine_state/idle_state.h"
#include "vending_machine.h"
#include <iostream>

DispenseItemState::DispenseItemState(VendingMachine* machine, int shelf_code) {
    dispenseItem(machine, shelf_code);
}

void DispenseItemState::dispenseItem(VendingMachine* machine, int shelf_code) {
    std::cout << "Item dispensed" << std::endl;
    machine->setVendingMachineState(new IdleState());
}
