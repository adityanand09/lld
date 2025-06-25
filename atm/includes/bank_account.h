#ifndef __BANK_ACCOUNT_H__
#define __BANK_ACCOUNT_H__

#include "user.h"

class BankAccount {
	private:
		static int m_account_number_gen;
		int m_account_number;
		int m_balance;
		User* m_user;
	public:
		BankAccount(User* user);
		void dipositMoney(int amount);
		void withdrawMoney(int amount);
		int getBalance();
		User* getUser();
};

#endif