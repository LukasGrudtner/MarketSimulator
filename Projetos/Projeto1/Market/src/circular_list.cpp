#include "circular_list.h"

circular_list::circular_list()
{
    size_ = 0u;
    smaller_queue = 0u;
    smaller_amount_of_products = 0u;
    head = new Node(0u);
}

circular_list::~circular_list()
{
    clear();
    smaller_queue = 0u;
    smaller_amount_of_products = 0u;
    delete head;
}

void circular_list::clear()
{
    while (!empty()) {
        pop_front();
    }
}

void circular_list::push_back(const T& data)
{
    insert(data, size());
}

void circular_list::push_front(const)
{
    Node* new_Node = new Node(data);

    if (new_Node == NULL) {
        throw std::out_of_range("Full_list_error");
    } else {
        if (!empty()) {
            new_Node->next(head->next());
        }
        head->next(new_Node);
        size_++;
    }
}

void circular_list::insert(const T& data, std::size_t index)
{
    Node *new_Node;
    Node *previous;

    if (index > size() || index < 0) {
        throw std::out_of_range("Invalid_position");
    } else {
        if (index == 0) {
            push_front(data);
        } else {
            new_Node = new Node(data);
            if (new_Node == NULL) {
                throw std::out_of_range("Full_list");
            } else {
                previous = head->next();
                for (int i = 0; i < index -1; i++) {
                    previous = previous->next();
                }
                if (index != size()) {
                    new_Node->next(previous->next());
                } else {
                    new_Node->next(head);
                }
                previous->next(new_Node);
                size_++;
            }
        }
    }
}

void circular_list::insert_sorted(const T& data)
{
    Node *current;
    int posicao;

    if (empty()) {
        push_front(data);
    } else {
        current = head->next();
        posicao = 0;
        while (current->next() != NULL  && data > current->data()) {
            current = current->next();
            posicao++;
        }

        if (data > current->data()) {
            insert(data, posicao+1);
        } else {
            insert(data, posicao);
        }
    }
}

const T& circular_list::at(std::size_t index) const
{
    Node *data_ = head->next();

    if (empty()) {
        throw std::out_of_range("Full_list");
    } else {
        if (index > size() || index < 0) {
            throw std::out_of_range("Invalid_position");
        } else {
            for (int i = 0; i < index; i++) {
                data_ = data_->next();
            }
            return data_->data();
        }
    }
}

T circular_list::pop(std::size_t index)
{
    Node* previous;
    Node* to_eliminate;
    T to_back;

    if (index > size()-1 || index < 0) {
        throw std::out_of_range("Invalid_position");
    } else {
        if (index == 0) {
            return pop_front();
        } else {
            previous = head->next();
            for (int i = 0; i < index -1; i++) {
                previous = previous->next();
            }
            to_eliminate = previous->next();
            to_back = to_eliminate->data();
            previous->next(to_eliminate->next());
            size_--;
            delete to_eliminate;

            return to_back;
        }
    }
}

T circular_list::pop_back()
{
    if (empty()) {
        throw std::out_of_range("Empty_list_error");
    } else {
        return pop(size()-1);
    }
}

T circular_list::pop_front()
{
    Node *quit;
    T to_back;

    if (empty()) {
        throw std::out_of_range("Empty_list_error");
    } else {
        quit = head->next();
        to_back = quit->data();
        head->next(quit->next());
        size_--;
        delete quit;

        return to_back;
    }
}

void circular_list::remove()
{
    Node* previous = head;
    Node* current = head->next();

    while (current->data() != data) {
        previous = previous->next();
        current = current->next();
    }
    previous->next(current->next());
    delete current;
    size_--;
}

bool circular_list::empty()
{
    return size_ == 0;
}

bool circular_list::contains(const T& data) const
{
    auto *data_ = head;

    for (int i = 0; i < size(); i++) {
        data_ = data_->next();
        if (data == data_->data()) {
            return true;
        }
    }
    return false;
}

std::size_t circular_list::find(const T& data) const
{
    auto *data_ = head;

    for (int i = 0; i < size(); i++) {
        data_ = data_->next();
        if (data == data_->data()) {
            return i;
        }
    }
    return size();
}

std::size_t circular_list::size() const
{
    return size_;
}

std::size_t circular_list::smaller_queue() const
{
    return smaller_queue;
}

std::size_t circular_list::smaller_amount_of_products() const
{
    return smaller_amount_of_products;
}
