#ifndef CLIENT_H
#define CLIENT_H

#include "time_p.h"

        /*!
        *   Tipos de pagamento possiveis.
        */
        enum class PayType { cash, card };

        /*!
        *   Tipos de fila que o cliente pode escolher.
        */
        enum class QueueType { less_Products, less_size };

//! Classe Client para clientes.
class Client
{
    public:

        /*!
        *   Construtor.
        */
        Client();

        /*!
        *   Construtor.
        *   \param tempo de chegada.
        *   \param tempo de saida.
        */
        Client(Time* arrival_time);

        /*!
        *   Destrutor.
        */
        virtual ~Client();

        /*!
        *   Define o tempo que o usuario deixara o mercado.
        */
        void set_exit_time(Time* arrival_time);

        /*!
        *   \return tempo de chegada na fila.
        */
        Time* get_arrival_time();

        /*!
        *   \return tempo de saida na fila.
        */
        Time* get_exit_time();

        /*!
        *   \return tempo que o cliente passou/vai passar na fila.
        */
        Time* get_average_time();

        /*!
        *   \return tipo de pagamento.
        */
        PayType get_pay_type();

        /*!
        *   \return tipo de fila.
        */
        QueueType get_queue_type();

        /*!
        *   \return total de compras.
        */
        unsigned int get_total_purchases();

        /*!
        *   \return valor total.
        */
        double get_total_value();

    private:

        /*!
        *   Define o tipo de fila que o cliente tem preferencia.
        */
        void set_queue_type();

        /*!
        *   Define o metodo de pagamento com 80% de chances de ser cartao.
        */
        void set_pay_type();

        /*!
        *   Define o valor total das compras.
        */
        void set_total_purchases_value();

        PayType pay_type_;              /*!< Tipo de pagamento do cliente. */
        QueueType queue_type_;          /*!< Tipo de fila que o cliente tem preferencia. */
        unsigned int total_purchases_;  /*!< Numero de produtos. */
        double total_purchases_value_;  /*!< Valor de todos os produtos. */
        Time* arrival_time_;            /*!< Tempo no qual o cliente entrou na fila. */
        Time* exit_time_;               /*!< Tempo no qual o cliente saira da fila. */

};

#endif // CLIENT_H
