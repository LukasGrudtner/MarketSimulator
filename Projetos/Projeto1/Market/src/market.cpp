#include "market.h"

Market::Market(std::string market_name,unsigned int time_of_simulation, unsigned int average_time_of_arrival_of_clients)
{
    box_list = new CircularList();
    clock = new Clock();
    clients_dropped_out = 0;
    market_name_ = market_name;
    time_of_simulation_ = new Time(time_of_simulation*120);
    average_time_of_arrival_of_clients_ = new Time(average_time_of_arrival_of_clients);
}

Market::~Market()
{
    delete box_list;
    delete clock;
    delete time_of_simulation_;
    delete average_time_of_arrival_of_clients_;
    delete bad_box_perform;
    delete medium_box_perform;
    delete good_box_perform;
}

void Market::add_box(std::string nome, unsigned int performance, double salary)
{
    switch (performance){
        case 1:
               box_list.push_front(new MarketBox(nome, good_box_perform, salary));
            break;
        case 2:
               box_list.push_front(new MarketBox(nome, medium_box_perform, salary));
            break;
        case 3:
               box_list.push_front(new MarketBox(nome, bad_box_perform, salary));
            break;
        default:
            break;
    }
}

