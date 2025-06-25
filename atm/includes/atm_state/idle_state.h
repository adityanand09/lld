#ifndef __IDLE_STATE_H__
#define __IDLE_STATE_H__

#include "atm_state.h"

class IdleState : public AtmState {
	private:
	public:
		IdleState();
		void insertCard(ATM* atm, Card* card);
};

#endif