#include <iostream>
#include "vending_machine.h"
#include "inventory.h"
#include "item.h"
#include "item_type.h"
#include "vending_machine_state/idle_state.h"
#include "coins.h"

int main() {
    VendingMachine* vending_machine = new VendingMachine();
    Inventory* inventory = new Inventory(10);
    int start_code = 101;
    for (int i=0; i<10; i++) {
        Item* item = new Item(ItemType::COKE, 1.0);
        inventory->addItem(item, start_code);
        inventory->addItem(item, start_code);
        start_code++;
    }
    vending_machine->setInventory(inventory);
    vending_machine->setVendingMachineState(new IdleState());
    
    VendingMachineState* state = vending_machine->getvendingMachineState();
    state->pressInsertCoinButton(vending_machine);
    state = vending_machine->getvendingMachineState();
    state->insertCoin(vending_machine, Coin::PENNY);
    state->insertCoin(vending_machine, Coin::NICKEL);
    state->insertCoin(vending_machine, Coin::NICKEL);
    state->pressItemSelectionButton(vending_machine);
    state = vending_machine->getvendingMachineState();
    state->chooseItem(vending_machine, 102);
}