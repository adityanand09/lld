#ifndef __VENDING_MACHINE_H__
#define __VENDING_MACHINE_H__

#include "inventory.h"
#include "vending_machine_state/vending_machine_state.h"

class VendingMachine {
    private:
        VendingMachineState* m_vending_machine_state;
        Inventory* m_inventory;
        std::vector<Coin> m_coins;
    public:
        VendingMachine();
        void setInventory(Inventory* inventory);
        Inventory* getInventory();
        void setVendingMachineState(VendingMachineState* vending_machine_state);
        VendingMachineState* getvendingMachineState();
        void addCoin(Coin coin);
        std::vector<Coin> getCoins();

};

#endif