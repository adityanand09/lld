#include "vending_machine_state/item_selection_state.h"
#include "vending_machine_state/item_dispense_state.h"
#include "vending_machine_state/idle_state.h"
#include "vending_machine.h"
#include <iostream>

ItemSelectionState::ItemSelectionState() {}

void ItemSelectionState::chooseItem(VendingMachine* machine, int shelf_code) {
    int collected_amount = 0;
    for (Coin coin : machine->getCoins()) {
        collected_amount += coin;
    }
    int item_price = machine->getInventory()->getItemPrice(shelf_code);
    if (collected_amount < item_price) {
        refundFullMoney(machine);
        return;
    }
    if (collected_amount > item_price) {
        getChange(collected_amount - item_price);
    }
    machine->setVendingMachineState(new DispenseItemState(machine, shelf_code));
}

int ItemSelectionState::getChange(int amount){
    std::cout << "Amount " << amount << " returned" << std::endl;
    return amount;
}

void ItemSelectionState::refundFullMoney(VendingMachine* machine) {
    machine->setVendingMachineState(new IdleState());
}