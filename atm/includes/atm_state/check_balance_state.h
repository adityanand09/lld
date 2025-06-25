#ifndef __CHECK_BALANCE_STATE_H__
#define __CHECK_BALANCE_STATE_H__

#include "atm_state.h"

class CheckBalanceState : public AtmState {
	private:
	public:
		CheckBalanceState();
		void checkBalance(ATM* atm);
		void removeCard(ATM* atm);
};

#endif