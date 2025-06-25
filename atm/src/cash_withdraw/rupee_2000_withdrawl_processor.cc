#include "cash_withdraw/rupee_2000_withdrawl_processor.h"
#include <algorithm>

Rupee2000WithdrawlProcessor::Rupee2000WithdrawlProcessor(WithdrawlProcessor* withdrawl_processor) : WithdrawlProcessor(withdrawl_processor) {}

void Rupee2000WithdrawlProcessor::withdrawCash(ATM* atm, int amount) {
	int count = std::min(atm->get2000Notes(),  amount / 2000);
    int remaining = amount - count * 2000;
    atm->deduct2000Notes(count);
    if (remaining) {
        m_next_withdrawl_processor->withdrawCash(atm, remaining);
    }
}