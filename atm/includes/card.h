#ifndef __CARD_H__
#define __CARD_H__

#include "bank_account.h"

class Card {
	private:
		int m_pin;
		BankAccount* m_bank_account;
	public:
		Card(int pin, BankAccount* bank_account);
		bool validatePin(int pin);
		bool changePin(int pin);
		BankAccount* getBankAccount();
};

#endif