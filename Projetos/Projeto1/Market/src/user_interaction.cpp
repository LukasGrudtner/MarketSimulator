#include "user_interaction.h"
#include <iostream>
#include <string>

using namespace std;

UserInteraction::UserInteraction()
{
    //ctor
}

UserInteraction::~UserInteraction()
{
    //dtor
}

bool UserInteraction::select_entry_with_file()
{
    unsigned int entry;

    cout << "Como deseja iniciar os parâmetros do programa?" << "\n\n"
         << "1. Os parâmetros serão pegos pelo arquivo input.dat." << "\n"
         << "2. Os parâmetros serão escolhidos manualmente." << "\n\n";

    cin >> entry;

    if (entry < 1 || entry > 2) {
        do {
            cout << "/nPor favor, selecione ou o número 1 ou o número 2." << "\n\n";

            cout << "Como deseja iniciar os parâmetros do programa?" << "\n\n"
                 << "1. Os parâmetros serão pegos pelo arquivo input.dat." << "\n"
                 << "2. Os parâmetros serão escolhidos manualmente.";

            cin >> entry;
        } while (entry < 1 || entry > 2);
    }

    if (entry == 1)
        return true;
    else
        return false;
}

string UserInteraction::get_market_name()
{
    char market_name[256];

    cout << "\nInsira o nome do Supermercado: ";
    //cin.getline(market_name, 255);
    cin >> market_name;

    return market_name;
}

unsigned int UserInteraction::get_unsigned_int(string msg)
{
    unsigned int input;

    cout << "\n" << msg;
    cin >> input;
    return input;
}

unsigned int UserInteraction::get_average_arrival_time_of_customers()
{
    unsigned int average_arrival_time_of_curstomers;

    cout << "\nInsira o tempo médio de chegada dos clientes (em segundos): ";
    cin >> average_arrival_time_of_curstomers;
    return average_arrival_time_of_curstomers;
}

unsigned int UserInteraction::get_number_of_box()
{
    unsigned int number_of_box;

    cout << "\nInsira o numero de caixas: ";
    cin >> number_of_box;
    return number_of_box;
}

string UserInteraction::get_identifier_box(int index)
{
    string identifier;

    cout << "\nInsira o identificador do caixa " << index << ": ";
    cin >> identifier;
    return identifier;
}

unsigned int UserInteraction::get_performance_box(int index)
{
    unsigned int performance;

    cout << "\nInsira o desempenho do caixa " << index << ": ";
    cin >> performance;
    return performance;
}

unsigned int UserInteraction::get_salary_box(int index)
{
    unsigned int salary;

    cout << "\nInsira o salário do caixa " << index << ": ";
    cin >> salary;
    return salary;
}

