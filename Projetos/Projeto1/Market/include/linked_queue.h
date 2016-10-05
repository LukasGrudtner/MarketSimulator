#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "client.h"
#include <cstdint>
#include <stdexcept>

//! Classe LinkedQueue
/*! A classe implementa a estrutura de fila encadeada, onde o tamanho é dinâmico, sendo no maximo 10,
*   e cada elemento (ou node) possui um dado e um ponteiro para o próximo elemento.
*/
class LinkedQueue
{
    public:
        /*!
        *   Construtor.
        */
        LinkedQueue();

        /*!
        *   Destrutor.
        *   \sa clear()
        */
        virtual ~LinkedQueue();

        /*!
        *   Limpa a lista.
        *   \sa empty(), dequeue()
        */
        void clear();

        /*!
        *   Adiciona um novo cliente no fim da fila.
        *   \param data cliente a ser adicionado
        */
        void enqueue(Client* data);

        /*!
        *   Retorna o priemiro cliente da fila e o retira da mesma.
        *   \return cliente
        */
        Client* dequeue();

        /*!
        *   Retorna o priemiro cliente da fila.
        *   \return cliente
        */
        Client* front() const;

        /*!
        *   Retorna o ultimo cliente da fila.
        *   \return cliente
        */
        Client* back() const;

        /*!
        *   Retorna true se a fila estiver vazia.
        *   \return uma variavel booleana.
        */
        bool empty() const;

        /*!
        *   Retorna o numero de pessoas na fila.
        *   \return quantidade de pessoas.
        */
        std::size_t num_people();

        /*!
        *   Retorna o numero de produtos na fila.
        *   \return quantidade de produtos.
        */
        std::size_t num_products();

    protected:

    private:

        //! Classe Node
        /*! A classe implementa o elemento da lista encadeada,
        onde cada node possui um atributo de dado e um ponteiro para o próximo elemento. */
        class Node {  // Elemento
        public:
            Node()
            {}

            //! Construtor
            /*! Método construtor da classe Node com um parâmetro de dados.
                /param data dado a ser inserido no Node.
            */
            explicit Node(Client* data):
                data_{data}
            {}

            //! Construtor
            /*! Método construtor da classe Node com dois parâmetros.
                /param data dado a ser inserido no Node.
                /param next ponteiro para o próximo Node.
            */
            Node(Client* data, Node* next):
                data_{data},
                next_{next}
            {}
            //! Data
            /*! Método getter de um Node.
                /return o dado do elemento.
            */
            Client* data() {
                return data_;
            }
            //! Data Const
            /*! Método getter de um Node, onde o dado retornado não será alterado.
                /return o dado do elemento.
            */
            const Client* data() const {
                return data_;
            }

            //! Next
            /*! Método getter de um Node.
                /return o ponteiro para o próximo elemento.
            */
            Node* next() {
                return next_;
            }

            //! Next
            /*! Método getter de um Node, onde o ponteiro retornado não será alterado.
                /return o ponteiro para o próximo elemento.
            */
            const Node* next() const {
                return next_;
            }
            //! Next
            /*! Método setter de um Node.
                /param um ponteiro, que será o indicador do próximo elemento.
            */
            void next(Node* node) {
                next_ = node;
            }

         private:
            Client* data_;          /*!< Declaração do dado, do tipo T. */
            Node* next_{nullptr}; /*!< Declaração do próximo Node. */
        };

        Node* head;                 /*!< Cabeça da fila. */
        Node* tail;                 /*!< Final da fila. */
        unsigned int num_people_;     /*!< Numero de pessoas na fila. */
        unsigned int num_products_;   /*!< Numero de produtos na fila. */
};

#endif // LINKEDQUEUE_H
