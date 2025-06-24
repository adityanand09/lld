#ifndef __IDLE_STATE_H__
#define __IDLE_STATE_H__

#include "vending_machine_state.h"

class IdleState : public VendingMachineState {
    private:
    public:
        IdleState();
        void pressInsertCoinButton(VendingMachine* machine);
};

#endif