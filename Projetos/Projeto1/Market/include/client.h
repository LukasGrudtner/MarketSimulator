#ifndef CLIENT_H
#define CLIENT_H


class Client
{
    public:
        Client();
        virtual ~Client();

    protected:

    private:
        Queue client_queue;
        PayType client_pay_type;
        int total_purchases;
        double total_purchases_value;
        Time coming_time;
        Time time_to_leave;
};

#endif // CLIENT_H
