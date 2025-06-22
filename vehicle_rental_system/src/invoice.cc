#include "invoice.h"

int Invoice::m_invoice_id_gen = 0;

Invoice::Invoice(std::string date, Reservation* reservation) {
    m_invoice_id = m_invoice_id_gen;
    m_date = date;
    m_reservation = reservation;
    m_invoice_id_gen++;
}

int Invoice::getInvoiceId() {
    return m_invoice_id;
}

double Invoice::getAmount() {
    return m_amount;
}

std::string Invoice::getDate() {
    return m_date;
}

Reservation* Invoice::getReservation() {
    return m_reservation;
}

double Invoice::getTotalAmount() {
    // Assuming the total amount is calculated based on the reservation details
    return m_amount;
}