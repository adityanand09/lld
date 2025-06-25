#ifndef __CHANGE_PIN_STATE_H__
#define __CHANGE_PIN_STATE_H__

#include "atm_state.h"

class ChangePinState : public AtmState {
	private:
	public:
		ChangePinState();
		void changePin(ATM* atm, int pin);
		void removeCard(ATM* atm);
};

#endif