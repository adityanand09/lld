#include "atm_state/pin_authentication_state.h"
#include "atm_state/select_operation_state.h"
#include "atm_state/idle_state.h"

PinAuthenticationState::PinAuthenticationState() {}

void PinAuthenticationState::authenticatePin(ATM* atm, int pin) {
	if (atm->getCard()->validatePin(pin) == true) {
		atm->setAtmState(new SelectOperationState());
	} else {
		std::cout << "PIN validation failed : Re-enter PIN" << std::endl;
	}
}

void PinAuthenticationState::removeCard(ATM* atm) {
	atm->removeCard();
	atm->setAtmState(new IdleState());
}