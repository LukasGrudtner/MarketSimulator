#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <cstdint>
#include <stdexcept>

template<typename T>

//! Classe LinkedQueue
/*! A classe implementa a estrutura de fila encadeada, onde o tamanho é dinâmico,
e cada elemento (ou node) possui um dado e um ponteiro para o próximo elemento. */
class LinkedQueue
{
    public:
        //! Construtor da Classe
        /*! Método construtor padrão da classe LinkedQueue. */
        LinkedQueue();

        //! Destrutor
        virtual ~LinkedQueue();

        //! Clear
        /*! Remove todos os elementos da fila encadeada. */
        void clear();

        //! Enqueue
        /*! Insere elementos no fim da fila encadeada.
            \param data um dado para ser inserido na fila.
        */
        void enqueue(const T& data);

        //! Dequeue
        /*! Remove elementos no início da fila encadeada; */
        T dequeue();

        //! Front
        /*! Retorna o elemento no início da fila.
            \return um dado do tipo T guardado no elemento da frente.
        */
        T& front() const;

        //! Back
        /*! Retorna o elemento no final da fila.
            \return um dado do tipo T guardado no elemento do fim.
        */
        T& back() const;

        //! Empty
        /*! Verifica se a fila está vazia.
            /return um valor do tipo bool.
        */
        bool empty() const;

        //! NumPeopleProcedure
        /*! Retorna o número de pessoas na fila. */
        std::size_t num_people_proc();

        //! NumProductsProcedure
        /*! Retorna o número de produtos na fila. */
        std::size_t num_products_proc();

    protected:

    private:

        //! Classe Node
        /*! A classe implementa o elemento da lista encadeada,
        onde cada node possui um atributo de dado e um ponteiro para o próximo elemento. */
        class Node {  // Elemento
        public:
            //! Construtor
            /*! Método construtor da classe Node com um parâmetro de dados.
                /param data dado a ser inserido no Node.
            */
            explicit Node(const T& data):
                data_{data}
            {}

            //! Construtor
            /*! Método construtor da classe Node com dois parâmetros.
                /param data dado a ser inserido no Node.
                /param next ponteiro para o próximo Node.
            */
            Node(const T& data, Node* next):
                data_{data},
                next_{next}
            {}
            //! Data
            /*! Método getter de um Node.
                /return o dado do elemento.
            */
            T& data() {
                return data_;
            }
            //! Data Const
            /*! Método getter de um Node, onde o dado retornado não será alterado.
                /return o dado do elemento.
            */
            const T& data() const {
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
            T data_; /**< Declaração do dado, do tipo T. */
            Node* next_{nullptr}; /**< Declaração do próximo Node. */
        };

        Node* head;  // nodo-cabeça
        Node* tail;  // nodo-fim
        std::size_t num_people;
        std::size_t num_products;
};

#endif // LINKEDQUEUE_H
