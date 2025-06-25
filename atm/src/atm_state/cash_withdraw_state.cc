#include "atm_state/cash_withdrawl_state.h"
#include "atm_state/idle_state.h"
#include "atm_state/select_operation_state.h"
#include "cash_withdraw/withdrawl_processor.h"
#include "cash_withdraw/rupee_100_withdrawl_processor.h"
#include "cash_withdraw/rupee_500_withdrawl_processor.h"
#include "cash_withdraw/rupee_2000_withdrawl_processor.h"

CashWithdrawlState::CashWithdrawlState() {}

void CashWithdrawlState::withdrawCash(ATM* atm, int amount) {
	// if atm has enough balance;
	if (atm->getBalance() < amount) {
		std::cout << "Not enough cash to dispense " << std::endl;
		atm->setAtmState(new SelectOperationState());
		return;
	}
	// check if user has enough account balance
	if (atm->getCard()->getBankAccount()->getBalance() < amount) {
		std::cout << "You don't have enough balance in your account" << std::endl;
		atm->setAtmState(new SelectOperationState());
	}
	// dispense cash
	atm->getCard()->getBankAccount()->withdrawMoney(amount);
	WithdrawlProcessor* withdrawl_processor = new Rupee2000WithdrawlProcessor(new Rupee500WithdrawlProcessor(new Rupee100WithdrawlProcessor(nullptr)));
	withdrawl_processor->withdrawCash(atm, amount);
	atm->setAtmState(new SelectOperationState());
}

void CashWithdrawlState::removeCard(ATM* atm) {
	atm->removeCard();
	atm->setAtmState(new IdleState());
}