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

            cout << "instanciou circular" << endl;

            MarketBox* marketBox = new MarketBox();

            cout << "Tamanho com nenhum elemento: 0 = " << circular->size() << endl;
            cout << "Vazio: true = " << circular->empty() << endl;


            circular->push_front(*marketBox);

            cout << "Tamanho com um elemento: 1 = " << circular->size() << endl;
            cout << "Vazio: false = " << circular->empty() << endl;

            circular->pop_front();

            cout << "Tamanho com um elemento: 0 = " << circular->size() << endl;
            cout << "Vazio: true = " << circular->empty() << endl;

            cout << "============Test4=============   Teste Cliente" << endl;

            Time* tempoChegada = new Time(10u);
            Time* tempoSaida = new Time(17u);

            Client* cliente = new Client(tempoChegada);

            cliente->set_exit_time(tempoSaida);
            cout << "instanciou cliente" << endl;

            cout << "Tempo chegada: 10 = " << cliente->get_arrival_time()->get_time_in_seconds() << endl;
            cout << "Tempo saida: 17 = " << cliente->get_exit_time()->get_time_in_seconds() << endl;
            cout << "Tempo que ficou na fila: 7 = " << cliente->get_average_time()->get_time_in_seconds() << endl;

            string tipoPagamento("");

            if (cliente->get_pay_type() == PayType::card) {
                tipoPagamento = "cartão";
            } else {
                tipoPagamento = "Dinheiro";
            }

            cout << "Tipo de pagamento: random = " << tipoPagamento << endl;

            string tipoFila("");

            if (cliente->get_queue_type() == QueueType::less_size) {
                tipoFila = "menorTamanho";
            } else {
                tipoFila = "menosProdutos";
            }

            cout << "Tipo de fila: random = " << tipoFila << endl;

            cout << "Numero de compras: random = " << cliente->get_total_purchases() << endl;

            cout << "Valor total: random = " << cliente->get_total_value() << endl;

            cout << "============Test5=============   Teste numero Produtos na fila" << endl;

            LinkedQueue* lqueue = new LinkedQueue();
            lqueue->enqueue(cliente);

            cout << "Numero de produtos na fila: " << cliente->get_total_purchases() << " = " << lqueue->num_products() << endl;
            lqueue->enqueue(cliente);

            cout << "Numero de produtos na fila: " << cliente->get_total_purchases()*2 << " = " << lqueue->num_products() << endl;
            lqueue->dequeue();

            cout << "Numero de produtos na fila: " << cliente->get_total_purchases() << " = " << lqueue->num_products() << endl;


        }
    private:
};

#endif // TESTLUIZ_H
