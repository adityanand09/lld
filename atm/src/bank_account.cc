#include "bank_account.h"
#include <iostream>

int BankAccount::m_account_number_gen = 0;

BankAccount::BankAccount(User* user) : m_balance(0), m_user(user) {
	user->linkBankAccount(this);
	m_account_number = m_account_number_gen;
	m_account_number_gen++;
}

void BankAccount::dipositMoney(int amount) {
	m_balance += amount;
}

void BankAccount::withdrawMoney(int amount) {
	m_balance -= amount;
	std::cout << "INR " << amount << " withdrawn from your account" << std::endl;
}

int BankAccount::getBalance() {
	return m_balance;
}

User* BankAccount::getUser() {
	return m_user;
}