#include "control.h"
#include <iostream>
#include <sstream>
#include <iomanip> // Manipulação de entrada e saída
#include <string>

using namespace std;

namespace read {

    Control::Control()
    {
        open_file(file);
        read_file(file);
        close_file(file);

        cout << "Market Name: " << get_market_name() << endl
             << "Time of Simulation (in hours): " << get_time_of_simulation_in_hours() << endl
             << "Average Arrival Time of Customers (in seconds): " << get_average_arrival_time_of_customers_in_seconds() << endl
             << "Number of Market Box: " << get_number_of_market_box() << endl;
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

}
