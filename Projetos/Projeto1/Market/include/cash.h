#ifndef CASH_H
#define CASH_H

#include "pay_type.h"

class Cash : private PayType
{
    public:
        Cash();
        virtual ~Cash();

    protected:

    private:
};

#endif // CASH_H
