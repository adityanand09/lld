#ifndef __WITHDRAWL_PROCESSOR_H__
#define __WITHDRAWL_PROCESSOR_H__

#include "../atm.h"

class WithdrawlProcessor {
	protected:
		WithdrawlProcessor* m_next_withdrawl_processor;
	public:
		WithdrawlProcessor(WithdrawlProcessor* withdrawl_processor);
		virtual void withdrawCash(ATM* atm, int amount);
};

#endif