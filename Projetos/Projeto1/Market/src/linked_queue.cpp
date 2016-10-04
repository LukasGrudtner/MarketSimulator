#include "linked_queue.h"

//template<typename T>
LinkedQueue::LinkedQueue()
{
    head = new Node();
    tail = NULL;
    num_people = 0u;
    num_products = 0u;
}

//template<typename T>
LinkedQueue::~LinkedQueue()
{
    clear();
    delete head;
}

//template<typename T>
void LinkedQueue::clear()
{
    while (!empty()) {
        dequeue();
    }
}

//template<typename T>
void LinkedQueue::enqueue(const Client& data)
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

//template<typename T>
Client LinkedQueue::dequeue()
{
    Node* eliminar;
    Client volta;

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

//template<typename T>
Client& LinkedQueue::front() const
{
    if (empty()) {
        throw std::out_of_range("Erro Fila Vazia!");
    }
    return head->next()->data();
}

//template<typename T>
Client& LinkedQueue::back() const
{
    if (empty()) {
        throw std::out_of_range("Erro Fila Vazia!");
    }
    return tail->data();
}

//template<typename T>
bool LinkedQueue::empty() const
{
    return (num_people == 0);
}

//template<typename T>
size_t LinkedQueue::num_people_proc()
{
    return num_people;
}

//template<typename T>
size_t LinkedQueue::num_products_proc()
{
    return num_products;
}
