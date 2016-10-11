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
        double get_total_billing() {
            auto total_billing = 0;
            for (auto i = 0; i < box_list->size() ; i++) {
                total_billing += box_list->at(i)->get_total_billing();
            }

            return total_billing;
        }

        /*!
        *   \return faturamento medio por caixa  .
        */
        double get_average_billing() {
            auto average_billing = 0;
            for (auto i = 0; i < box_list->size() ; i++) {
                average_billing += box_list->at(i)->get_average_billing();
            }

            return average_billing/box_list->size();
        }

        /*!
        *   \param posicao de caixa q se deseja saber a informacao.
        *   \return faturamento medio de caixa em especifico.
        */
        double get_average_billing(unsigned int index) {
            return box_list->at(index)->get_average_billing();
        }

        /*!
        *   \param posicao de caixa q se deseja saber a informacao.
        *   \return faturamento total de caixa em especifico.
        */
        double get_billing(unsigned int index) {
            return box_list->at(index)->get_total_billing();
        }

        /*!
        *   \return lucro total.
        */
        double get_total_profit() {
            auto total_profit = 0;
            for (auto i = 0; i < box_list->size() ; i++) {
                total_profit += box_list->at(i)->get_profit();
            }

            return total_profit;
        }

        /*!
        *   \param posicao de caixa q se deseja saber a informacao.
        *   \return lucro provido por determinado caixa.
        */
        double get_profit(unsigned int index) {
            return box_list->at(index)->get_profit();
        }

        /*!
        *   \return tempo medio que um cliente passa na fila ao chegar nesse mercado.
        */
        double get_average_queue_time_in_seconds() {
            auto total_time = 0;
            for (auto i = 0; i < box_list->size() ; i++) {
                total_time += box_list->at(i)->get_average_service_time()->get_time_in_seconds();
            }

            return total_time/box_list->size();
        }

        /*!
        *   \return numero de clientes q desistiram.
        */
        int get_dropped_out() {
            return clients_dropped_out;
        }

        /*!
        *   \return faturamento que deixou de ser realizado.
        */
        double get_billing_lost() {
            return billing_lost;
        }

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
        /*!
        *   \return true se todas as filas estiverem cheias.
        */
        bool full_market();

        /*!
        *   Reponsavel por adicionar o cliente na fila de menor tamanho.
        *   \param cliente a ser adicionado em uma das filas.
        */
        void add_client_less_size_queue(Client* client);

        /*!
        *   Reponsavel por adicionar o cliente na fila com menos produtos.
        *   \param cliente a ser adicionado em uma das filas.
        */
        void add_client_less_products_queue(Client* client);

        /*!
        *   Define tempo de chegada do proximo cliente.
        */
        void increase_time_next_client() {
            time_of_next_client->add_seconds(average_time_of_arrival_of_clients_->get_time_in_seconds());
        }

        void simulate_box();

        CircularList* box_list;                                     /*!< Fila com caixas do mercado. */
        Clock* clock;                                               /*!< Relogio do mercado. */
        unsigned int clients_dropped_out;                           /*!< Numero de clientes q deixaram de comprar. */
        unsigned int max_clients_in_queue_;                         /*!< Maximo de clientes nas filas. */
        double billing_lost;                                        /*!< Faturamento perdido. */
        std::string market_name_;                                   /*!< Nome do mercado. */
        Time* time_of_simulation_;                                  /*!< Tempo de simulacao. */
        Time* average_time_of_arrival_of_clients_;                  /*!< Tempo de chegada de um novo cliente. */
        Time* time_of_next_client;                                  /*!< Tempo no qual o proximo cliente chegara. */
        bool reserve_box;                                           /*!< Se caixa reserva esta disponivel. */

        Performance* bad_box_perform = new Performance(60u, 4);     /*!< Performance ruim para caixas. */
        Performance* medium_box_perform = new Performance(25u, 2);  /*!< Performance media para caixas. */
        Performance* good_box_perform = new Performance(10u, 1);    /*!< Performance boa para caixas. */

};

#endif // MARKET_H
