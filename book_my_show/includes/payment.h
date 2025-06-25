#ifndef __PAYMENT_H__
#define __PAYMENT_H__

#include "payment_status.h"

class Payment {
    private:
        static int m_id_gen;
        int m_id;
        PaymentStatus m_payment_status;
    public:
        Payment();
        void makePayment(int amount);
        int getId();
};

#endif