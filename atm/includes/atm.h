#ifndef __ATM_H__
#define __ATM_H__

#include "card.h"

class AtmState;

class ATM {
	private:
		AtmState* m_state;
		Card* m_card;
		int m_balance;
		int m_100_notes;
		int m_500_notes;
		int m_2000_notes;
	public:
		ATM();
		void addCard(Card* card);
		void removeCard();
		Card* getCard();
		void add100Notes(int count);
		void add500Notes(int count);
		void add2000Notes(int count);
		void deduct100Notes(int count);
		void deduct500Notes(int count);
		void deduct2000Notes(int count);
		int get100Notes();
		int get500Notes();
		int get2000Notes();
		int getBalance();
		void setAtmState(AtmState* state);
		AtmState* getAtmState();
};

#endif