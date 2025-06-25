#include "atm_state/select_operation_state.h"
#include "atm_state/cash_withdrawl_state.h"
#include "atm_state/check_balance_state.h"
#include "atm_state/change_pin_state.h"
#include "atm_state/idle_state.h"

SelectOperationState::SelectOperationState() {}

void SelectOperationState::selectOperation(ATM* atm,  TransactionType transaction_type) {
	switch (transaction_type) {
		case TransactionType::WITHDRAW_CASH :
			atm->setAtmState(new CashWithdrawlState());
			break;
		case TransactionType::CHECK_BALANCE :
			atm->setAtmState(new CheckBalanceState());
			break;
		case TransactionType::CHANGE_PIN :
			atm->setAtmState(new ChangePinState());
			break;
		default :
			std::cout << "Please choose a valid option." << std::endl;
	}
}

void SelectOperationState::removeCard(ATM* atm) {
	atm->removeCard();
	atm->setAtmState(new IdleState());
}