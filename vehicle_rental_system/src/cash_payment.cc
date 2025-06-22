#include "cash_payment.h"

CashPayment::CashPayment() {
}

bool CashPayment::processPayment(Invoice* invoice) {
    // Process cash payment logic here
    // For simplicity, we assume the payment is always successful
    m_date = "today's date"; // Set the payment date
    return true;
}