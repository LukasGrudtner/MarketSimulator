#ifndef BADPERFORMANCE_H
#define BADPERFORMANCE_H

#include "performance.h"

class BadPerformance : public Performance
{
    public:
        BadPerformance() : Performance()
        {}
        virtual ~BadPerformance();
        int time_to_spend_item();
        int time_to_spend_card();

    protected:

    private:


};

#endif // BADPERFORMANCE_H
