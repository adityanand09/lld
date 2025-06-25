#ifndef __PIN_AUTHENTICATION_STATE_H__
#define __PIN_AUTHENTICATION_STATE_H__

#include "atm_state.h"

class PinAuthenticationState : public AtmState {
	private:
	public:
		PinAuthenticationState();
		void authenticatePin(ATM* atm, int pin);
		void removeCard(ATM* atm);
};

#endif