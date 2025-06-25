#include "cash_withdraw/withdrawl_processor.h"

WithdrawlProcessor::WithdrawlProcessor(WithdrawlProcessor* withdrawl_processor) : m_next_withdrawl_processor(withdrawl_processor) {}

void WithdrawlProcessor::withdrawCash(ATM* atm, int amount) {
	if (m_next_withdrawl_processor != nullptr) {
		m_next_withdrawl_processor->withdrawCash(atm, amount);
	}
}