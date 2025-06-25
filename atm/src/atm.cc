#include "atm.h"
#include "atm_state/idle_state.h"
#include <iostream>

ATM::ATM() : m_card(nullptr), m_state(new IdleState()), m_balance(0) {}

void ATM::addCard(Card* card) {
	m_card = card;
}

void ATM::removeCard() {
	m_card = nullptr;
	m_state = new IdleState();
}

Card* ATM::getCard() {
	return m_card;
}

void ATM::add100Notes(int count) {
	m_100_notes += count;
	m_balance += count * 100;
}

void ATM::add500Notes(int count) {
	m_500_notes += count;
	m_balance += count * 500;
}

void ATM::add2000Notes(int count) {
	m_2000_notes += count;
	m_balance += count * 2000;
}

void ATM::deduct100Notes(int count) {
	m_100_notes -= count;
	m_balance -= 100 * count;
	std::cout << count << " 100 rupee note(s) dispensed" << std::endl;
}

void ATM::deduct500Notes(int count) {
	m_500_notes -= count;
	m_balance -= 500 * count;
	std::cout << count << " 500 rupee note(s) dispensed" << std::endl;
}

void ATM::deduct2000Notes(int count) {
	m_2000_notes -= count;
	m_balance -= 2000 * count;
	std::cout << count << " 2000 rupee note(s) dispensed" << std::endl;
}

int ATM::get100Notes() {
	return m_100_notes;
}

int ATM::get500Notes() {
	return m_500_notes;
}

int ATM::get2000Notes() {
	return m_2000_notes;
}

int ATM::getBalance() {
	return m_balance;
}

void ATM::setAtmState(AtmState* state) {
	m_state = state;
}

AtmState* ATM::getAtmState() {
	return m_state;
}