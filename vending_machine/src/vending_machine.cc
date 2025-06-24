#include "vending_machine.h"
#include "vending_machine_state/idle_state.h"

VendingMachine::VendingMachine() : m_inventory(nullptr), m_vending_machine_state(new IdleState()) {}

void VendingMachine::setInventory(Inventory* inventory) {
    m_inventory = inventory;
}

Inventory* VendingMachine::getInventory() {
    return m_inventory;
}

void VendingMachine::setVendingMachineState(VendingMachineState* vending_machine_state) {
    m_vending_machine_state = vending_machine_state;
}

VendingMachineState* VendingMachine::getvendingMachineState() {
    return m_vending_machine_state;
}

void VendingMachine::addCoin(Coin coin) {
    m_coins.push_back(coin);
}

std::vector<Coin> VendingMachine::getCoins() {
    return m_coins;
}