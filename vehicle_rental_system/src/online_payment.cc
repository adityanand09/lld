#include "online_payment.h"

OnlinePayment::OnlinePayment() {
}

bool OnlinePayment::processPayment(Invoice* invoice) {
    // Process online payment logic here
    // For simplicity, we assume the payment is always successful
    m_date = "today's date"; // Set the payment date
    return true;
}