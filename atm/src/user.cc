#include "user.h"

User::User(std::string user_name) : m_user_name(user_name), m_bank_account(nullptr), m_card(nullptr) {}

void User::linkBankAccount(BankAccount* bank_account) {
	m_bank_account = bank_account;
}

void User::linkCard(Card* card) {
	m_card = card;
}