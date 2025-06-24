#include "vending_machine_state/vending_machine_state.h"
#include <iostream>

VendingMachineState::VendingMachineState() {}

void VendingMachineState::pressInsertCoinButton(VendingMachine* machine) {
    std::cout << "!OOPS wrong selection" << std::endl;
}

void VendingMachineState::insertCoin(VendingMachine* machine, Coin coin) {
    std::cout << "!OOPS wrong selection" << std::endl;
}

void VendingMachineState::pressItemSelectionButton(VendingMachine* machine) {
    std::cout << "!OOPS wrong selection" << std::endl;
}

void VendingMachineState::chooseItem(VendingMachine* machine, int shelf_code) {
    std::cout << "!OOPS wrong selection" << std::endl;
}

void VendingMachineState::dispenseItem(VendingMachine* machine, int shelf_code) {
    std::cout << "!OOPS wrong selection" << std::endl;
}

void VendingMachineState::refundFullMoney(VendingMachine* machine) {
    std::cout << "!OOPS wrong selection" << std::endl;
}