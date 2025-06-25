#include <iostream>
#include "user.h"
#include "atm.h"
#include "atm_state/atm_state.h"

int main() {
    User* user1 = new User("Alice");
    BankAccount* bank_account = new BankAccount(user1);
    Card* card = new Card(5790, bank_account);
    bank_account->dipositMoney(3000);

    ATM* atm = new ATM();
    atm->add100Notes(5);
    atm->add2000Notes(1);
    atm->add2000Notes(2);
    AtmState* state = atm->getAtmState();
    state->insertCard(atm, card);
    state = atm->getAtmState();
    state->authenticatePin(atm, 5790);
    state = atm->getAtmState();
    state->selectOperation(atm, TransactionType::CHECK_BALANCE);
    state = atm->getAtmState();
    state->checkBalance(atm);
    state = atm->getAtmState();
    state->selectOperation(atm, TransactionType::WITHDRAW_CASH);
    state = atm->getAtmState();
    state->withdrawCash(atm, 2700);
    state = atm->getAtmState();
    state->selectOperation(atm, TransactionType::CHECK_BALANCE);
    state = atm->getAtmState();
    state->checkBalance(atm);
    state = atm->getAtmState();
    state->selectOperation(atm, TransactionType::CHANGE_PIN);
    state = atm->getAtmState();
    state->changePin(atm, 2935);
    state->removeCard(atm);
}