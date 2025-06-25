#include "card.h"

Card::Card(int pin, BankAccount* bank_account) : m_pin(pin), m_bank_account(bank_account) {
	User* user = bank_account->getUser();
	user->linkCard(this);
}

bool Card::validatePin(int pin) {
	return m_pin == pin;
}

bool Card::changePin(int pin) {
	m_pin = pin;
	// pin changed succesfully
	return true;
}

BankAccount* Card::getBankAccount() {
	return m_bank_account;
}