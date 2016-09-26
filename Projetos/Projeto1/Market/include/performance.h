#ifndef PERFORMANCE_H
#define PERFORMANCE_H


class Performance
{
    public:
        unsigned int time_to_spend_item();
        unsigned int time_to_spend_card();

    protected:

    private:
        unsigned int time_to_spend_item_;
        unsigned int time_to_spend_card_;
};

#endif // PERFORMANCE_H
