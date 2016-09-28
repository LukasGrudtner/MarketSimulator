#ifndef MARKETBOX_H
#define MARKETBOX_H


class MarketBox
{
    public:
        MarketBox();
        virtual ~MarketBox();

    protected:

    private:
        // Queue client_queue;
        // string identifier;
        // Performance performance;
        unsigned int clients_in_queue;
        unsigned int clients_served;
        // Time average_service_time;
        double total_billing;
        double average_billing;
};

#endif // MARKETBOX_H
