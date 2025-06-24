#include "vending_machine_state/insert_coin_state.h"
#include "vending_machine_state/item_selection_state.h"
#include "vending_machine.h"
#include <iostream>

InsertCoinState::InsertCoinState() {}

void InsertCoinState::insertCoin(VendingMachine* machine, Coin coin) {
    machine->addCoin(coin);
}

void InsertCoinState::pressItemSelectionButton(VendingMachine* machine) {
    machine->setVendingMachineState(new ItemSelectionState());
}

void InsertCoinState::refundFullMoney(VendingMachine* machine) {
    std::cout << "Money refunded" << std::endl;
}