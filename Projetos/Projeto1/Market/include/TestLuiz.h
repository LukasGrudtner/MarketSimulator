#ifndef TESTLUIZ_H
#define TESTLUIZ_H

#include <iostream>
#include <string>

#include "performance.h"
#include "clock.h"
#include "circular_list.h"
#include "market_box.h"
#include "client.h"
#include "linked_queue.h"
#include "market.h"

using namespace std;

class TestLuiz
{
    public:
        TestLuiz(){



            cout << "\n============Test7=============   Teste Market" << endl;

            Market* market = new Market("Teste",1u, 30, 10);

            market->add_box("Joao", 1, 800);
            market->add_box("Maria", 2, 400);
            market->add_box("Maria", 3, 200);

            market->start_simulation();

            cout << "Faturamento total do supermercado: " << market->get_total_billing() << endl;
            cout << "Faturamento medio: " << market->get_average_billing() << endl;
            cout << "-------------\n";
            for (auto i = 0; i < market->get_num_of_boxes(); i++) {
                cout << "Caixa " << market->get_identifier(i) << " teve um faturamento medio de : ";
                cout << market->get_average_billing_box(i) << endl;
            }
            cout << "-------------\n";
            for (auto i = 0; i < market->get_num_of_boxes(); i++) {
                cout << "Caixa " << market->get_identifier(i) << " teve um faturamento total de : ";
                cout << market->get_billing(i) << endl;
            }
            cout << "-------------\n";
            for (auto i = 0; i < market->get_num_of_boxes(); i++) {
                cout << "Caixa " << market->get_identifier(i) << " teve um lucro de : ";
                cout << market->get_profit(i) << endl;
            }
            cout << "-------------\n";
            cout << "O tempo medio de permanencia de um cliente na fila eh de: " << market->get_average_queue_time_in_seconds() << endl;
            cout << "Numero de clientes que desistiram: " << market->get_dropped_out() << endl;
            cout << "Faturamento que deixou de ser realizado: " << market->get_billing_lost() << endl;
            cout << "Nome do Mercado: " << market->get_maket_name() << endl;






        }
    private:
};

#endif // TESTLUIZ_H
