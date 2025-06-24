#ifndef __DISPENSE_ITEM_STATE_H__
#define __DISPENSE_ITEM_STATE_H__

#include "vending_machine_state.h"

class DispenseItemState : public VendingMachineState{
    private:
    public:
        DispenseItemState(VendingMachine* machine, int shelf_code);
        void dispenseItem(VendingMachine* machine, int shelf_code);
};

#endif