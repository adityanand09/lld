#ifndef __CASH_WITHDRAWL_STATE_H__
#define __CASH_WITHDRAWL_STATE_H__

#include "atm_state.h"

class CashWithdrawlState : public AtmState {
	private:
	public:
		CashWithdrawlState();
		void withdrawCash(ATM* atm, int amount);
		void removeCard(ATM* atm);
};

#endif