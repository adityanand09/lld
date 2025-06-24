#include "vending_machine_state/idle_state.h"
#include "vending_machine_state/insert_coin_state.h"
#include "vending_machine.h"

IdleState::IdleState() {}

void IdleState::pressInsertCoinButton(VendingMachine* machine) {
    machine->setVendingMachineState(new InsertCoinState());
}