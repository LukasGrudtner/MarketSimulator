#include "linked_queue.h"

LinkedQueue::LinkedQueue()
{
    head = new Node();
    tail = NULL;
    num_people_ = 0u;
    num_products_ = 0u;
}

LinkedQueue::~LinkedQueue()
{
    clear();
    delete head;
}

void LinkedQueue::clear()
{
    while (!empty()) {
        dequeue();
    }
}

void LinkedQueue::enqueue(Client* data)
{
    Node* new_node = new Node(data);

    if (empty()) {
        head->next(new_node);
    } else {
        tail->next(new_node);
    }
    tail = new_node;
    num_people_++;
    num_products_ += data->get_total_purchases();
}

Client* LinkedQueue::dequeue()
{
    Node* to_eliminate;
    Client* to_back;

    if (empty()) {
        throw std::out_of_range("Empty_queue_Exception");
    } else {
        to_eliminate = head->next();
        head->next(to_eliminate->next());
        to_back = to_eliminate->data();
        num_people_--;
        num_products_ -= to_back->get_total_purchases();
        delete to_eliminate;
    }
    return to_back;
}

Client* LinkedQueue::front() const
{
    if (empty()) {
        throw std::out_of_range("Empty_queue_Exception");
    }
    return head->next()->data();
}

Client* LinkedQueue::back() const
{
    if (empty()) {
        throw std::out_of_range("Empty_queue_Exception");
    }
    return tail->data();
}

bool LinkedQueue::empty() const
{
    return (num_people_ == 0);
}

size_t LinkedQueue::num_people()
{
    return num_people_;
}

size_t LinkedQueue::num_products()
{
    return num_products_;
}
