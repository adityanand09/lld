#ifndef __INSERT_COIN_STATE_H__
#define __INSERT_COIN_STATE_H__

#include "vending_machine_state.h"

class InsertCoinState : public VendingMachineState{
    private:
    public:
        InsertCoinState();
        void insertCoin(VendingMachine* machine, Coin coin);
        void pressItemSelectionButton(VendingMachine* machine);
        void refundFullMoney(VendingMachine* machine);
};

#endif