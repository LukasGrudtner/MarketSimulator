/*!
 *  \author Luiz Felipe Ribeiro Baroncello
 *  \author Lukas Derner Grüdtner
 *  \version 1.0
 *  \copyright General Public License version 2
 *
 */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <cstdint>
#include <stdexcept>

#include "client.h"

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
        void enqueue(const Client& data);

        /*!
        *   Retorna o priemiro cliente da fila e o retira da mesma.
        *   \return cliente
        */
        Client dequeue();

        /*!
        *   Retorna o priemiro cliente da fila.
        *   \return cliente
        */
        Client front() const;

        /*!
        *   Retorna o ultimo cliente da fila.
        *   \return cliente
        */
        Client back() const;

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

    private:
//! Classe Node para referenciar dado e proximo elemento na fila.
/*!
*   Na classe Node sao implementados os metodos basicos para a referencia de um dado T e ao proximo Node.
*/
class Node {
 public:
//! Construtor.
/*!
*   Construtor que referencia o dado a ser guardado atraves de parametro.
*   \param data dado que sera armazenado.
*/
        Node(const Client& data):
            data_{data}
        {}
/*!
*   Construtor vazio.
*/
        Node()
        {}

//! Construtor.
/*!
*   Construtor que referencia o dado a ser guardado e o proximo Node.
*   \param data dado que sera armazenado.
*   \param next ponteiro para o proximo Node.
*/
        Node(const Client& data, Node* next):
            data_{data},
            next_{next}
        {}

/*!
*   Retorna o dado que esta salvo.
*   \return um T.
*/
        Client& data() {
            return data_;
        }

/*!
*   Retorna o dado que esta salvo.
*   \return um T.
*/
        const Client& data() const {
            return data_;
        }


/*!
*   Retorna o proximo elemento.
*   \return um Node.
*/
        Node* next() {
            return next_;
        }

/*!
*   Retorna o proximo elemento.
*   \return um Node.
*/
        const Node* next() const {
            return next_;
        }

/*!
*   Recebe um ponteiro indicando qual sera o proximo Node.
*   \param node.
*/
        void next(Node* node) {
            next_ = node;
        }


         private:
            Client data_;          /*!< Declaração do dado, do tipo T. */
            Node* next_{nullptr}; /*!< Declaração do próximo Node. */
        };

        Node* head;                 /*!< Cabeça da fila. */
        Node* tail;                 /*!< Final da fila. */
        unsigned int num_people_;     /*!< Numero de pessoas na fila. */
        unsigned int num_products_;   /*!< Numero de produtos na fila. */
};

#endif // LINKEDQUEUE_H
