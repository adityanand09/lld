#include "atm_state/change_pin_state.h"
#include "atm_state/select_operation_state.h"
#include "atm_state/idle_state.h"

ChangePinState::ChangePinState() {}

void ChangePinState::changePin(ATM* atm, int pin) {
	bool status = atm->getCard()->changePin(pin);
	if (status == true) {
		std::cout << "Pin changed succesfully" << std::endl;
		atm->setAtmState(new SelectOperationState());
	} else {
		std::cout << "Pin change failed" << std::endl;
	}
}

void ChangePinState::removeCard(ATM* atm) {
	atm->removeCard();
	atm->setAtmState(new IdleState());
}