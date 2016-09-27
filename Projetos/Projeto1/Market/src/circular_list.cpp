#include "circular_list.h"


template<typename T>
circular_list<T>::circular_list()
{
    size_ = 0u;
    head = new Node(0u);
}

template<typename T>
circular_list<T>::~circular_list()
{
    clear();
    delete head;
}

template<typename T>
void circular_list<T>::clear()
{
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
void circular_list<T>::push_back(const T& data)
{
    insert(data, size());
}

template<typename T>
void circular_list<T>::push_front(const T& data)
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

template<typename T>
void circular_list<T>::insert(const T& data, std::size_t index)
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

template<typename T>
void circular_list<T>::insert_sorted(const T& data)
{
    Node *current;
    int position;

    if (empty()) {
        push_front(data);
    } else {
        current = head->next();
        position = 0;
        while (current->next() != NULL  && data > current->data()) {
            current = current->next();
            position++;
        }

        if (data > current->data()) {
            insert(data, position+1);
        } else {
            insert(data, position);
        }
    }
}

template<typename T>
const T& circular_list<T>::at(std::size_t index) const
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

template<typename T>
T circular_list<T>::pop(std::size_t index)
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

template<typename T>
T circular_list<T>::pop_back()
{
    if (empty()) {
        throw std::out_of_range("Empty_list_error");
    } else {
        return pop(size()-1);
    }
}

template<typename T>
T circular_list<T>::pop_front()
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

template<typename T>
void circular_list<T>::remove(const T& data)
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

template<typename T>
bool circular_list<T>::empty() const
{
    return size_ == 0;
}

template<typename T>
bool circular_list<T>::contains(const T& data) const
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

template<typename T>
std::size_t circular_list<T>::find(const T& data) const
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

template<typename T>
std::size_t circular_list<T>::size() const
{
    return size_;
}
