#ifndef __ONLINE_PAYMENT_H__
#define __ONLINE_PAYMENT_H__

#include "payment.h"

class OnlinePayment : public Payment {
    private:
    public:
        OnlinePayment();
        bool processPayment(Invoice* invoice) override;
};

#endif