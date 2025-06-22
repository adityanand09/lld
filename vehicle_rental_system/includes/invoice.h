#ifndef __INVOICE_H__
#define __INVOICE_H__

#include <string>
#include "reservation.h"

class Invoice {
    private:
        static int m_invoice_id_gen;
        int m_invoice_id;
        double m_amount;
        std::string m_date;
        Reservation* m_reservation;
    public:
        Invoice(std::string date, Reservation* reservation);
        int getInvoiceId();
        double getAmount();
        std::string getDate();
        Reservation* getReservation();
        double getTotalAmount();
};

#endif