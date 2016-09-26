#ifndef PERFORMANCE_H
#define PERFORMANCE_H


class Performance
{
    public:
        virtual Performance() = 0;
        virtual ~Performance() = 0;
        virtual unsigned int time_to_spend_item() = 0;
        virtual unsigned int time_to_spend_card() = 0;

    protected:

    private:
        unsigned int time_to_spend_item_;
        unsigned int time_to_spend_card_;
};

#endif // PERFORMANCE_H
