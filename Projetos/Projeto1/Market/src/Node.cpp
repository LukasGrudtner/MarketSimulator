#include "Node.h"

T data_;
Node* next_{nullptr};

Node::Node(const T& data)
{
    data_ = data;
}

Node(const T& data Node* next)
{
    data_ = data;
    next_ = next;
}

T& data()
{
    return data_;
}

const T& data() const
{
    return data_;
}

Node* next()
{
    return next_;
}

const Node* next() const
{
    return next_;
}

void next(Node* node)
{
    next_ = node;
}
