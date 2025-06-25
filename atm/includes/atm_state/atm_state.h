#ifndef __ATM_STATE_H__
#define __ATM_STATE_H__

#include "../atm.h"
#include "../card.h"
#include "../transaction_type.h"
#include <iostream>

class AtmState {
	private:
	public:
		AtmState();
		virtual void insertCard(ATM* atm, Card* card);
		virtual void authenticatePin(ATM* atm, int pin);
		virtual void selectOperation(ATM* atm, TransactionType transaction_type);
		virtual void withdrawCash(ATM* atm, int amount);
		virtual void changePin(ATM* atm, int pin);
		virtual void checkBalance(ATM* atm);
		virtual void removeCard(ATM* atm);
};
#endif