#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "client.h"

Client::Client()
{

}

Client::Client(Time& arrival_time)
{
    srand(time(0));
    total_purchases_= 2+ (rand() %98);
    set_total_purchases_value();
    set_pay_type();
    set_queue_type();
    arrival_time_ = arrival_time;
}

void Client::set_queue_type()
{
    int queue_type = rand() %2;

    if (queue_type == 1) {
        queue_type_ = QueueType::less_Products;
    } else {
        queue_type_ = QueueType::less_size;
    }
}

void Client::set_pay_type()
{
    int pay_type = 1 + (rand() %100);

    if (pay_type < 80) {
        pay_type_ = PayType::card;
    } else {
        pay_type_ = PayType::cash;
    }
}

void Client::set_total_purchases_value()
{
    for (auto i = 0; i < total_purchases_; i++) {
        total_purchases_value_ += (1 + (rand()%89));
    }
}

Client::~Client()
{

}

void Client::set_exit_time(Time& exit_time)
{
    exit_time_ = exit_time;
}

const Time Client::get_arrival_time()
{
    return arrival_time_;
}

const Time Client::get_exit_time()
{
    return exit_time_;
}

const Time Client::get_average_time()
{
    return *new Time(get_exit_time().get_time_in_seconds() - get_arrival_time().get_time_in_seconds());
}

PayType Client::get_pay_type()
{
    return pay_type_;
}

QueueType Client::get_queue_type()
{
    return queue_type_;
}

unsigned int Client::get_total_purchases()
{
    return total_purchases_;
}

long int Client::get_total_value()
{
    return total_purchases_value_;
}
