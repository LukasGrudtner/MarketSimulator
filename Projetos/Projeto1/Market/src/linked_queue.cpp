#include "linked_queue.h"

template<typename T>
LinkedQueue<T>::LinkedQueue()
{
    head = new Node(0u);
    tail = NULL;
    num_people = 0u;
    num_products = 0u;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue()
{
    clear();
    delete head;
}

template<typename T>
void LinkedQueue<T>::clear()
{
    while (!empty()) {
        dequeue();
    }
}

template<typename T>
void LinkedQueue<T>::enqueue(const T& data)
{
    Node* novo = new Node(data);
    if (novo == NULL) {
        throw std::out_of_range("Erro");
    } else {
        if (empty()) {
            head->next(novo);
        } else {
            tail->next(novo);
        }
        tail = novo;
        num_people++;
    }
}

template<typename T>
T LinkedQueue<T>::dequeue()
{
    Node* eliminar;
    T volta;
    if (empty()) {
        throw std::out_of_range("Erro Fila Vazia!");
    } else {
        eliminar = head->next();
        head->next(eliminar->next());
        volta = eliminar->data();
        num_people--;
        delete eliminar;
    }
    return volta;
}

template<typename T>
T& LinkedQueue<T>::front() const
{
    if (empty()) {
        throw std::out_of_range("Erro Fila Vazia!");
    }
    return head->next()->data();
}

template<typename T>
T& LinkedQueue<T>::back() const
{
    if (empty()) {
        throw std::out_of_range("Erro Fila Vazia!");
    }
    return tail->data();
}

template<typename T>
bool LinkedQueue<T>::empty() const
{
    return (num_people == 0);
}

template<typename T>
size_t LinkedQueue<T>::num_people_proc()
{
    return num_people;
}

template<typename T>
size_t LinkedQueue<T>::num_products_proc()
{
    return num_products;
}
