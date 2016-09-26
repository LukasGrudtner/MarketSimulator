#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>

using namespace std;

template <typename T>

class circular_list
{
 public:
        CircularList();

        void clear();

        void push_back(const T& data);
        void push_front(const T& data);
        void insert(const T& data, std::size_t index);
        void insert_sorted(const T& data);

        T& at(std::size_t index);
        const T& at(std::size_t index) const;

        T pop(std::size_t index);
        T pop_back();
        T pop_front();
        void remove(const T& data);

        bool empty() const;
        bool contains(const T& data) const;
        std::size_t find(const T& data) const;

        std::size_t size() const;
        std::size_t smaller_queue() const;
        std::size_t smaller_amount_of_products() const;

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
