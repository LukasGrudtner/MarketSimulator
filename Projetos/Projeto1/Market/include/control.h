#ifndef CONTROL_H
#define CONTROL_H


#include <string>
#include <fstream>
#include <sstream>
#include "market.h"

using namespace std;

namespace read {

class Control
{
    public:
        Control();
        void open_file(std::ifstream &);
        void read_file(std::ifstream &);
        void close_file(std::ifstream &);
        bool read_comment(std::ifstream &);
        void insert(std::string buffer[]);
        std::string get_market_name();
        unsigned int get_time_of_simulation_in_hours();
        unsigned int get_average_arrival_time_of_customers_in_seconds();
        unsigned int get_number_of_market_box();

    private:
        ifstream file;
        std::string line;
        std::string market_name;
        unsigned int time_of_simulation_in_hours;
        unsigned int average_arrival_time_of_customers_in_seconds;
        unsigned int number_of_market_box;
        // Criação do mercado com os atributos de simulação recolhidos do input.dat
        Market* market;
};

}

#endif
