#ifndef __RUPEE_500_WITHDRAWL_PROCESSOR_H__
#define __RUPEE_500_WITHDRAWL_PROCESSOR_H__

#include "withdrawl_processor.h"

class Rupee500WithdrawlProcessor : public WithdrawlProcessor {
	private:
	public:
		Rupee500WithdrawlProcessor(WithdrawlProcessor* withdrawl_processor);
		void withdrawCash(ATM* atm, int amount);
};

#endif