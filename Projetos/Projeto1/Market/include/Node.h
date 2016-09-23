#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        explicit Node(const T& data);
        Node(const T& data, Node* next);
        T& data();
        const T& data();
        Node* next();
        const Node* next() const;
        void next(Node* node);

    protected:

    private:
        T data_;
        Node* next_{nullptr};
};

#endif // NODE_H
