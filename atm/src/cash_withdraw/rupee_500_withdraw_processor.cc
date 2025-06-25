#include "cash_withdraw/rupee_500_withdrawl_processor.h"

Rupee500WithdrawlProcessor::Rupee500WithdrawlProcessor(WithdrawlProcessor* withdrawl_processor) : WithdrawlProcessor(withdrawl_processor) {}

void Rupee500WithdrawlProcessor::withdrawCash(ATM* atm, int amount) {
	int count = std::min(atm->get500Notes(),  amount / 500);
    int remaining = amount - count * 500;
    atm->deduct500Notes(count);
    if (remaining) {
        m_next_withdrawl_processor->withdrawCash(atm, remaining);
    }
}