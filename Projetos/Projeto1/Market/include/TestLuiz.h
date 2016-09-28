#ifndef TESTLUIZ_H
#define TESTLUIZ_H

#include <iostream>

#include "performance.h"
#include "clock.h"
#include "circular_list.h"
#include "market_box.h"

using namespace std;

class TestLuiz
{
    public:
        TestLuiz(){

            cout << "============Test1=============   Teste Performance" << endl;

            Performance* performance = new Performance(60u, 4);

            cout << "Tempo cartao: 60 = " << performance->get_time_to_spend_card() << endl;
            cout << "Tempo item: 4 = " << performance->get_time_to_spend_item() << endl;

            delete performance;

            cout << "============Test2=============   Teste Clock/Time" << endl;

            Clock* clock = new Clock();

            cout << "Tempo inicial: 0 = " << clock->get_time()->get_time_in_seconds() << endl;

            clock->set_one_more_second();

            cout << "Tempo dps de um segundo: 1 = " << clock->get_time()->get_time_in_seconds() << endl;

            clock->set_one_more_second();

            cout << "Tempo dps de dois segundos: 2 = " << clock->get_time()->get_time_in_seconds() << endl;

            clock->add_seconds(8u);

            cout << "Tempo dps de 10 segundos: 10 = " << clock->get_time()->get_time_in_seconds() << endl;

            clock->add_seconds(50u);

            cout << "Tempo dps de 1 minuto em minutos: 1 = " << clock->get_time()->get_time_in_minutes() << endl;

            clock->add_seconds(59u*60u);

            cout << "Tempo dps de 1 hora em horas: 1 = " << clock->get_time()->get_time_in_hours() << endl;
            cout << "Tempo dps de 1 hora em minutos: 60 = " << clock->get_time()->get_time_in_minutes() << endl;

            delete clock;

            cout << "============Test3=============   Teste Circular List" << endl;

            CircularList* circular = new CircularList();

            MarketBox* marketBox = new MarketBox();

            cout << "Tamanho com nenhum elemento: 0 = " << circular->size() << endl;
            cout << "Vazio: true = " << circular->empty() << endl;


            circular->push_front(*marketBox);

            cout << "Tamanho com um elemento: 1 = " << circular->size() << endl;
            cout << "Vazio: false = " << circular->empty() << endl;

            circular->pop_front();

            cout << "Tamanho com um elemento: 0 = " << circular->size() << endl;
            cout << "Vazio: true = " << circular->empty() << endl;

            delete circular;


        }
    private:
};

#endif // TESTLUIZ_H
