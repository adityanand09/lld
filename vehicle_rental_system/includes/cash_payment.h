#ifndef __CASH_PAYMENT_H__
#define __CASH_PAYMENT_H__

#include "payment.h"

class CashPayment : public Payment {
    private:
    public:
        CashPayment();
        bool processPayment(Invoice* invoice) override;
};

#endif