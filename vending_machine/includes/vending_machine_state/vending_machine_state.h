#ifndef __VENDING_MACHINE_STATE_H__
#define __VENDING_MACHINE_STATE_H__

#include "coins.h"

class VendingMachine;

class VendingMachineState {
    private:
    public:
        VendingMachineState();
        virtual void pressInsertCoinButton(VendingMachine* machine);
        virtual void insertCoin(VendingMachine* machine, Coin coin);
        virtual void pressItemSelectionButton(VendingMachine* machine);
        virtual void chooseItem(VendingMachine* machine, int shelf_code);
        virtual void dispenseItem(VendingMachine* machine, int shelf_code);
        virtual void refundFullMoney(VendingMachine* machine);

};

#endif