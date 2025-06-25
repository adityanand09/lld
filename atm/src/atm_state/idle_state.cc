#include "atm_state/idle_state.h"
#include "atm_state/pin_authentication_state.h"

IdleState::IdleState() {}

void IdleState::insertCard(ATM* atm, Card* card) {
	atm->addCard(card);
	atm->setAtmState(new PinAuthenticationState());
}