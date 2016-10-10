#ifndef MARKET_H
#define MARKET_H
#include <string>

#include "performance.h"
#include "clock.h"
#include "circular_list.h"
#include "market_box.h"
#include "client.h"
#include "linked_queue.h"

//! Classe Market para simulacao do projeto.
class Market
{
    public:
        /*!
        *   Construtor.
        *   \param nome do mercado.
        *   \param tempo de simulacao em horas.
        *   \param tempo medio para chegada de um novo cliente.
        */
        Market(std::string market_name,unsigned int time_of_simulation, unsigned int average_time_of_arrival_of_clients, unsigned int max_clients_in_queue);

        /*!
        *   Destrutor.
        */
        virtual ~Market();

        /*!
        *   Metodo Usado para se adicionar novos caixas ao supermercado.
        */
        void add_box(std::string nome, unsigned int performance, double salary);

        /*!
        *   Com os dados recebidos realiza a simulacao de funcionamento.
        */
        void start_simulation();

        /*!
        *   \return faturamento total.
        */
        double get_total_billing();

        /*!
        *   \return faturamento medio por caixa  .
        */
        double get_average_billing();

        /*!
        *   \param posicao de caixa q se deseja saber a informacao.
        *   \return faturamento medio de caixa em especifico.
        */
        double get_average_billing(unsigned int index);

        /*!
        *   \param posicao de caixa q se deseja saber a informacao.
        *   \return faturamento total de caixa em especifico.
        */
        double get_billing(unsigned int index);

        /*!
        *   \return lucro total.
        */
        double get_total_profit();

        /*!
        *   \param posicao de caixa q se deseja saber a informacao.
        *   \return lucro provido por determinado caixa.
        */
        double get_profit(unsigned int index);

        /*!
        *   \return tempo medio que um cliente passa na fila ao chegar nesse mercado.
        */
        double get_average_queue_time();

        /*!
        *   \return numero de clientes q desistiram.
        */
        int get_dropped_out();

        /*!
        *   \return faturamento que deixou de ser realizado.
        */
        double get_billing_lost();// faturamento q deixou de ser realizado == variavel q contem o valor de todos q deixaram a fila

        /*!
        *   \return nome do mercado.
        */
        std::string get_maket_name() {
            return market_name_;
        }

        /*!
        *   \param posicao de caixa q se deseja saber a informacao.
        *   \return identificador do caixa.
        */
        std::string get_identifier(unsigned int index) {
            return box_list->at(index)->get_identifier();
        }

    private:
        CircularList* box_list;
        Clock* clock;
        unsigned int clients_dropped_out;
        unsigned int max_clients_in_queue_;
        double billing_lost;
        std::string market_name_;
        Time* time_of_simulation_;
        Time* average_time_of_arrival_of_clients_;

        Performance* bad_box_perform = new Performance(60u, 4);
        Performance* medium_box_perform = new Performance(25u, 2);
        Performance* good_box_perform = new Performance(10u, 1);

};

#endif // MARKET_H
