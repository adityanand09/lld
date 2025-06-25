#include "cash_withdraw/rupee_100_withdrawl_processor.h"

Rupee100WithdrawlProcessor::Rupee100WithdrawlProcessor(WithdrawlProcessor* withdrawl_processor) : WithdrawlProcessor(withdrawl_processor) {}

void Rupee100WithdrawlProcessor::withdrawCash(ATM* atm, int amount) {
	int count = std::min(atm->get100Notes(),  amount / 100);
    int remaining = amount - count * 100;
    atm->deduct100Notes(count);
    if (remaining) {
        m_next_withdrawl_processor->withdrawCash(atm, remaining);
    }
}