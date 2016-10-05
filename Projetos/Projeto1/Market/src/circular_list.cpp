#include "circular_list.h"

CircularList::CircularList()
{
    size_ = 0u;
    head = new Node();
}

CircularList::~CircularList()
{
    clear();
    delete head;
}

void CircularList::clear()
{
    while (!empty()) {
        pop_front();
    }
}

void CircularList::push_back(const MarketBox& data)
{
    insert(data, size());
}

void CircularList::push_front(const MarketBox& data)
{
    Node* new_Node = new Node(data);

    if (!empty()) {
        new_Node->next(head->next());
    }
    head->next(new_Node);
    size_++;
}

void CircularList::insert(const MarketBox& data, std::size_t index)
{
    Node *new_Node;
    Node *previous;

    if (index > size() || index < 0) {
        throw std::out_of_range("Invalid_position_Exception");
    } else {
        if (index == 0) {
            push_front(data);
        } else {
            new_Node = new Node(data);
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

const MarketBox& CircularList::at(std::size_t index) const
{
    Node *data_ = head->next();

    if (empty()) {
        throw std::out_of_range("Full_list_Exception");
    } else {
        if (index > size() || index < 0) {
            throw std::out_of_range("Invalid_position_Exception");
        } else {
            for (int i = 0; i < index; i++) {
                data_ = data_->next();
            }
            return data_->data();
        }
    }
}

MarketBox CircularList::pop(std::size_t index)
{
    Node* previous;
    Node* to_eliminate;
    MarketBox to_back;

    if (index > size()-1 || index < 0) {
        throw std::out_of_range("Invalid_position_Exception");
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

MarketBox CircularList::pop_back()
{
    if (empty()) {
        throw std::out_of_range("Empty_list_Exception");
    } else {
        return pop(size()-1);
    }
}

MarketBox CircularList::pop_front()
{
    Node *quit;
    MarketBox to_back;

    if (empty()) {
        throw std::out_of_range("Empty_list_Exception");
    } else {
        quit = head->next();
        to_back = quit->data();
        head->next(quit->next());
        size_--;
        delete quit;

        return to_back;
    }
}

bool CircularList::empty() const
{
    return size_ == 0;
}

std::size_t CircularList::size() const
{
    return size_;
}
