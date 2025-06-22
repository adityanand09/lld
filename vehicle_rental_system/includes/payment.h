#ifndef __PAYMENT_H__
#define __PAYMENT_H__

#include <string>
#include "invoice.h"

class Payment {
    protected:
        std::string m_date;
    public:
        Payment();
        virtual bool processPayment(Invoice* invoice) = 0;
};

#endif