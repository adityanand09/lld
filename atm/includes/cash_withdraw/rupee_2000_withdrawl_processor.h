#ifndef __RUPEE_2000_WITHDRAWL_PROCESSOR_H__
#define __RUPEE_2000_WITHDRAWL_PROCESSOR_H__

#include "withdrawl_processor.h"

class Rupee2000WithdrawlProcessor : public WithdrawlProcessor {
	private:
	public:
		Rupee2000WithdrawlProcessor(WithdrawlProcessor* withdrawl_processor);
		void withdrawCash(ATM* atm, int amount);
};

#endif