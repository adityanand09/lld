#ifndef __USER_H__
#define __USER_H__

#include <string>

class BankAccount;
class Card;

class User {
	private:
		std::string m_user_name;
		Card* m_card;
		BankAccount* m_bank_account;
	public:
		User(std::string user_name);
		void linkBankAccount(BankAccount* bank_account);
		void linkCard(Card* card);
};

#endif