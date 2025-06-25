#include "atm_state/atm_state.h"

AtmState::AtmState() {}

void AtmState::insertCard(ATM* atm, Card* card) {
	std::cout << "OOPS wrong selection!" << std::endl;
}

void AtmState::authenticatePin(ATM* atm, int pin) {
	std::cout << "OOPS wrong selection!" << std::endl;
}

void AtmState::selectOperation(ATM* atm, TransactionType transaction_type) {
	std::cout << "OOPS wrong selection!" << std::endl;
}

void AtmState::withdrawCash(ATM* atm, int amount) {
	std::cout << "OOPS wrong selection!" << std::endl;
}

void AtmState::changePin(ATM* atm, int pin) {
	std::cout << "OOPS wrong selection!" << std::endl;
}

void AtmState::checkBalance(ATM* atm) {
	std::cout << "OOPS wrong selection!" << std::endl;
}

void AtmState::removeCard(ATM* atm) {
	std::cout << "OOPS wrong selection!" << std::endl;
}