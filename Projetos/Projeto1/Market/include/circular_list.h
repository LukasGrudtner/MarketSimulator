#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>

using namespace std;

template<typename T>

//! Classe CircularList para uma Lista.
/*!
*   Na classe CircularList, e implementado o funcionamento de uma lista
*   atraves de Nodes que referenciam o proximo valor na lista e o dado na mesma.
*/
class circular_list
{
 public:
        /*!
        *   Construtor.
        */
        circular_list();

        /*!
        *   Destrutor.
        *   \sa clear()
        */
        ~circular_list();

        /*!
        *   Limpa a lista.
        *   \sa empty(), pop_front()
        */
        void clear();

        /*!
        *   Adiciona fila no final.
        *   \param data dado a ser adicionado.
        *   \sa insert()
        */
        void push_back(const T& data);

        /*!
        *  Adiciona fila no começo.
        *   \param data dado a ser adicionado.
        *   \sa empty()
        */
        void push_front(const T& data);

        /*!
        *   Insere dado em uma posicao n.
        *   \param data dado a ser adicionado.
        *   \param index posicao q sera adicionado.
        *   \sa push_front
        */
        void insert(const T& data, std::size_t index);

        /*!
        *   Insere dado de forma ordenada.
        *   \param data dado a ser adicionado
        *   \sa insert(), push_front()
        */
        void insert_sorted(const T& data);

        /*!
        *   Retorna dado.
        *   \param index posicao do dado a ser retornado.
        *   \return dado.
        */
        const T& at(std::size_t index) const;

        /*!
        *   Retira e retorna dado.
        *   \param posicao do dado a ser retirado.
        *   \return dado retirado.
        *   \sa pop_front()
        */
        T pop(std::size_t index);

        /*!
        *   Retira e retorna dado do final.
        *   \return dado retirado.
        *   \sa pop()
        */
        T pop_back();

        /*!
        *   Retira e retorna dado do inicio.
        *   \return dado retirado.
        */
        T pop_front();

        /*!
        *   Remove dado da lista.
        *   \param data dado a ser removido.
        */
        void remove(const T& data);

        /*!
        *   Retorna true se a lista estiver vazia.
        *   \return uma variavel booleana.
        */
        bool empty() const;

        /*!
        *   Retorna true se o dado recebido esta contido na lista.
        *   \param data dado a ser verificado.
        *   \return uma variavel booleana.
        */
        bool contains(const T& data) const

        /*!
        *   Retorna posicao de uma variavel.
        *   \param data variavel a ser verificada.
        *   \return um inteiro correspondente a posicao.
        */;
        std::size_t find(const T& data) const;

        /*!
        *   Retorna a quantidade de elementos na lista.
        */
        std::size_t size() const;

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
        explicit Node(const T& data):
            data_{data}
        {}

//! Construtor.
/*!
*   Construtor que referencia o dado a ser guardado e o proximo Node.
*   \param data dado que sera armazenado.
*   \param next ponteiro para o proximo Node.
*/
        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

/*!
*   Retorna o dado que esta salvo.
*   \return um T.
*/
        T& data() {
            return data_;
        }

/*!
*   Retorna o dado que esta salvo.
*   \return um T.
*/
        const T& data() const {
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
        T data_;                /*!< Dado contido. */
        Node* next_{nullptr};   /*!< Proximo Node. */
};

        Node* head;
        std::size_t size_;
};

#endif // CIRCULAR_LIST_H
