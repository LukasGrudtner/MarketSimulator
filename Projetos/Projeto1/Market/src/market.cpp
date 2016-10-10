#include "market.h"

Market::Market(std::string market_name,unsigned int time_of_simulation, unsigned int average_time_of_arrival_of_clients, unsigned int max_clients_in_queue)
{
    box_list = new CircularList();
    clock = new Clock();
    clients_dropped_out = 0;
    market_name_ = market_name;
    time_of_simulation_ = new Time(time_of_simulation*3600);
    average_time_of_arrival_of_clients_ = new Time(average_time_of_arrival_of_clients);
    time_of_next_client = new Time(0u);
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
    delete time_of_next_client;
}

void Market::add_box(std::string nome, unsigned int performance, double salary)
{
    switch (performance){
        case 1:
               box_list->push_front(new MarketBox(nome, good_box_perform, salary));
            break;
        case 2:
               box_list->push_front(new MarketBox(nome, medium_box_perform, salary));
            break;
        case 3:
               box_list->push_front(new MarketBox(nome, bad_box_perform, salary));
            break;
        default:
            break;
    }
}

void Market::start_simulation()
{
    while(time_of_simulation_->get_time_in_hours() > clock->get_time()->get_time_in_hours()) {
        box_list->passes_forward();
        while (box_list->get_data_pointer_element() != nullptr) {
            if (box_list->get_data_pointer_element()->get_exit_time_of_first_client()->get_time_in_seconds() == clock->get_time()->get_time_in_seconds()) {
                box_list->get_data_pointer_element()->remove_client();
            }


            box_list->passes_forward();
        }

        if (clock->get_time()->get_time_in_seconds() == time_of_next_client->get_time_in_seconds()) {
               time_of_next_client->add_seconds(average_time_of_arrival_of_clients_->get_time_in_seconds());
        }



      //  if (clock->get_time()->get_time_in_seconds() == box_list->

        clock->add_seconds(1u);
    }
}
