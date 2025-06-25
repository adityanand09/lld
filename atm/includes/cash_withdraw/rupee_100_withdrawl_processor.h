#ifndef __RUPEE_100_WITHDRAWL_PROCESSOR_H__
#define __RUPEE_100_WITHDRAWL_PROCESSOR_H__

#include "withdrawl_processor.h"

class Rupee100WithdrawlProcessor : public WithdrawlProcessor {
	private:
	public:
		Rupee100WithdrawlProcessor(WithdrawlProcessor* withdrawl_processor);
		void withdrawCash(ATM* atm, int amount);
};

#endif