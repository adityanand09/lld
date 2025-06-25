#include "atm_state/check_balance_state.h"
#include "atm_state/select_operation_state.h"
#include "atm_state/idle_state.h"

CheckBalanceState::CheckBalanceState() {}

void CheckBalanceState::checkBalance(ATM* atm) {
	int balance = atm->getCard()->getBankAccount()->getBalance();
	std::cout << balance << " remaining in your account" << std::endl;
	atm->setAtmState(new SelectOperationState());
}

void CheckBalanceState::removeCard(ATM* atm) {
	atm->removeCard();
	atm->setAtmState(new IdleState());
}