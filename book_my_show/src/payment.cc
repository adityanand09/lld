#include "payment.h"

int Payment::m_id_gen = 0;

Payment::Payment() {
    m_id = m_id_gen;
    m_id_gen++;
    m_payment_status = PaymentStatus::PENDING;
}

int Payment::getId() {
    return m_id;
}

void Payment::makePayment(int amount) {
    // make payment;
    // m_payment_status = PaymentStatus::COMPLETED;
}