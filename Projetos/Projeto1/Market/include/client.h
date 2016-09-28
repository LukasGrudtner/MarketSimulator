#ifndef CLIENT_H
#define CLIENT_H


class Client
{
    public:

        Client();
        virtual ~Client();

        enum PayType { cash, card };

    private:
        PayType pay_type_;
        unsigned int total_purchases_;
    //    unsigned double total_purchases_value_;



};

#endif // CLIENT_H
