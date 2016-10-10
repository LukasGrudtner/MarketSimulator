#include "control.h"
#include <iostream>
#include <sstream>
#include <iomanip> // Manipulação de entrada e saída

#include <string>

using namespace std;

namespace read {

    auto count = 0u;
    string buffer[4];

    void Control::read_market(std::istream &in)
    {

        string name;
        unsigned int performance;
        double salary;



        // Lê linha por linha até o final do arquivo.
        // Enquanto não encontrar a marca de fim de arquivo:

        for (auto i = 0u; count < 4; ++i) {
            if (!read_comment(in)) {
                buffer[count] = linha;
                count++;
            }
        }

        insert(buffer);
        market = new Market(get_market_name(), get_time_of_simulation_in_hours(), get_average_arrival_time_of_customers_in_seconds(), 10u);


        while (!in.eof()) {
            in >> name >> performance >> salary;
            if (name[0] != '#' && name[0] != '\n' && !in.eof()) {
                market->add_box(name, performance, salary);
            }
        }


      std::cout << "Nome Mercado eoq : " << market->get_maket_name() << endl;
      cout << "Nome caixa 4 : " << market->get_identifier(0) << endl;
      cout << "Nome caixa 3 : " << market->get_identifier(1) << endl;
      cout << "Nome caixa 2 : " << market->get_identifier(2) << endl;
      cout << "Nome caixa 1 : " << market->get_identifier(3) << endl;

     }

    bool Control::read_comment(std::istream &in)
    {
        string test;

        auto counter = 0u;
        getline(in, test);

        if (test[0] == '\n')
            return true;

        while (test[counter] == ' ') {
            counter++;
        }

        if (test[counter] == '#') {
            linha = "";
            return true;
        } else {
            linha = test;
            return false;
        }
    }

    // std::stoi -> converte string para inteiro

    void Control::insert(string buffer[])
    {
        market_name = buffer[0];


        istringstream convert(buffer[1]);
        convert >> time_of_simulation_in_hours;

        istringstream convert2(buffer[2]);
        convert2 >> average_arrival_time_of_customers_in_seconds;

        istringstream convert3(buffer[3]);
        convert3 >> number_of_market_box;

    }

  std::string Control::get_market_name()
  {
      return market_name;
  }

  unsigned int Control::get_time_of_simulation_in_hours()
  {
      return time_of_simulation_in_hours;
  }

  unsigned int Control::get_average_arrival_time_of_customers_in_seconds()
  {
      return average_arrival_time_of_customers_in_seconds;
  }

  unsigned int Control::get_number_of_market_box()
  {
      return number_of_market_box;
  }

}
