#ifndef __ITEM_SELECTION_STATE_H__
#define __ITEM_SELECTION_STATE_H__

#include "vending_machine_state.h"

class ItemSelectionState : public VendingMachineState{
    private:
    public:
        ItemSelectionState();
        void chooseItem(VendingMachine* machine, int shelf_code);
        int getChange(int amount);
        void refundFullMoney(VendingMachine* machine);
};

#endif