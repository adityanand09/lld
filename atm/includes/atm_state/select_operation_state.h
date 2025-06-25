#ifndef __SELECT_OPERATION_STATE_H__
#define __SELECT_OPERATION_STATE_H__

#include "atm_state.h"

class SelectOperationState : public AtmState {
	private:
	public:
		SelectOperationState();
		void selectOperation(ATM* atm, TransactionType transaction_type);
		void removeCard(ATM* atm);
};

#endif