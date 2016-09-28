#ifndef MARKETBOX_H
#define MARKETBOX_H

#include "linked_queue.h"
#include <string>

class MarketBox
{
    public:
        MarketBox();
        virtual ~MarketBox();

    protected:

    private:
        LinkedQueue client_queue;
        std::string identifier;
        Performance performance;
        unsigned int clients_in_queue;
        unsigned int clients_served;
        // Time average_service_time;
        double total_billing;
        double average_billing;
};

#endif // MARKETBOX_H
