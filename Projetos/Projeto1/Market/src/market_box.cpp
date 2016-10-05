#include "market_box.h"


MarketBox::MarketBox()
{

}

MarketBox::MarketBox(std::string identifier, Performance* performance, double salary)
{
    client_queue = new LinkedQueue();
    identifier_ = identifier;
    performance_ = performance;
    salary_ = salary;
}

MarketBox::~MarketBox()
{
    delete performance_;
    delete average_service_time;
    delete client_queue;
}

unsigned int MarketBox::get_num_of_clients_in_queue()
{
    return client_queue->num_people();
}

unsigned int MarketBox::get_num_of_products_in_queue()
{
    return client_queue->num_products();
}

unsigned int MarketBox::get_num_of_clients_served()
{
    return clients_served;
}

Time* MarketBox::get_average_service_time()
{
    return average_service_time;
}

double MarketBox::get_total_billing()
{
    return total_billing;
}

double MarketBox::get_average_billing()
{
    return average_billing;
}

void MarketBox::add_client(Client* client)
{
    if (get_num_of_clients_in_queue() > 9 ) {
        throw std::out_of_range("Full_queue_Exception");
    } else {

        unsigned int exit_time = performance_->get_time_to_spend_item() * client->get_total_purchases();

        if (client->get_pay_type() == PayType::card) {
            exit_time += performance_->get_time_to_spend_card();
        }

        exit_time += client->get_arrival_time();

        // tipo quando não tiver ngm na fila tem q calcular
        //o tempo com arrival time, quando tiver alguém, tem q usar
        //o tempo do ultimo cara a ter entrado na fila

        Time* exit_time = new Time(exit_time);

        client->set_exit_time(pay_time);

        client_queue->enqueue(client);
    }
}

void MarketBox::remove_client()
{

}

Time* MarketBox::get_exit_time_of_first_client()
{

}
