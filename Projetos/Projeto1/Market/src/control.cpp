#include "control.h"
#include <iostream>
#include <sstream>
#include <iomanip> // Manipulação de entrada e saída
#include <string>
#include "user_interaction.h"

using namespace std;

namespace read {

    Control::Control()
    {
        type_of_entry();
    }

    void Control::open_file(std::ifstream &file)
    {
        file.open("input.dat");

    }

    void Control::read_file(std::ifstream &file)
    {
        auto count = 0u;
        string buffer[4];
        string name;
        unsigned performance;
        double salary;

        while (count < 4) {
            if (!read_comment(file)) {
                buffer[count] = line;
                count++;
            }
        }

        insert(buffer);

        market = new Market(get_market_name(), get_time_of_simulation_in_hours(), get_average_arrival_time_of_customers_in_seconds(), 10u);

        while (!file.eof()) {
            file >> name >> performance >> salary;
            if (!file.eof() && name != "") {
                cout << "Name: " << name << endl
                     << "Performance: " << performance << endl
                     << "Salary: " << salary << endl << endl;
            }
            market->add_box(name, performance, salary);
        }
    }

    void Control::close_file(std::ifstream &file)
    {
        file.close();
    }

    bool Control::read_comment(std::ifstream &file)
    {
        auto index = 0u;
        getline(file, line);

        if (line == "" || line == " ")
            return true;

        while (line[index] == ' ') {
            index++;
        }

        if (line[index] == '#') {
            line = "";
            return true;
        } else {
            return false;
        }
    }

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

  void Control::type_of_entry()
  {
    string market_name, identifier;
    unsigned int time_of_simulation, average_arrival_time_of_customers, number_of_box, performance;
    double salary;
    UserInteraction user;

    if (user.select_entry_with_file()) {
        open_file(file);
        read_file(file);
        close_file(file);

    } else {
        cout << "==============================================================\n";
        market_name = user.get_string("Informe o nome do Supermercado: ");
        time_of_simulation = user.get_unsigned_int("Insira o tempo de simulacao (em horas): ");
        average_arrival_time_of_customers = user.get_unsigned_int("Insira o tempo medio de chegada dos clientes (em segundos): ");
        number_of_box = user.get_unsigned_int("Insira o numero de caixas: ");
        cout << "==============================================================\n";

        market = new Market(market_name, time_of_simulation, average_arrival_time_of_customers, 10u);

        for (auto i = 0u; i < number_of_box; ++i) {
            identifier = user.get_string_with_index("Insira o identificador do caixa", i+1);
            performance = user.get_unsigned_int_with_index("Informe o desempenho do caixa", i+1);
            salary = user.get_double_with_index("Informe o salario do caixa", i+1);

            market->add_box(identifier, performance, salary);

            cout << "Caixa adicionado!\n"
                 << "===============================================================\n";
        }
    }
  }

}
