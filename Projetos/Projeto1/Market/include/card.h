#ifndef CARD_H
#define CARD_H

#include "pay_type.h"

class Card : private PayType
{
    public:
        Card();
        virtual ~Card();

    protected:

    private:
};

#endif // CARD_H
